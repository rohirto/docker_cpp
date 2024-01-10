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

#define CONFIG_PACKET       0x01    /**< Config Packets - for config purpose - username getting*/
#define CHAT_INIT_PACKET    0x02    /**< Chat init packet - from client to server only, to let server know which user Id to chat with */
#define MESSAGE_PACKET      0x03    /**< Message Packet - Carries message intended for the other client thread */
#define ERROR_PACKET        0x04    /**< Error packets - from server to client only, when some error has occured */

class client{

    int socket;                 /**< Scket FD of the USer*/
    int threadID;               /**< Thread ID, 0 to 20 */
    int first_flag;             /**< 255 when first initialized, 0 when the user has been sent username list even once */
    int config_flag;            /**< Set when some config packet is received and needs to be processesd*/
    int msg_flag;               /**< Set when some message packet is received */
    int error_flag;             /**< Set when some error flag is received */
    int status;                 /**< Status - 1 Online, 0 Offline */
    

public:
    player p;
    client(){}
    explicit client(int no);
    void set_socket(int sock){socket = sock;}
    void set_firstflag(int val){first_flag = val;}
    void set_threadID(int val){threadID = val;}
    void set_configflag(int val){config_flag = val;}
    void set_msgflag(int val){msg_flag = val;}
    void set_errorflag(int val){error_flag = val;}
    void set_status(int val){status = val;}

    int get_threadID(){return threadID;}
    int get_configflag(){return config_flag;}
    int get_msgflag(){return msg_flag;}
    int get_errorflag(){return error_flag;}
    int get_firstflag(){return first_flag;}
    int get_socket(){return socket;}
    int get_status(){return status;}

};

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

#if 0
    std::vector<std::thread> thread_pool;

    //Synchronization mechanims
    std::mutex mutex;
    std::condition_variable condition_var;
    std::queue<player*> player_queue;
#endif

public:
    server();
    int server_listen(client& p1, client& p2);
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




int recvall(int s, void *buf, int *len);

#endif