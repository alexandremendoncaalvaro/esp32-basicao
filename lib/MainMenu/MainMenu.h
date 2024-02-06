#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"
#include "Screen.h"

using namespace button_interface;

class MainMenu : public Screen
{
private:
    int _menuOption = 0;

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
    MainMenu();
    void setCallback(function<void(SCREEN_NUMBER)> callback) override;
};