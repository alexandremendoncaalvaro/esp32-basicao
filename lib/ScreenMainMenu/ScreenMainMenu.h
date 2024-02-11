#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"
#include "Screen.h"

using namespace button_interface;

class ScreenMainMenu : public Screen
{
private:
    enum MENU_OPTION
    {
        UP = 0,
        SETTINGS = 1,
        SECOND = 2,
        THIRD = 3,
    };

    const int FIRST_MENU_OPTION = MENU_OPTION::UP;
    const int LAST_MENU_OPTION = MENU_OPTION::THIRD;

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
    ScreenMainMenu();
    void setCallback(function<void(SCREEN_NUMBER)> callback) override;
};