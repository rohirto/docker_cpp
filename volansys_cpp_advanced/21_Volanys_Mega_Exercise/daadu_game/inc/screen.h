/**
 * @file screen.h
 * @author rohit S
 * @brief Includes the settings of screeen
 * @version 0.1
 * @date 2024-01-02
 *
 * @copyright Copyright (c) 2024 Volansys technologies
 *
 */

#ifndef _SCREEN_H_
#define _SCREEN_H_

#define WIDTH 16
#define HEIGHT 6

#include <iostream>

// Only one instance of this class should be there thus inherit it as virtual
/**
 * @brief Screen class
 * 
 */
class screen
{
    int width;
    int height;

public:
    screen() : width(WIDTH), height(HEIGHT) {} // Constructor
    /**
     * @brief Display a template in red color on terminal
     *
     * @tparam T
     * @param str
     */
    template <typename T>
    void display_red(T str)
    {
        std::cout << "\033[1;31m" << str << "\033[0m";
    }

    /**
     * @brief Display a template in Green color on terminal
     *
     * @tparam T
     * @param str
     */
    template <typename T>
    void display_green(T str)
    {
        std::cout << "\033[1;32m" << str << "\033[0m";
    }

    /**
     * @brief Display a template in yellow color on terminal
     *
     * @tparam T
     * @param str
     */
    template <typename T>
    void display_yellow(T str)
    {
        std::cout << "\033[1;33m" << str << "\033[0m";
    }

    /**
     * @brief Display a template in blue color on terminal
     *
     * @tparam T
     * @param str
     */
    template <typename T>
    void display_blue(T str)
    {
        std::cout << "\033[1;34m" << str << "\033[0m";
    }

    /**
     * @brief Display the decorator to make output more organized
     *
     */
    void display_decorator()
    {
        std::cout << "===============================";
    }

    void clear()
    {
        std::system("clear");
    }

    int getwidth(){return width;}
    int getheight(){return height;}

    char get_char();
    int get_int();
    std::string get_string();


    //Vitual funcs
    virtual int display_menu()=0;
    virtual char display_cowry_menu(std::string_view name)=0;
    virtual char display_daa_menu()=0;
    virtual char display_rules()=0;
};

#endif