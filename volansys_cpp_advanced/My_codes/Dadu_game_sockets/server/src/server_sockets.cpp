/**
 * @file server_sockets.cpp
 * @author rohirto
 * @brief Sockets implementation for dadu game
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <stdexcept>
#include "server_sockets.h"
#include "player.h"

player* server::dequeue()
{
    if(!player_queue.empty())
    {
        player* p = player_queue.front();
        player_queue.pop();
        return p;
    }
    else
    {
        return nullptr;
    }
}

void server::thread_function(int index) {
    std::cout << "Thread " << index << " is running.\n";
    // Your thread logic here

    while(1)
    {
        player *p = nullptr;
        {
            std::unique_lock<std::mutex> lock(mutex);
            if((p = dequeue()) == nullptr)
            {
                // If the queue is empty, wait for a signal
                condition_var.wait(lock);

                //Try again
                p = dequeue();
            }
        }// Unlock the mutex automatically when the unique_lock goes out of scope

        if(p != nullptr)
        {
            //We have a new connection handle it acc
            p->set_threadID(index);

            //Handle the client
            client_handle(p);

            //If here then means client closed the connection
            std::cout << "Client has Disconnected\n";
        }

    }
}

server::server()
{
    //create thread pool 
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_pool.emplace_back([this, i]() {
            thread_function(i);
        });
    }

    // get us a socket and bind it
    hints = {};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    

    try
    {
        int rv;
        if ((rv = getaddrinfo(NULL, PORT, &hints, &ai)) != 0) // fill up the structs
        {
            std::cerr << "selectserver: " << gai_strerror(rv);
            // Throw error
            throw "selectserver";
        }
    }
    catch(const std::exception& e)
    {
        // Catch the exception and handle the error
        std::cerr << "Error creating object: " << e.what() << "\n";
    }

    for (p = ai; p != NULL; p = p->ai_next)
    {
        listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol); // Create the socket descriptor
        if (listener < 0)
        {
            continue;
        }
    
        // lose the pesky "address already in use" error message
        int yes = 1; // for setsockopt() SO_REUSEADDR, below
        setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

        if (bind(listener, p->ai_addr, p->ai_addrlen) < 0)
        {
            close(listener);
            continue;
        }
        break;

        // if we got here, it means we didn't get bound
        try
        {
            if (p == NULL)
            {
                std::cerr << "selectserver: failed to bind\n";
                throw "selectserver";
            }
        }
        catch(const std::exception& e)
        {
            freeaddrinfo(ai); // all done with this  //This can have dangeorous effect on struct?
            std::cerr << e.what() << '\n';
        }
        
        

        

    }

}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in *)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

int server::server_listen()
{
    //Listen
    try
    {
        if (listen(listener, 10) == -1)  //10 is max listener backlog
        {
            
            throw "listen";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // main loop
    for (;;)
    {
        addrlen = sizeof(remoteaddr);
        newfd = accept(listener,
                       (struct sockaddr *)&remoteaddr,
                       &addrlen);
        
        try
        {
            if (newfd == -1)
            {
                throw "accept";
            }
            else
            {
                std::cout << "selectserver: new connection from" << inet_ntop(remoteaddr.ss_family,get_in_addr((struct sockaddr *)&remoteaddr),remoteIP, INET6_ADDRSTRLEN)
                << "on socket " << newfd << std::endl;

               no_of_active_connections++;
                std::cout << "No of Active Connections: "<< no_of_active_connections<< std::endl;
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        if (make_sock_nonblocking(newfd) == -1)
        {
            std::cerr << "sock nonblocking";
            continue;
        }

        //Make a new player
        player *p = new player();
        if(p == nullptr)
        {
            std::cerr << "new";
            continue;
        }
        p->set_socket(newfd);
        p->set_firstflag(255);  //To signify that its a brand new connection and not a reconnection

        {
            // Lock the mutex
            // Enqueue the player
            // Signal the condition variable

            std::unique_lock<std::mutex> lock(mutex);
            player_queue.push(p);
            condition_var.notify_one();
        }// Unlock the mutex automatically when the unique_lock goes out of scope
        

    }
}

void server::thread_joining()
{
    // Join all threads
    for (auto &thread : thread_pool)
    {
        thread.join();
    }
}

/**
 * @brief Make the socket Non Blocking, to acheive async functionality
 * 
 * @param fd file descriptor of socket
 * @return int 0 on success, -1 on failure
 * @callergraph
 */
int server::make_sock_nonblocking(int fd)
{
    if(fcntl(fd, F_SETFL, O_NONBLOCK) != 0)
    {
        std::cerr << "fcntl";
        return -1;
    }
    return 0;
}


void server::client_handle(player* p)
{
    player client = *p;

    delete p; //To avoid memory leak

    int retval;

    client.set_configflag(0);
    client.set_msgflag(0);
    client.set_errorflag(0);

    


}