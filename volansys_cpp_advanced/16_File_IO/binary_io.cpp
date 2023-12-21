/**
 * @file binary_io.cpp
 * @author rohirto
 * @brief Demo of Binary IO in Cpp
 * @version 0.1
 * @date 2023-12-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fstream>

using namespace std;

#define FILE_PATH "/workspaces/docker_cpp/volansys_cpp_advanced/16_File_IO/files/test.bin"

struct PlayerRecord
{
    int age;
    int score;
};


void read_fun()
{
     ifstream a_file(FILE_PATH, ios::binary);

    if (!a_file.is_open())
    {
        cout << "Could not open file!" << '\n';
        return ;
    }

    // Reading the array of integers
    int nums[10];
    a_file.read(reinterpret_cast<char *>(nums), sizeof(nums));

    cout << "Array of Integers: ";
    for (int i = 0; i < 10; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";

    // Reading the PlayerRecord
    PlayerRecord rec;
    a_file.read(reinterpret_cast<char *>(&rec), sizeof(rec));

    cout << "Player Record: Age=" << rec.age << ", Score=" << rec.score << "\n";

    a_file.close();
}

void write_fun()
{
    ofstream a_file( FILE_PATH, ios::binary );
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        nums[i] = i;
    }
    a_file.write(reinterpret_cast<char *>(nums), sizeof(nums));  // When you give it a pointer, it gives you the size of
                                                                //the pointer, not the size of the memory pointed to. The code above works because nums is declared as
                                                                //an array rather than a pointer, and sizeof knows the total size of the array.
    
    PlayerRecord rec;
    rec.age = 10;
    rec.score = 890;
    a_file.write( reinterpret_cast<char*>( & rec ), sizeof( rec ) );

    a_file.close();
}


int main()
{
     write_fun();
     read_fun();

    return 0;
   
}