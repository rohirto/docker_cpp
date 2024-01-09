/**
 * @file server_main.cpp
 * @author rohirto
 * @brief main.cpp of multiplayer dadu game
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <stdexcept>
#include "server_sockets.h"

int main()
{
    
    server s;
    
    s.server_listen();

    s.thread_joining();

    return 0;
}