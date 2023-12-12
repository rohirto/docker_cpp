/**
 * @file Debug.h
 * @author rohit S
 * @brief header File for Debug Class implementation, Singleton design implementation
 * @version 0.1
 * @date 2023-12-11
 *
 * @copyright Copyright (c) 2023 Volansys Technologies
 *
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "Movie.h"
#include "Movies.h"

/**
 * @brief Debug class to print statements in colored format on terminal
 * @class Debug
 *
 */
class Debug
{

private:
    /**
     * @brief Construct a new Debug object
     *
     */
    Debug();

    // Private copy constructor to prevent copying
    Debug(const Debug &);

    // Private assignment operator to prevent assignment
    Debug &operator=(const Debug &);

public:
    /**
     * @brief Static method to get the instance of the singleton class
     * 
     * @return Debug& 
     */
    static Debug& getInstance() 
    {
        // Static instance of the singleton class
        static Debug instance;
        return instance;
    }


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
     * @brief Destroy the Debug object
     *
     */
    ~Debug();

};

#endif