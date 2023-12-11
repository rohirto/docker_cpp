/**
 * @file Debug.h
 * @author rohit S
 * @brief header File for Debug Class implementation
 * @version 0.1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023 Volansys Technologies
 * 
 */

#ifndef DEBUG_H_
#define DEBUG_H_


/**
 * @brief Debug class to print statements in colored format on terminal
 * @class Debug
 * 
 */
class Debug{
public:
/**
 * @brief Display a template in red color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_red(T str);


/**
 * @brief Display a template in Green color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_green(T str);


/**
 * @brief Display a template in yellow color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_yellow(T str);


/**
 * @brief Display a template in blue color on terminal
 * 
 * @tparam T 
 * @param str 
 */
template <typename T>
void display_blue(T str);


/**
 * @brief Display the decorator to make output more organized
 * 
 */
void display_decorator();

/**
 * @brief Construct a new Debug object
 * 
 */
Debug();

/**
 * @brief Destroy the Debug object
 * 
 */
~Debug();


};

#endif