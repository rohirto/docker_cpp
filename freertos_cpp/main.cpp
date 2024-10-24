#include <iostream>
#include "FreeRTOS/Task.hpp"

class MyTask : public FreeRTOS::Task
{
public:
    MyTask(const UBaseType_t priority, const char *name)
        : FreeRTOS::Task(priority, configMINIMAL_STACK_SIZE, name) {}
    void taskFunction() final;
};

// Task to be created.
void MyTask::taskFunction()
{
    // Block for 500ms.
    constexpr TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
    for (;;)
    {
        // Task code goes here.
        std::cout << "Hello Cpp\r\n";
        delay(xDelay);
    }
}

int main()
{
    // Create the task.
    MyTask task((tskIDLE_PRIORITY + 1), "NAME");

    // Check that the task was created successfully.
    if (task.isValid())
    {
        // Start the scheduler.
        FreeRTOS::Kernel::startScheduler();
    }

    return 0;
}