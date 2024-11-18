/**
 * @file async_client.h
 * @author rohirto
 * @brief async client header file
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <boost/asio.hpp>
#include <iostream>
#include <string>

//Player Protocol


void sync_tcp_client(const std::string& server_ip);
