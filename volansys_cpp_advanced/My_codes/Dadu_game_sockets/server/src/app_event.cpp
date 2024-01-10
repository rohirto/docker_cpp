/**
 * @file app_event.c
 * @author rohirto
 * @brief event handling from sockets
 * @version 0.1
 * @date 2024-01-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "server_sockets.h"
#include "app_event.h"

extern "C"{
    void unpack(unsigned char *buf, char *format, ...);
    unsigned int pack(unsigned char *buf, char *format, ...);
}



/**
 * @brief Dispatch Event function based on the event occured
 * 
 * @param client 
 * @param eventType Read, Write or exception
 * @param eventHandler Handlers are called based on event, implemented using function pointers (callback functions)
 * @return int 0 on success, -1 on soft error, -2 on hard error (client connection closed, release thread for new connection)
 * @callgraph
 * @callergraph
 */

int dispatchEvent_cpp(client& client, EventType eventType, EventHandler_cpp* eventHandler) 
{
    switch (eventType)
    {
    case READ_EVENT:
        if (eventHandler->onRead != NULL)
        {
            unsigned char c;
            int bytesRead;
            if ((bytesRead = recv(client.get_socket(), &c, 1, MSG_PEEK)) == -1)  //Just Peek the message to do some error handling
            {
                std::cerr <<  "Socket error\n";
                return -1;
            }
            else if (bytesRead == 0)
            {
                // set the username to offline
                client.set_status(OFFLINE);
                // if (status_handling(client->userID, client->status) == -1)
                // {
                //     debugError("status update\n");
                // }
                std::cerr << " Closed Connection on " << client.get_socket() << std::endl;
                return -2;
            }
            else
            {
                eventHandler->onRead(client);
            }
        }
        break;
    case WRITE_EVENT:
        if (eventHandler->onWrite != NULL)
        {
            eventHandler->onWrite(client);
        }
        break;
    case EXCEPTION_EVENT:
        if (eventHandler->onException != NULL)
        {
            eventHandler->onException(client);
        }
        break;
    default:
        // Handle unknown event type
        break;
    }

    return 0;
}



/**
 * @brief Read Handler, handles incoming data on socket
 * 
 * @param client User context of thread
 * @callgraph
 * @callergraph
 */
void onReadHandler_cpp(client& client) 
{
    unsigned char packet_type;
    unsigned char len;
    unsigned char buffer[128];
    int intPacketLen = 0;
    const char* t = "8s";


    // Implement read event handling
    recv(client.get_socket(), &packet_type, 1, 0);
    //get len
    recv(client.get_socket(), &len, 1, 0);
    
    switch (packet_type)
    {
    case CONFIG_PACKET:
        //Get the username
        intPacketLen = (int)len;
        if (recvall(client.get_socket(), buffer, &intPacketLen) == -1) // read the remaining packet, username and message
        {
            // Error
             std::cerr << "recv_all";
            return;
        }

        char temp_str[9];
        
        unpack(buffer, (char*)t, temp_str);
        client.p.setname(temp_str);
        //client.setname(temp_str);
        std::cout  << "Username: " <<  client.p.getname() << std::endl;
        
        break;
    case CHAT_INIT_PACKET:  //User as sent a UserID to initate chat with other user
        // //Recv packet
        // recv(client->socket,buffer,len,0);
        // unpack(buffer,"h",&client->chat_userID);
        // debugLog2("User %s wants to chat with UserID %d\n",client->username,client->chat_userID);
        // if(check_status(client->chat_userID) != 1)
        // {
        //     //User Offline, notify client
        //     client->send_msg[0] = ERROR_PACKET;
        //     client->error_flag =  1;

        // }

        break;
    case MESSAGE_PACKET:
        // recv(client->socket,buffer,len,0);
        // unpack(buffer,"s",client->rx_msg);
        // debugLog2("User %s Rx message for %d: %s\n",client->username,client->chat_userID, client->rx_msg);
        // // Need a new set of queue mechanism to handle inter thread messaging
        
        
        // if(check_status(client->chat_userID) != 1)
        // {
        //     //User Offline, notify client
        //     client->send_msg[0] = ERROR_PACKET;
        //     client->error_flag =  1;

        // }
        // else
        // {
        //     //UsrID online
        //     client->msg_flag = 1;
        // }
        
        
        break;
    
    default:
        std::cerr << "Invalid Packet\n";
        break;
    }

}



/**
 * @brief Write handler, handles writing to the socket
 * 
 * @param client 
 * @callgraph
 * @callergraph
 */
void onWriteHandler_cpp(client& client) 
{

}



/**
 * @brief Exception Handler
 * 
 * @param client 
 * @callgraph
 * @callergraph
 */
void onExceptionHandler_cpp(client& client) 
{
    // Implement exception event handling
}
