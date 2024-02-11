#include "ScreenSettings.h"

// -----------------------------------------------------------------------------
// Short Press Actions

void ScreenSettings::doShortPressActionEnter()
{
    debugger.println(F("[SETTINGS] ENTER!"));
    ScreenSettings::printMenuOption();
    switch (_menuOption)
    {
    case MENU_OPTION::UP:
        callback(SCREEN_NUMBER::MAIN_MENU);
        break;

    case MENU_OPTION::FIRST:
        debugger.println(F("[MAIN MENU] FIRST OPTION"));
        break;

    case MENU_OPTION::SECOND:
        debugger.println(F("[MAIN MENU] SECOND OPTION"));
        break;

    case MENU_OPTION::THIRD:
        debugger.println(F("[MAIN MENU] THIRD OPTION"));
        break;

    case MENU_OPTION::FOURTH:
        debugger.println(F("[MAIN MENU] FOURTH OPTION"));
        break;

    case MENU_OPTION::FIFTH:
        debugger.println(F("[MAIN MENU] FIFTH OPTION"));
        break;
    default:
        break;
    }
    debugger.println();
}

void ScreenSettings::doShortPressActionCancel()
{
    debugger.println(F("[SETTINGS] CANCEL!"));
    _menuOption = FIRST_MENU_OPTION;
    ScreenSettings::printMenuOption();
}

void ScreenSettings::doShortPressActionLeft()
{
    debugger.println(F("[SETTINGS] LEFT!"));
    _menuOption--;
    if (_menuOption < FIRST_MENU_OPTION)
    {
        _menuOption = FIRST_MENU_OPTION;
    }
    ScreenSettings::printMenuOption();
}

void ScreenSettings::doShortPressActionRight()
{
    debugger.println(F("[SETTINGS] RIGHT!"));
    _menuOption++;
    if (_menuOption > LAST_MENU_OPTION)
    {
        _menuOption = LAST_MENU_OPTION;
    }
    ScreenSettings::printMenuOption();
}

// -----------------------------------------------------------------------------
// Long Press Actions

void ScreenSettings::doLongPressActionEnter()
{
    debugger.println(F("[SETTINGS] LONG ENTER!"));
}

void ScreenSettings::doLongPressActionCancel()
{
    debugger.println(F("[SETTINGS] LONG CANCEL!"));
}

void ScreenSettings::doLongPressActionLeft()
{
    debugger.println(F("[SETTINGS] LONG LEFT!"));
}

void ScreenSettings::doLongPressActionRight()
{
    debugger.println(F("[SETTINGS] LONG RIGHT!"));
}

// -----------------------------------------------------------------------------
// Core Functions

void ScreenSettings::printMenuOption()
{
    Serial.print(F("Option: "));
    Serial.println(_menuOption);
    Serial.println();
}

void ScreenSettings::setCallback(function<void(SCREEN_NUMBER)> callback)
{
    this->callback = callback;
}

void ScreenSettings::registerFunctions()
{
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

ScreenSettings::ScreenSettings()
{
    debugger.println(F("[SETTINGS] Loaded!"));
    debugger.println();

    registerFunctions();
}
