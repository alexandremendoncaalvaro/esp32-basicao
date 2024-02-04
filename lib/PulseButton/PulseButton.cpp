#include "PulseButton.h"

PulseButton::PulseButton(
    uint8_t pin,
    Milliseconds longPressDelay,
    Milliseconds debounceDelay)
    : _pin(pin),
      _longPressDelay(longPressDelay),
      _debounceDelay(debounceDelay),
      _readingState(BUTTON_RELEASED),
      _lastReadingState(BUTTON_RELEASED),
      _lastDebounceTime(0_ms),
      _pressTime(0_ms),
      _shortPressAcknowledged(false),
      _longPressAcknowledged(false),
      _isLongPressAchieved(false)
{
    pinMode(_pin, INPUT_PULLUP);
}

void PulseButton::update()
{
    _shortPressAcknowledged = false;

    auto now = getMillis();
    uint8_t inputReading = (GPIO.in & (1 << _pin)) != 0;

    auto inputStateChanged = inputReading != _lastReadingState;
    if (inputStateChanged)
    {
        _pressTime = now;

        auto isDebounceTimeWindow = (now - _lastDebounceTime) <= _debounceDelay;
        _lastDebounceTime = now;

        if (isDebounceTimeWindow)
        {
            _lastReadingState = inputReading;
            return;
        }
    }

    auto isButtonPressed = inputReading == BUTTON_PRESSED;
    auto isButtonLastStateReleased = _lastReadingState == BUTTON_RELEASED;
    auto buttonChangeToPressed = isButtonPressed && isButtonLastStateReleased;

    _lastReadingState = inputReading;
    _pressTime = buttonChangeToPressed ? now : _pressTime;

    if (isButtonPressed)
    {
        _isLongPressAchieved = (now - _pressTime) >= _longPressDelay;
        return;
    }

    auto isButtonShortPressedReleased = !isButtonLastStateReleased && !_longPressAcknowledged;

    if (isButtonShortPressedReleased)
    {
        _shortPressAcknowledged = true;
    }

    _isLongPressAchieved = false;
    _longPressAcknowledged = false;
}

bool PulseButton::isShortPressed()
{
    auto result = _shortPressAcknowledged && !_longPressAcknowledged;
    return result;
}

bool PulseButton::isLongPressed()
{
    if (_isLongPressAchieved && !_longPressAcknowledged)
    {
        _longPressAcknowledged = true;
        return true;
    }
    return false;
}

uint8_t PulseButton::getPin()
{
    return _pin;
}
