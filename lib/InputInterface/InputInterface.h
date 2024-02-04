#pragma once

#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "Debugger.h"
#include "Duration.h"
#include "PulseButton.h"

using namespace std;
class InputInterface
{
private:
    enum MENU_BUTTON
    {
        ENTER = 12,
        CANCEL = 13,
        LEFT = 14,
        RIGHT = 15
    };

    PulseButton _buttons[4] = {
        PulseButton(MENU_BUTTON::ENTER),
        PulseButton(MENU_BUTTON::CANCEL),
        PulseButton(MENU_BUTTON::LEFT),
        PulseButton(MENU_BUTTON::RIGHT),
    };

    void doShortPressActionEnter();
    void doShortPressActionCancel();
    void doShortPressActionLeft();
    void doShortPressActionRight();

    unordered_map<int, function<void()>> shortPressCommands = {
        {MENU_BUTTON::ENTER, [this]()
         { doShortPressActionEnter(); }},
        {MENU_BUTTON::CANCEL, [this]()
         { doShortPressActionCancel(); }},
        {MENU_BUTTON::LEFT, [this]()
         { doShortPressActionLeft(); }},
        {MENU_BUTTON::RIGHT, [this]()
         { doShortPressActionRight(); }}};

    void doLongPressActionEnter();
    void doLongPressActionCancel();
    void doLongPressActionLeft();
    void doLongPressActionRight();

    unordered_map<int, function<void()>> longPressCommands = {
        {MENU_BUTTON::ENTER, [this]()
         { doLongPressActionEnter(); }},
        {MENU_BUTTON::CANCEL, [this]()
         { doLongPressActionCancel(); }},
        {MENU_BUTTON::LEFT, [this]()
         { doLongPressActionLeft(); }},
        {MENU_BUTTON::RIGHT, [this]()
         { doLongPressActionRight(); }}};

public:
    bool begin();
    void handleInputs();
    void handleShortPress(PulseButton &button);
    void executeButtonRelativeCommand(PulseButton &button, unordered_map<int, function<void()>> &commands);
    void handleLongPress(PulseButton &button);
};

extern InputInterface inputInterface;