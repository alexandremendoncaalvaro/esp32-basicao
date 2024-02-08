#include "ScreenMainMenu.h"

void ScreenMainMenu::printMenuOption()
{
    Serial.print(F("Option: "));
    Serial.println(_menuOption);
    Serial.println();
}

void ScreenMainMenu::doShortPressActionCancel()
{
    debugger.println(F("[MAIN MENU] CANCEL!"));
    _menuOption = MENU_OPTION::UP;
    ScreenMainMenu::printMenuOption();
}

void ScreenMainMenu::doShortPressActionEnter()
{
    debugger.println(F("[MAIN MENU] ENTER!"));
    ScreenMainMenu::printMenuOption();
    switch (_menuOption)
    {
    case MENU_OPTION::UP:
        debugger.println(F("[MAIN MENU]"));
        break;

    case MENU_OPTION::SETTINGS:
        callback(SCREEN_NUMBER::SETTINGS);
        break;

    case MENU_OPTION::SECOND:
        debugger.println(F("[MAIN MENU] SECOND OPTION"));
        break;

    case MENU_OPTION::THIRD:
        debugger.println(F("[MAIN MENU] THIRD OPTION"));
        break;

    default:
        break;
    }
    debugger.println();
}

void ScreenMainMenu::doShortPressActionLeft()
{
    debugger.println(F("[MAIN MENU] LEFT!"));
    _menuOption--;
    if (_menuOption < 0)
    {
        _menuOption = 0;
    }
    ScreenMainMenu::printMenuOption();
}

void ScreenMainMenu::doShortPressActionRight()
{
    debugger.println(F("[MAIN MENU] RIGHT!"));
    _menuOption++;
    if (_menuOption > 3)
    {
        _menuOption = 3;
    }
    ScreenMainMenu::printMenuOption();
}

void ScreenMainMenu::doLongPressActionCancel()
{
    debugger.println(F("[MAIN MENU] LONG CANCEL!"));
}

void ScreenMainMenu::doLongPressActionEnter()
{
    debugger.println(F("[MAIN MENU] LONG ENTER!"));
}

void ScreenMainMenu::doLongPressActionLeft()
{
    debugger.println(F("[MAIN MENU] LONG LEFT!"));
}

void ScreenMainMenu::doLongPressActionRight()
{
    debugger.println(F("[MAIN MENU] LONG RIGHT!"));
}

ScreenMainMenu::ScreenMainMenu()
{
    debugger.println(F("[MAIN MENU] Loaded!"));
    debugger.println();

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

void ScreenMainMenu::setCallback(function<void(SCREEN_NUMBER)> callback)
{
    this->callback = callback;
}