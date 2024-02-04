#include "main.h"

using namespace SystemResources;

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
  if (!dualCore.begin() ||
      !inputInterface.begin() ||
      !oled.begin())
  {
    reboot();
  }
}