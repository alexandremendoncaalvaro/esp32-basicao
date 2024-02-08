#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"
#include "Screen.h"

using namespace button_interface;

class ScreenSettings : public Screen
{
private:
    const int FIRST_MENU_OPTION = 10;
    const int LAST_MENU_OPTION = 15;

    int _menuOption = FIRST_MENU_OPTION;

    enum MENU_OPTION
    {
        UP = 10,
        FIRST = 11,
        SECOND = 12,
        THIRD = 13,
        FOURTH = 14,
        FIFTH = 15
    };

    void printMenuOption();

    void doShortPressActionCancel();
    void doShortPressActionEnter();
    void doShortPressActionLeft();
    void doShortPressActionRight();

    void doLongPressActionCancel();
    void doLongPressActionEnter();
    void doLongPressActionLeft();
    void doLongPressActionRight();

public:
    ScreenSettings();
    void setCallback(function<void(SCREEN_NUMBER)> callback) override;
};