/**
 * @file main_client.cpp
 * @author rohirto
 * @brief 
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "client_screen.h"
#include "async_client.h"
#include "game_menu.h"
#include "game_event.h"


#include <boost/asio.hpp>
#include <iostream>



int main() {
    try
    {
        #if 0
        asio::io_context ioc;
        TCPClient client(ioc, "127.0.0.1", "12345"); //In funture this will be some DHCP discovery

        client_screen *window; // Polymorphic class
        menu m;

        window = &m;
        int choice = window->display_menu();

        if (choice == 1)
        {
            // Start the game
            window->clear();
            // player p1(1);  //Initalize player 1 and send its info to server

            // Get the list of players on the Server
            ioc.run();

            while (1)
                ;
        }
        #else
        TCPClient client("127.0.0.1", 12345);
        client.run();
        #endif
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}
