/**
 * @file client_screen.h
 * @author rohirto
 * @brief Header for client screen module
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>

class client_screen
{
    public:
    static client_screen& get_instance() {
        static client_screen instance;
        return instance;
    }

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

    private:
    client_screen() {} // Private constructor
    client_screen(const client_screen&) = delete;
    client_screen& operator=(const client_screen&) = delete;



};