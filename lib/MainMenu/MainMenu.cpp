#include "MainMenu.h"

void MainMenu::printMenuOption()
{
    Serial.print(F("Option: "));
    Serial.println(_menuOption);
    Serial.println();
}

void MainMenu::doShortPressActionCancel()
{
    debugger.println(F("[INPUT] CANCEL!"));
    _menuOption = 0;
    MainMenu::printMenuOption();
}

void MainMenu::doShortPressActionEnter()
{
    debugger.println(F("[INPUT] ENTER!"));
    MainMenu::printMenuOption();
}

void MainMenu::doShortPressActionLeft()
{
    debugger.println(F("[INPUT] LEFT!"));
    _menuOption--;
    if (_menuOption < 0)
    {
        _menuOption = 0;
    }
    MainMenu::printMenuOption();
}

void MainMenu::doShortPressActionRight()
{
    debugger.println(F("[INPUT] RIGHT!"));
    _menuOption++;
    if (_menuOption > 3)
    {
        _menuOption = 3;
    }
    MainMenu::printMenuOption();
}

void MainMenu::doLongPressActionCancel()
{
    debugger.println(F("[INPUT] LONG CANCEL!"));
}

void MainMenu::doLongPressActionEnter()
{
    debugger.println(F("[INPUT] LONG ENTER!"));
}

void MainMenu::doLongPressActionLeft()
{
    debugger.println(F("[INPUT] LONG LEFT!"));
}

void MainMenu::doLongPressActionRight()
{
    debugger.println(F("[INPUT] LONG RIGHT!"));
}

MainMenu::MainMenu()
{
    debugger.println(F("[MAIN_MENU] Loaded!"));
    shortPressCommands = {
        {BUTTON::CANCEL, [this]()
         { doShortPressActionCancel(); }},
        {BUTTON::ENTER, [this]()
         { doShortPressActionEnter(); }},
        {BUTTON::LEFT, [this]()
         { doShortPressActionLeft(); }},
        {BUTTON::RIGHT, [this]()
         { doShortPressActionRight(); }}};

    longPressCommands = {
        {BUTTON::CANCEL, [this]()
         { doLongPressActionCancel(); }},
        {BUTTON::ENTER, [this]()
         { doLongPressActionEnter(); }},
        {BUTTON::LEFT, [this]()
         { doLongPressActionLeft(); }},
        {BUTTON::RIGHT, [this]()
         { doLongPressActionRight(); }}};
}

MainMenu mainMenu;