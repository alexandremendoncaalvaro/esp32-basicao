#include "DualCore.h"

void DualCore::_loopTaskProtocol(void *args)
{
    DualCore *instance = static_cast<DualCore *>(args);
    while (true)
    {
        instance->_taskCoreProtocol();
        vTaskDelay(1);
    }
}

void DualCore::_loopTaskApp(void *args)
{
    DualCore *instance = static_cast<DualCore *>(args);
    while (true)
    {
        instance->_taskCoreApp();
        vTaskDelay(1);
    }
}

DualCore::DualCore(taskCore taskCoreProtocol, taskCore taskCoreApp)
    : _taskCoreProtocol(taskCoreProtocol), _taskCoreApp(taskCoreApp)
{
}

bool DualCore::_startTasks()
{
    BaseType_t result1 = xTaskCreatePinnedToCore(
        _loopTaskProtocol,
        "taskProtocol",
        TASK_STACK_SIZE,
        this,
        1,
        &_taskHandleCoreProtocol,
        0);

    delay(TASK_CREATION_DELAY);

    if (result1 == pdPASS)
        debugger.println(F("[DUALCORE] TaskProtocol created"));

    BaseType_t result2 = xTaskCreatePinnedToCore(
        _loopTaskApp,
        "taskApp",
        TASK_STACK_SIZE,
        this,
        1,
        &_taskHandleCoreApp,
        1);

    if (result2 == pdPASS)
        debugger.println(F("[DUALCORE] TaskApp created"));

    return (result1 == pdPASS) && (result2 == pdPASS);
}

bool DualCore::begin()
{
    debugger.println(F("[DUALCORE] Starting Tasks..."));

    auto isTasksOk = _startTasks();

    if (!isTasksOk)
    {
        debugger.println(F("[DUALCORE] Failed to start tasks!"));
        return false;
    }

    debugger.println(F("[DUALCORE] Dual Core Ok!"));
    debugger.println();

    return true;
}