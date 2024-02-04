#pragma once

#include <Arduino.h>
#include "Duration.h"

class PulseButton
{
public:
    PulseButton(
        uint8_t pin,
        Milliseconds longPressDelay = 2000_ms,
        Milliseconds debounceDelay = 50_ms);
    void update();
    bool isShortPressed();
    bool isLongPressed();
    uint8_t getPin();

private:
    static const uint8_t BUTTON_PRESSED = LOW;
    static const uint8_t BUTTON_RELEASED = HIGH;

    bool _shortPressAcknowledged;
    bool _longPressAcknowledged;
    bool _isLongPressAchieved;

    uint8_t _pin;
    uint8_t _readingState;
    uint8_t _lastReadingState;

    Milliseconds _pressTime;
    Milliseconds _lastDebounceTime;
    Milliseconds _longPressDelay;
    Milliseconds _debounceDelay;
};