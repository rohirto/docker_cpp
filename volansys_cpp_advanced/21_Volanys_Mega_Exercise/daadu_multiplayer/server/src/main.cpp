/**
 * @file main.cpp
 * @author rohirto
 * @brief Main.cpp 
 * @version 0.1
 * @date 2024-11-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "server_config.h"
#include "async_server.h"
#include "server_screen.h"

int main()
{
    server_screen::get_instance().display_yellow("Daadu Game server\r\n");

    try {
        const unsigned short port = TCP_PORT;
        const std::size_t thread_count = NO_OF_PLAYERS; // No of players

        asio::io_context ioc;

        // Work guard to keep io_context running
        auto work_guard = asio::make_work_guard(ioc);

        // Start server
        Server server(ioc, port, thread_count);
        std::cout << "Server running on port " << port << " with " << thread_count << " threads.\n";

        // Run the io_context in a thread pool
        std::vector<std::thread> threads;
        for (std::size_t i = 0; i < thread_count; ++i) {
            threads.emplace_back([&ioc]() { ioc.run(); });
        }

        // Wait for all threads to finish
        for (auto& t : threads) {
            if (t.joinable()) {
                t.join();
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;


}