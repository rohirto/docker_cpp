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
#include "app_event.h"
#include "player.h"

#define USE_THREADS 0


#if USE_THREADS
std::mutex myMutex; // Declare a mutex

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

            std::cout << "Thread " << index << " is running.\n";

            //Handle the client
            client_handle(p);

            //If here then means client closed the connection
            std::cout << "Client has Disconnected\n";
        }

    }
}

#endif
server::server()
{
    #if USE_THREADS
    //create thread pool 
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_pool.emplace_back([this, i]() {
            thread_function(i);
        });
    }
    #endif

    no_of_active_connections = 0;

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

client::client(int no)
{
    p = player(no);
}

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in *)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

int server::server_listen(client& p1, client& p2)
{
    //Listen
    try
    {
        if (listen(listener, 2) == -1)  //2 is max listener backlog
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

        //Can have simple 2 objects instead of 2 theads

        if(no_of_active_connections == 1)
        {
            p1.set_socket(newfd);
            p1.set_firstflag(255);

        }
        else if(no_of_active_connections == 2)
        {
            p2.set_socket(newfd);
            p2.set_firstflag(255);

            return 0;

        }
        
    
#if USE_THREADS
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
#endif

        
        

    }
}

#if USE_THREADS

void server::thread_joining()
{
    // Join all threads
    for (auto &thread : thread_pool)
    {
        thread.join();
    }
}

#endif

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

#if USE_THREADS
void server::client_handle(player* p)
{
    player client = *p;

    delete p; //To avoid memory leak

    int retval;

    client.set_configflag(0);
    client.set_msgflag(0);
    client.set_errorflag(0);

    EventType event;
    // Set up event handlers
    EventHandler eventHandler = 
    {
        .onRead = onReadHandler,
        .onWrite = onWriteHandler,
        .onException = onExceptionHandler
    };

    fd_set c_master;                      // master file descriptor list
    fd_set c_read_fds;                    // temp file descriptor list for select()
    fd_set c_write_fds;
    int c_fdmax;

    //Initialize FDs
    // Initialize file descriptor sets
    FD_ZERO(&c_master); // clear the master and temp sets
    FD_ZERO(&c_read_fds);
    FD_ZERO(&c_write_fds);

    FD_SET(client.get_socket(), &c_master);
    // keep track of the biggest file descriptor
    c_fdmax = client.get_socket(); // so far, it's this one

    while(1)
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
        if (FD_ISSET(client.get_socket(), &c_read_fds))
        {
            event = READ_EVENT;
            {
                std::lock_guard<std::mutex> lock(myMutex);
                retval = dispatchEvent(&client, event, &eventHandler);
            }//mutex lock unlocks after out of scope
            if(retval  == -2)
            {
                //Close the socket and return only when 0 is received on recv
                close(client.get_socket());
                FD_CLR(client.get_socket(),&c_master);
                return; //Socket closed due to error
            }

            
        }
    }

    //receive the player name

    


}

#endif

/**
 * @brief receive all the bytes of len to socket 
 * @param int s - socket descriptor
 * @param unsigned char *buf - buffer to be rx
 * @param int* len - len to be rx, also how many bytes were actually rx is updated here
 * @returns -1 on failure or 0 on success
 * 
 * @paragraph - to check if socket is closed on other side, just check the *len, if it is zero then connection was closed
 * @callergraph
*/
int recvall(int s, void *buf, int *len)
{
    unsigned char* buff = (unsigned char*) buf;
    int total = 0;        // how many bytes we've received
    int bytesleft = *len; // how many bytes we have left to receive
    int n = 0;
    while (total < *len)
    {
        n = recv(s, buff + total, bytesleft, 0);
        if (n == -1)
        {
            break;
        }
        total += n;
        bytesleft -= n;
    }
    *len = total;            // return the number actually received here
    return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}