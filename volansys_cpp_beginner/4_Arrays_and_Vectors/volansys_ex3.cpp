/**
 * @file volansys_ex3.cpp
 * @author rohit S
 * @brief Exercise 3 of Arrays and Vectors C++ Basic
 * @version 0.1
 * @date 2023-11-27
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 * @paragraph Exercise 3
 * Create a function that tweaks letters by one forward (+1) or backwards (-1) according to an array.
 *
 * Examples
 * tweakLetters("apple", {0, 1, -1, 0, -1}) ➞ "aqold"
 * // "p" + 1 => "q"; "p" - 1 => "o"; "e" - 1 => "d"
 * 
 * tweakLetters("many", {0, 0, 0, -1}) ➞ "manx"
 * 
 * tweakLetters("rhino", {1, 1, 1, 1, 1}) ➞ "sijop"
 * Notes
 * Don't worry about capital letters.
 * 
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Tweaks letters in a given string by the specified adjustments.
 *
 * @param str The input string.
 * @param adjustments The array of adjustments to be applied to each letter.
 * @return The tweaked string.
 */
std::string tweakLetters(const std::string& str, const std::vector<int>& adjustments) 
{
    std::string tweakedStr = str;

    // Iterate through each character and apply the adjustments
    for (size_t i = 0; i < str.size(); ++i) 
    {
        if (isalpha(str[i])) 
        {
            char baseChar = islower(str[i]) ? 'a' : 'A'; // Determine the base character for case 
            //Base char will be either a (ASCII Diff) or A (ASCII Diff)

            //Calculate the Offset: Takes the ASCII value of the current character in str, subtracts the ASCII value of the base character, and adds the adjustment specified in the adjustments array.
            //Apply Modulo Operation: % 26: Takes the result from step 2 and performs a modulo operation by 26. This ensures that the result is within the range of the 26 letters in the alphabet.
            //Adjust to Base Character Range: baseChar + ...: Adds the result from step 3 to the base character. This ensures that the adjusted value is within the ASCII range of the alphabet.
            // Convert to Char
            tweakedStr[i] = static_cast<char>(baseChar + (str[i] - baseChar + adjustments[i]) % 26);

        }
    }

    return tweakedStr;
}

int main() 
{
    // Examples
    std::cout << tweakLetters("apple", {0, 1, -1, 0, -1}) << std::endl; // Output: "aqold"
    std::cout << tweakLetters("many", {0, 0, 0, -1}) << std::endl; // Output: "manx"
    std::cout << tweakLetters("rhino", {1, 1, 1, 1, 1}) << std::endl; // Output: "sijop"

    return 0;
}
