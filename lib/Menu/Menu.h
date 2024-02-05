#pragma once
#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "InputInterface.h"

using namespace button_interface;

class Menu
{
private:
    int _counter = 0;

    void printCounter();

    void doShortPressActionEnter();
    void doShortPressActionCancel();
    void doShortPressActionLeft();
    void doShortPressActionRight();

    unordered_map<int, function<void()>> shortPressCommands = {
        {BUTTON::ENTER, [this]()
         { doShortPressActionEnter(); }},
        {BUTTON::CANCEL, [this]()
         { doShortPressActionCancel(); }},
        {BUTTON::LEFT, [this]()
         { doShortPressActionLeft(); }},
        {BUTTON::RIGHT, [this]()
         { doShortPressActionRight(); }}};

    void doLongPressActionEnter();
    void doLongPressActionCancel();
    void doLongPressActionLeft();
    void doLongPressActionRight();

    unordered_map<int, function<void()>> longPressCommands = {
        {BUTTON::ENTER, [this]()
         { doLongPressActionEnter(); }},
        {BUTTON::CANCEL, [this]()
         { doLongPressActionCancel(); }},
        {BUTTON::LEFT, [this]()
         { doLongPressActionLeft(); }},
        {BUTTON::RIGHT, [this]()
         { doLongPressActionRight(); }}};

public:
    bool begin();
};

extern Menu menu;