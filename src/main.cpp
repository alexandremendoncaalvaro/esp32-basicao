#include "main.h"

void setup()
{
  using namespace BasicSettings;

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
  using namespace BasicSettings;

  if (!dualCore.begin() ||
      !inputInterface.begin() ||
      !oled.begin())
  {
    reboot();
  }
}