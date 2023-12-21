/**
 * @file binary_read_structs.cpp
 * @author rohirto
 * @brief Demo of reading structs from binary files
 * @version 0.1
 * @date 2023-12-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <fstream>
#include <string>
#include <iostream>
#include <memory>

using namespace std;

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/records.bin"

//Strut of interest
struct PlayerRecord
{
    int age;
    int score;
    string name; //This is string class, note that
};
int main()
{
    PlayerRecord rec;
    rec.age = 11;
    rec.score = 200;
    rec.name = "John";

    //Open the file
    fstream a_file(FILE_PATH, ios::trunc | ios::binary | ios::in |
                                      ios::out);
    //Writing Part

    //Cast the datatypes into char* to cpnvert to binary
    a_file.write(reinterpret_cast<char *>(&rec.age), sizeof(rec.age));
    a_file.write(reinterpret_cast<char *>(&rec.score), sizeof(rec.score));

    //For string, append the string with length in the file
    int len = rec.name.length();
    a_file.write(reinterpret_cast<char *>(&len), sizeof(len));
    //Take the pointer and write its memory to the file
    a_file.write(rec.name.c_str(), rec.name.length() + 1);


    //Reading part

    PlayerRecord in_rec;

    a_file.seekg(0, ios::beg);

    //read int
    if (!a_file.read(reinterpret_cast<char *>(&in_rec.age), sizeof(
                                                                in_rec.age)))
    {
        cout << "Error reading from file" << endl;
        return 1;
    }

    //read int
    if (!a_file.read(reinterpret_cast<char *>(&in_rec.score), sizeof(
                                                                  in_rec.score)))
    {
        cout << "Error reading from file" << endl;
        return 1;
    }

    //read the len of the string in the file
    int str_len;
    if (!a_file.read(reinterpret_cast<char *>(&str_len), sizeof(
                                                             str_len)))
    {
        cout << "Error reading from file" << endl;
        return 1;
    }
    // perform a sanity check to ensure we don't try to allocate too much
    // memory!
    if (str_len > 0 && str_len < 10000)
    {
        char *p_str_buf = new char[str_len];
        if (!a_file.read(p_str_buf, str_len + 1)) // + 1 for null terminator
        {
            delete [] p_str_buf;
            cout << "Error reading from file" << endl;
            return 1;
        }
        // validate that the string is null-terminated
        if (p_str_buf[str_len] == 0)
        {
            in_rec.name = string(p_str_buf);
        }
        delete [] p_str_buf;
    }
    cout << in_rec.age << " " << in_rec.score << " " << in_rec.name << endl;

    a_file.close();
}