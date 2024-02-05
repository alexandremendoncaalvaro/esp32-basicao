#include "InputInterface.h"

bool InputInterface::begin()
{
    debugger.println(F("[INPUT_INTERFACE] Input Interface Ok!"));
    debugger.println();

    return true;
}

void InputInterface::handleInputs()
{
    for (auto &button : _buttons)
    {
        button.update();
        handleShortPress(button);
        handleLongPress(button);
    }
}

void InputInterface::setShortPressCommands(unordered_map<int, function<void()>> &commands)
{
    shortPressCommands = commands;
}

void InputInterface::setLongPressCommands(unordered_map<int, function<void()>> &commands)
{
    longPressCommands = commands;
}

void InputInterface::handleShortPress(PulseButton &button)
{
    if (button.isShortPressed())
    {
        executeButtonRelativeCommand(button, shortPressCommands);
    }
}

void InputInterface::handleLongPress(PulseButton &button)
{
    if (button.isLongPressed())
    {
        executeButtonRelativeCommand(button, longPressCommands);
    }
}

void InputInterface::executeButtonRelativeCommand(PulseButton &button, unordered_map<int, function<void()>> &commands)
{
    auto buttonAndCallbackPair = commands.find(button.getPin());
    if (buttonAndCallbackPair != commands.end())
    {
        buttonAndCallbackPair->second(); // executes the second item of the pair
    }
}

InputInterface inputInterface;