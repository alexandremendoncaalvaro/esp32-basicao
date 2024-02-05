#include "Menu.h"

bool Menu::begin()
{
    inputInterface.begin();
    inputInterface.setShortPressCommands(shortPressCommands);
    inputInterface.setLongPressCommands(longPressCommands);

    debugger.println(F("[INPUT_INTERFACE] Input Interface Ok!"));
    debugger.println();

    return true;
}

void Menu::printCounter()
{
    Serial.print(F("Contador: "));
    Serial.println(_counter);
    Serial.println();
}

void Menu::doShortPressActionEnter()
{
    debugger.println(F("[INPUT] ENTER!"));
    Menu::printCounter();
}

void Menu::doShortPressActionCancel()
{
    debugger.println(F("[INPUT] CANCEL!"));
    _counter = 0;
    Menu::printCounter();
}

void Menu::doShortPressActionLeft()
{
    debugger.println(F("[INPUT] LEFT!"));
    _counter--;
    Menu::printCounter();
}

void Menu::doShortPressActionRight()
{
    debugger.println(F("[INPUT] RIGHT!"));
    _counter++;
    Menu::printCounter();
}

void Menu::doLongPressActionEnter()
{
    debugger.println(F("[INPUT] LONG ENTER!"));
}

void Menu::doLongPressActionCancel()
{
    debugger.println(F("[INPUT] LONG CANCEL!"));
}

void Menu::doLongPressActionLeft()
{
    debugger.println(F("[INPUT] LONG LEFT!"));
}

void Menu::doLongPressActionRight()
{
    debugger.println(F("[INPUT] LONG RIGHT!"));
}

Menu menu;