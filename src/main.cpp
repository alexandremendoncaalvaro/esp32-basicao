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
      !screenManager.begin() ||
      !oled.begin() ||
      !dualCore.begin())
  {
    reboot();
  }
}