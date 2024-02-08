#include "ScreenManager.h"

bool ScreenManager::begin()
{
    inputInterface.begin();
    debugger.println(F("[SCREEN MANAGER] Starting Screen Manager..."));
    setScreen(SCREEN_NUMBER::MAIN_MENU);
    debugger.println(F("[SCREEN MANAGER] Screen Manager Ok!"));
    debugger.println();
    return true;
}

void ScreenManager::applyScreen()
{
    inputInterface.setShortPressCommands(_screen->shortPressCommands);
    inputInterface.setLongPressCommands(_screen->longPressCommands);
    debugger.println();
    _screen->setCallback([&](SCREEN_NUMBER screen)
                         { screenManager.setScreen(screen); });
}

void ScreenManager::setScreen(SCREEN_NUMBER screen)
{
    switch (screen)
    {
    case SCREEN_NUMBER::MAIN_MENU:
        _screen = new ScreenMainMenu();
        break;
    case SCREEN_NUMBER::SETTINGS:
        _screen = new ScreenSettings();
        break;

    default:
        break;
    }

    if (_screen != nullptr)
    {
        applyScreen();
    }
}

ScreenManager screenManager;