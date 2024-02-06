#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"

enum SCREEN_NUMBER
{
    MAIN_MENU,
    SETTINGS
};

class Screen
{
protected:
    function<void(SCREEN_NUMBER)> callback;

public:
    unordered_map<int, function<void()>> shortPressCommands;
    unordered_map<int, function<void()>> longPressCommands;
    virtual void setCallback(function<void(SCREEN_NUMBER)> callback) = 0;
};