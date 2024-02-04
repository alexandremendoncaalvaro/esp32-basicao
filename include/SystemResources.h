#pragma once

#include <Arduino.h>
#include "Debugger.h"

namespace SystemResources
{
    void reboot()
    {
        debugger.println(F("[SYSTEM] Rebooting..."));
        esp_restart();
    };

    void SerialBegin(unsigned long baudrate = 115200)
    {
        Serial.begin(baudrate);
        debugger.println();
        debugger.println(F("[SYSTEM] SYSTEM STARTED ########################################################"));
        debugger.println(F("[SYSTEM] Serial Ok!"));
        debugger.println();
    }

} // namespace SystemResources