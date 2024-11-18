/**
 * @file main.cpp
 * @author rohirto
 * @brief Main.cpp 
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "async_server.h"
#include "server_screen.h"

int main()
{
    server_screen::get_instance().display_yellow("Daadu Game server\r\n");

    async_server();


}