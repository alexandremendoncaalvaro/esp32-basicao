#pragma once

#include <Arduino.h>
#include "core.h"
#include "Debugger.h"
#include "DualCore.h"
#include "Duration.h"
#include "Oled.h"
#include "Menu.h"

using namespace core;

void loopCoreProtocol();
void loopCoreApp();
void _initializeServices();

DualCore dualCore(loopCoreProtocol, loopCoreApp);

void loop() {}
