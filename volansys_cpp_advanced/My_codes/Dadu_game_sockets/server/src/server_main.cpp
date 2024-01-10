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
#include "app_event.h"

void init_player(client& p)
{
    p.set_configflag(0);
    p.set_msgflag(0);
    p.set_errorflag(0);
}

int main()
{
    
    server s;
    client c1(1), c2(2);
    
    if(s.server_listen(c1,c2) == 0)
    {
        

        //Get the player names of the both players


        //Got the connections for p1 and p2, start the game
        init_player(c1);
        init_player(c2);

        //Now we have received player 1 and player 2 names, all that remains is getting turns and inputs from players

        // Select loop to keep a tab of p1 and p2
        EventType event;
        // Set up event handlers
        EventHandler_cpp eventHandler =
            {
                .onRead = onReadHandler_cpp,
                .onWrite = onWriteHandler_cpp,
                .onException = onExceptionHandler_cpp};
        
        fd_set c_master;                      // master file descriptor list
        fd_set c_read_fds;                    // temp file descriptor list for select()
        fd_set c_write_fds;
        int c_fdmax;

        // Initialize FDs
        // Initialize file descriptor sets
        FD_ZERO(&c_master); // clear the master and temp sets
        FD_ZERO(&c_read_fds);
        FD_ZERO(&c_write_fds);

        FD_SET(c1.get_socket(), &c_master);
        FD_SET(c2.get_socket(), &c_master);

        if (c1.get_socket() > c2.get_socket()) // Check which one is fdmax
        {
            c_fdmax = c1.get_socket();
        }
        else
        {
            c_fdmax = c2.get_socket();
        }

        while (1)
        {
            c_read_fds = c_master;                                              // copy it, need to keep a safe copy of master fds
            c_write_fds = c_master;

            // Use select to wait for activity on descriptors
            if (select(c_fdmax + 1, &c_read_fds, &c_write_fds, NULL, NULL) == -1)
            {

                std::cerr << "select";
                continue;
            }

            // run through the existing connections looking for data to read
            // Visualizing this loop as a polling agent,which will be used to call our event dispatcher
            if (FD_ISSET(c1.get_socket(), &c_read_fds))
            {
                event = READ_EVENT;
                //If any data received on player 1 socket
                int retval = dispatchEvent_cpp(c1, event, &eventHandler);

            }
            else if (FD_ISSET(c2.get_socket(), &c_read_fds))
            {
                //If any data received on player 2 socket
                event = READ_EVENT;
                //If any data received on player 1 socket
                int retval = dispatchEvent_cpp(c2, event, &eventHandler);
                
            }



            //Actual game logic goes here
        }
    }

    //s.thread_joining();

    return 0;
}