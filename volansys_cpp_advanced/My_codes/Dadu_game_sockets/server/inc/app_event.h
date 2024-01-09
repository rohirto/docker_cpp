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
typedef void (*ReadEventHandler)(player*);
typedef void (*WriteEventHandler)(player*);
typedef void (*ExceptionEventHandler)(player*);

// Structure to hold event handlers
/**
 * @brief struct where callback handlers are defined
 * 
 */
typedef struct 
{
    ReadEventHandler onRead;
    WriteEventHandler onWrite;
    ExceptionEventHandler onException;
} EventHandler;


//Handler Prototypes
void onReadHandler(player* ) ;
void onWriteHandler(player* ) ;
void onExceptionHandler(player* );

//Event dispatcher prototype
int dispatchEvent(player* , EventType , EventHandler* );


#endif