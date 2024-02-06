#include "ScreenManager.h"

bool ScreenManager::begin()
{
    inputInterface.begin();
    debugger.println(F("[SCREEN_MANAGER] Starting Screen Manager..."));
    setScreen(SCREEN_NUMBER::MAIN_MENU);
    debugger.println(F("[SCREEN_MANAGER] Screen Manager Ok!"));
    debugger.println();
    return true;
}

void ScreenManager::applyScreen()
{
    inputInterface.setShortPressCommands(_screen->shortPressCommands);
    inputInterface.setLongPressCommands(_screen->longPressCommands);
    _screen->setCallback([&](SCREEN_NUMBER screen)
                         { screenManager.setScreen(screen); });
}

void ScreenManager::setScreen(SCREEN_NUMBER screen)
{
    if (screen == SCREEN_NUMBER::MAIN_MENU)
    {
        _screen = new MainMenu();
    }
    else if (screen == SCREEN_NUMBER::SETTINGS)
    {
        debugger.println(F("[SCREEN_MANAGER] Setting Screen: SETTINGS"));
    }

    if (_screen != nullptr)
    {
        applyScreen();
    }
}

ScreenManager screenManager;