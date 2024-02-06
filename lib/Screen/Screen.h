#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"

class Screen
{
public:
    unordered_map<int, function<void()>> shortPressCommands;
    unordered_map<int, function<void()>> longPressCommands;
};