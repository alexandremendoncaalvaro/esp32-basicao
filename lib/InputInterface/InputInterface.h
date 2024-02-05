#pragma once

#include <Arduino.h>
#include <unordered_map>
#include <functional>
#include "Debugger.h"
#include "Duration.h"
#include "PulseButton.h"

namespace button_interface
{
    enum BUTTON
    {
        ENTER = 12,
        CANCEL = 13,
        LEFT = 14,
        RIGHT = 15
    };
}
using namespace std;
using namespace button_interface;

class InputInterface
{
private:
    PulseButton _buttons[4] = {
        PulseButton(BUTTON::ENTER),
        PulseButton(BUTTON::CANCEL),
        PulseButton(BUTTON::LEFT),
        PulseButton(BUTTON::RIGHT),
    };

    unordered_map<int, function<void()>> shortPressCommands = {};
    unordered_map<int, function<void()>> longPressCommands = {};

    void handleShortPress(PulseButton &button);
    void handleLongPress(PulseButton &button);
    void executeButtonRelativeCommand(PulseButton &button, unordered_map<int, function<void()>> &commands);

public:
    bool begin();
    void handleInputs();
    void setShortPressCommands(unordered_map<int, function<void()>> &commands);
    void setLongPressCommands(unordered_map<int, function<void()>> &commands);
};

extern InputInterface inputInterface;