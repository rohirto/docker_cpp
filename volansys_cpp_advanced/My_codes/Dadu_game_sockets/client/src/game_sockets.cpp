/**
 * @file game_sockets.cpp
 * @author rohirto
 * @brief client side of daadu game multiplayer, sockets layer
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>
#include "game_sockets.h"

extern "C"{
    void unpack(unsigned char *buf, char *format, ...);
    unsigned int pack(unsigned char *buf, char *format, ...);
}

/**
 * @brief Get the in addr object
 * 
 * @param sa 
 * @return * void* 
 * @callergraph
 */
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in *)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

client::client()
{
    int rv;

    //Fill up the structs
    hints = {};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    try
    {
        if ((rv = getaddrinfo(SERVER_IP, SERVER_PORT, &hints, &servinfo)) != 0) // Fill up our structs using getaddrinfo function
        {

            throw "getddrinfo";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "getaddrinfo" << gai_strerror(rv);
        std::cerr << e.what() << '\n';
    }

    // loop through all the results and connect to the first we can
    for (p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
        {
            std::cerr << "client: socket";
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) // Connect to the nodes in linked list, ipv4 or ipv6
        {
            close(sockfd);
            std::cerr << "client: connect";
            continue;
        }
        break;
    }

    try
    {
        if (p == NULL)
        {
            throw  "client: failed to connect\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
                  s, sizeof(s));
        std::cout << "client: connecting to " << s << std::endl;
        freeaddrinfo(servinfo); // all done with this structure

    std::cout << "Connected to the server" << std::endl;

    state = 0;   //init done
    
}


/**
 * @brief Send all bytes in buffer on socket s
 * 
 * @param s Socket file descriptor s 
 * @param buf unsigned char* buffer to be sent
 * @param len int* no of bytes to be sent, updated with actual no of bytes
 * @return int -1 on failure, 0 on success
 * @callergraph
 */
int sendall(int s, unsigned char *buf, int *len)
{
    int total = 0;        // how many bytes we've sent
    int bytesleft = *len; // how many we have left to send
    int n = 0;
    while (total < *len)
    {
        n = send(s, buf + total, bytesleft, 0);
        if (n == -1)
        {
            std::cerr << "Error no: " << errno << std::endl;;
            if (errno == EPIPE || errno == ECONNRESET)
            {
                return -1;
            }
            break;
        }
        total += n;
        bytesleft -= n;
    }
    *len = total;            // return number actually sent here
    return n == -1 ? -1 : 0; // return -1 on failure, 0 on success
}

/**
 * @brief Send a User Defined Packet
 * 
 * @param socket where the data is to be sent
 * @param packet_type Config, chat init or message packet
 * @param format the format in which variable args are passed, eg "sh" -> string and signed int
 * @param ...  Variable arguments
 * @return int 0 on success -1 on failure
 * @callgraph
 * @callergraph
 * @paragraph Protocol
 *  |Packet Type 1 Byte| len 1 Byte | Body - Max 128 Bytes |
 *  
 *  Max 130 Bytes packet can be there
 */
int client::send_packet(int socket, unsigned char packet_type, const char *format, ...)
{
    unsigned char buff[130];
    int len_to_tx = 0, l = 0;
    buff[0] = packet_type;
    const char* ss = "s";
    const char* hh = "h";


    va_list args;
    va_start(args, format);

    int h;
    char *s;

    for(; *format != '\0'; format++) 
    {
        switch(*format) 
        {
            case 's':
                s = va_arg(args, char*);
                l = pack(buff+(2+len_to_tx),(char*)ss,s);
                len_to_tx += l;
                break;
            
            case 'h': // 16-bit
			    h = va_arg(args, int);
                l = pack(buff+(2+len_to_tx),(char*)hh,h);
                len_to_tx +=l;
			    break;
            

            default:
                break;
        }
        
    }

    va_end(args);
    buff[1] = len_to_tx;
    len_to_tx = len_to_tx + 2;
    if (sendall(socket, buff, &len_to_tx) == -1)
    {
        std::cerr << "sendall";
        return -1;
    }
    return 0;

}


/**
 * @brief Client Handle to handle the connection with server
 * 
 * @return int Usually does not returns, returns -1 on error
 * @callgraph 
 * @callergraph
 */
int client::client_handle()
{
    // Set stdin to non-blocking mode
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);



    fd_set master;                      // master file descriptor list
    fd_set read_fds;                    // temp file descriptor list for select()
    fd_set write_fds;
    int fdmax;                          // maximum file descriptor number
    int fd = STDIN_FILENO;

    //Macros for select()
    FD_ZERO(&master); // clear the master and temp sets
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);

    //Load the file descriptors into master list
    FD_SET(sockfd, &master);  //Socket descriptor
    FD_SET(fd, &master);      //stdin descriptor

    if(sockfd > fd)         //Check which one is fdmax
    {
        fdmax = sockfd;
    }
    else
    {
        fdmax = fd;
    }

    while(1)
    {
        read_fds = master;  // Save a copy of master
        write_fds = master; ////Save a copy of master

        try
        {
            if (select(fdmax + 1, &read_fds, &write_fds, NULL, NULL) == -1) // we will need both read and write functions
            {
                throw "select";
            }
            // run through the existing connections looking for data to read
            for (int i = 0; i <= fdmax; i++)
            {
                if (FD_ISSET(i, &read_fds)) // If any of the read_fds is set
                {
                    if (i == sockfd) // If receive on socketfd
                    {
                        
                    }
                    else if(i == fd)
                    {

                    }
                }
                if (FD_ISSET(i, &write_fds))
                {
                    if( i == sockfd)
                    {

                    }
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}