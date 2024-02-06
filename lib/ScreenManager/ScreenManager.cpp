#include "ScreenManager.h"

bool ScreenManager::begin()
{
    inputInterface.begin();
    debugger.println(F("[SCREEN_MANAGER] Starting Screen Manager..."));
    auto mainMenu = new MainMenu();
    setScreen(mainMenu);
    debugger.println(F("[SCREEN_MANAGER] Screen Manager Ok!"));
    debugger.println();
    return true;
}

void ScreenManager::applyScreen()
{
    inputInterface.setShortPressCommands(_screen->shortPressCommands);
    inputInterface.setLongPressCommands(_screen->longPressCommands);
}

void ScreenManager::setScreen(Screen *screen)
{
    _screen = screen;
    applyScreen();
    delete _screen;
}

ScreenManager screenManager;