#pragma once

#include <Arduino.h>
#include "BasicSettings.h"
#include "Debugger.h"
#include "DualCore.h"
#include "Duration.h"
#include "Oled.h"
#include "InputInterface.h"

void loopCoreProtocol();
void loopCoreApp();
void _initializeServices();

DualCore dualCore(loopCoreProtocol, loopCoreApp);

void loop() {}
