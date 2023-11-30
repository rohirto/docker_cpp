/**
 * @file volansys_ex4.cpp
 * @author rohit S
 * @brief Challenge 5 of C++ Basic Course
 * @version 0.1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * A simple and very old method of sending secret messages is the substitution cipher.
 * You might have used this cipher with your friends when you were a kid.
 * Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
 * For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.
 *
 * Write a program thats ask a user to enter a secret message.
 *
 * Encrypt this message using the substitution cipher and display the encrypted message.
 * Then decryped the encrypted message back to the original message.
 *
 * You may use the 2 strings below for  your subsitition.
 * For example, to encrypt you can replace the character at position n in alphabet 
 * with the character at position n in key.
 *
 * To decrypt you can replace the character at position n in key
 * with the character at position n in alphabet.
 *
 * Have fun! And make the cipher stronger if you wish!
 * Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
 * forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
 * This could also be improved.
 *
 * Remember, the less code you write the less code you have to test!
 * Reuse existing functionality in libraries and in the std::string class!
 */

#include <iostream>
#include <bits/stdc++.h>
#include <string_view>

using namespace std;



/**
 * @brief Encrpyt message
 * 
 * @param alphabet string view, eng alphabets in correct order
 * @param key string view, cipher to be used to encrypt
 * @param input_msg string view, input message to be encrypted
 * @return string The encrypted string
 */
string encrypt_msg(string_view alphabet, string_view key, string_view input_msg)  //Using string view for ciphers for efficency
{
    string encrypted_msg {input_msg};
    

    for(char& ch: encrypted_msg)
    {
        size_t pos = alphabet.find(ch);
        if (pos != string::npos) 
        {
            ch = key[pos];
        }
    }
    return encrypted_msg;
}

/**
 * @brief Decrpyt message
 * 
 * @param alphabet string view, eng alphabets in correct order
 * @param key string view, cipher to be used to encrypt
 * @param input_msg string view, Encrypted message to be Decrypted
 * @return string The Decrypted string
 */
string decrypt_msg(string_view alphabet, string_view key, string_view input_msg)  //Using string view for ciphers for efficency
{
    string decrypted_msg {input_msg};
    

    for(char& ch: decrypted_msg)
    {
        size_t pos = key.find(ch);
        if (pos != string::npos) 
        {
            ch = alphabet[pos];
        }
    }
    return decrypted_msg;
}


int main() {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    //Ask user to input the message
    cout << "Enter the Secret Message : ";
    string input_msg {};
    getline(cin >> ws,input_msg);

    //Encrpt the message
    input_msg = encrypt_msg(alphabet,key, input_msg);

    //Display Encrypted message
    cout << "Encrypted Message: \n"; 
    cout << input_msg << endl;

    //Decrypt message
    input_msg = decrypt_msg(alphabet,key,input_msg);
    
    //Display Decrypted message
    cout << "Decrypted Message: \n"; 
    cout << input_msg << endl;
    
    cout << endl;
    return 0;
}