/**
 * @file app_event.h
 * @author rohit S
 * @brief header file for app_event.c
 * @version 0.1
 * @date 2023-11-12
 * 
 * @copyright Copyright (c) 2023 Volansys Yechnologies
 * 
 */
#ifndef APP_EVENT_H
#define APP_EVENT_H

#include <thread>
#include "player.h"
#include "server_sockets.h"

#define ONLINE  1
#define OFFLINE 0


/**
 * @brief Enum of Event types
 * 
 */
typedef enum 
{
    READ_EVENT,             /**< Read Event */
    WRITE_EVENT,            /**< Write Event */
    EXCEPTION_EVENT         /**< Exception Event */
} EventType;

// Event callback function signatures

typedef void (*ReadEventHandler_cpp)(client&);
typedef void (*WriteEventHandler_cpp)(client&);
typedef void (*ExceptionEventHandler_cpp)(client&);

// Structure to hold event handlers


/**
 * @brief struct where callback handlers are defined
 * 
 */
typedef struct 
{
    ReadEventHandler_cpp onRead;
    WriteEventHandler_cpp onWrite;
    ExceptionEventHandler_cpp onException;
} EventHandler_cpp;


//Handler Prototypes


void onReadHandler_cpp(client& ) ;
void onWriteHandler_cpp(client& ) ;
void onExceptionHandler_cpp(client& );

//Event dispatcher prototype
int dispatchEvent_cpp(client& , EventType , EventHandler_cpp* );


#endif