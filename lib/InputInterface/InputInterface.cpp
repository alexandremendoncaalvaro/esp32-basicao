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

void InputInterface::doShortPressActionEnter()
{
    debugger.println(F("[INPUT] ENTER!"));
}

void InputInterface::doShortPressActionCancel()
{
    debugger.println(F("[INPUT] CANCEL!"));
}

void InputInterface::doShortPressActionLeft()
{
    debugger.println(F("[INPUT] LEFT!"));
}

void InputInterface::doShortPressActionRight()
{
    debugger.println(F("[INPUT] RIGHT!"));
}

void InputInterface::doLongPressActionEnter()
{
    debugger.println(F("[INPUT] LONG ENTER!"));
}

void InputInterface::doLongPressActionCancel()
{
    debugger.println(F("[INPUT] LONG CANCEL!"));
}

void InputInterface::doLongPressActionLeft()
{
    debugger.println(F("[INPUT] LONG LEFT!"));
}

void InputInterface::doLongPressActionRight()
{
    debugger.println(F("[INPUT] LONG RIGHT!"));
}

InputInterface inputInterface;