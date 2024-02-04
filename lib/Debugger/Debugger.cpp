#include "Debugger.h"

size_t Debugger::print(const __FlashStringHelper *message)
{
    return _debug ? Serial.print(message) : 0;
}

size_t Debugger::print(const String &message)
{
    return _debug ? Serial.print(message) : 0;
}

size_t Debugger::print(char character)
{
    return _debug ? Serial.print(character) : 0;
}

size_t Debugger::print(int number)
{
    return _debug ? Serial.print(number) : 0;
}

size_t Debugger::print(double number)
{
    return _debug ? Serial.print(number) : 0;
}

size_t Debugger::print(float number)
{
    return _debug ? Serial.print(number) : 0;
}

size_t Debugger::println(const __FlashStringHelper *message)
{
    return _debug ? Serial.println(message) : 0;
}

size_t Debugger::println(const String &message)
{
    return _debug ? Serial.println(message) : 0;
}

size_t Debugger::println(char character)
{
    return _debug ? Serial.println(character) : 0;
}

size_t Debugger::println(int number)
{
    return _debug ? Serial.println(number) : 0;
}

size_t Debugger::println(double number, int digits)
{
    return _debug ? Serial.println(number, digits) : 0;
}

size_t Debugger::println(float number, int digits)
{
    return _debug ? Serial.println(number, digits) : 0;
}

size_t Debugger::println()
{
    return _debug ? Serial.println() : 0;
}

Debugger debugger;
