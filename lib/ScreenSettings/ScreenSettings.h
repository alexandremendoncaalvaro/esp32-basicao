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
    enum MENU_OPTION
    {
        UP = 10,
        FIRST = 11,
        SECOND = 12,
        THIRD = 13,
        FOURTH = 14,
        FIFTH = 15
    };

    const int FIRST_MENU_OPTION = MENU_OPTION::UP;
    const int LAST_MENU_OPTION = MENU_OPTION::FIFTH;

    int _menuOption = FIRST_MENU_OPTION;

    void registerFunctions();
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