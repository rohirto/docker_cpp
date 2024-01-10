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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdarg.h>

#define SERVER_IP       "127.0.0.1"
#define SERVER_PORT     "9034"

#define CONFIG_PACKET       0x01    /**< Config Packets - for config purpose - username getting*/
#define CHAT_INIT_PACKET    0x02    /**< Chat init packet - from client to server only, to let server know which user Id to chat with */
#define MESSAGE_PACKET      0x03    /**< Message Packet - Carries message intended for the other client thread */
#define ERROR_PACKET        0x04    /**< Error packets - from server to client only, when some error has occured */


class client {
    int sock;
    struct sockaddr_in address;
    // Other client-specific data
    struct addrinfo hints;      /**< Some Server related structs */
    struct addrinfo *servinfo; 
    struct addrinfo *p; 

    struct sockaddr_storage remoteaddr;     /**< Client Connection related Variables*/
    socklen_t addrlen;
    char s[INET6_ADDRSTRLEN];
    int sockfd;

    int state;

public:
    client();
    int send_packet(int socket, unsigned char packet_type, const char *format, ...);
    int client_handle();


    int get_socket(){return sockfd;}
};


#endif