#pragma once

#include <Arduino.h>
#include "Debugger.h"

class DualCore
{
private:
    typedef void (*taskCore)();

    taskCore _taskCoreProtocol;
    taskCore _taskCoreApp;

    TaskHandle_t _taskHandleCoreProtocol;
    TaskHandle_t _taskHandleCoreApp;

    static const int TASK_STACK_SIZE = 10000;
    static const int TASK_CREATION_DELAY = 500;

    static void _loopTaskProtocol(void *args);
    static void _loopTaskApp(void *args);

    bool _startTasks();

public:
    DualCore(taskCore taskCoreProtocol, taskCore taskCoreApp);
    bool begin();
};
