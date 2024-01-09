/**
 * @file server_sockets.h
 * @author rohirto
 * @brief Sockets header for server of dadu game
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _SERVER_SOCKETS_H
#define _SERVER_SOCKETS_H

#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <cstdlib>
#include <vector>
#include <fcntl.h>
#include <mutex>
#include <condition_variable>
#include <queue>
#include "player.h"

#define NUM_THREADS 2   //no of threads in threadpool
#define PORT "9034"

class server{
    //All server info
    unsigned int no_of_active_connections;  /**< No of Active Connections */
    int listener;               /**< Listener for new connetions */
    struct addrinfo hints;      /**< Some Server related structs */
    struct addrinfo *ai; 
    struct addrinfo *p; 

    struct sockaddr_storage remoteaddr;     /**< Client Connection related Variables*/
    socklen_t addrlen;
    char remoteIP[INET6_ADDRSTRLEN];
    int newfd;

    //pthread_t thread_pool[2];    /**< Thread pool defined*/

    std::vector<std::thread> thread_pool;

    //Synchronization mechanims
    std::mutex mutex;
    std::condition_variable condition_var;
    std::queue<player*> player_queue;

public:
    server();
    int server_listen();
    void client_handle(player* p);
    int sendall(int , unsigned char *, int *);
    int recvall(int , void *, int *);
    int make_sock_nonblocking(int fd);
    int check_connection(int );
    void soft_error_handle(const char*);
    void hard_error_handle(const char* );
    int send_packet(int , unsigned char , const char*,...);

    void thread_joining();

private:
    void thread_function(int thread_index);
    player* dequeue();
};

#endif