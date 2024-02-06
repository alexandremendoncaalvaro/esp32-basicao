#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"
#include "Screen.h"
#include "MainMenu.h"

class ScreenManager
{
private:
public:
    bool begin();
    void setScreen(Screen &screen);
};

extern ScreenManager screenManager;