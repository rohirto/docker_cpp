/**
 * @file example_static_memory_allocation.h
 * @author rohirto
 * @brief Header for Static memory alloc
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include "FreeRTOS.h"
#include "task.h"

//Prototypes
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, StackType_t *pulIdleTaskStackSize);
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, StackType_t *pulTimerTaskStackSize);