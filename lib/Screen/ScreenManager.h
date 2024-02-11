#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"
#include "Screen.h"
#include "ScreenMainMenu.h"
#include "ScreenSettings.h"

class ScreenManager
{
private:
    Screen *_screen;
    void applyScreen();

public:
    bool begin();
    void setScreen(SCREEN_NUMBER screen);
};

extern ScreenManager screenManager;