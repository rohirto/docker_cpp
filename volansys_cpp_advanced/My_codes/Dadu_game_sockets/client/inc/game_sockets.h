/**
 * @file game_sockets.h
 * @author rohirto
 * @brief Sockets header file for dadu game
 * @version 0.1
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef _GAME_SOCKETS_H_
#define _GAME_SOCKETS_H_

#include <iostream>
#include <vector>
#include <mutex>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>
#include <thread>  //C++11 sockets, as opposed to POSIX threads, p_threads

class client {
    int socket;
    struct sockaddr_in address;
    // Other client-specific data
};


#endif