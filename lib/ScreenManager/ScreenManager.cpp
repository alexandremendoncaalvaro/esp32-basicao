#include "ScreenManager.h"

bool ScreenManager::begin()
{
    inputInterface.begin();
    debugger.println(F("[SCREEN_MANAGER] Starting Screen Manager..."));
    setScreen(mainMenu);
    debugger.println(F("[SCREEN_MANAGER] Screen Manager Ok!"));
    debugger.println();
    return true;
}

void ScreenManager::setScreen(Screen &screen)
{
    inputInterface.setShortPressCommands(screen.shortPressCommands);
    inputInterface.setLongPressCommands(screen.longPressCommands);
}

ScreenManager screenManager;