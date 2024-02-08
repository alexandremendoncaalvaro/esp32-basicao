#include "main.h"

void setup()
{
  debugger.setDebug(true);
  SerialBegin();
  _initializeServices();
}

void loopCoreProtocol()
{
  inputInterface.handleInputs();
}

void loopCoreApp()
{
  delay(500);
}

// -----------------------------------------------------------------------------

void _initializeServices()
{
  if (
      !dualCore.begin() ||
      !oled.begin() ||
      !screenManager.begin())
  {
    reboot();
  }
}