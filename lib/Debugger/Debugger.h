#pragma once

#include <Arduino.h>

class Debugger
{
private:
    bool _debug = false;

public:
    size_t print(const __FlashStringHelper *message);
    size_t print(const String &message);
    size_t print(char character);
    size_t print(int number);
    size_t print(double number);
    size_t print(float number);

    size_t println(const __FlashStringHelper *message);
    size_t println(const String &message);
    size_t println(char character);
    size_t println(int number);
    size_t println(double number, int digits = 2);
    size_t println(float number, int digits = 2);
    size_t println();

    void setDebug(bool debug) { _debug = debug; }
    bool getDebug() { return _debug; }
};

extern Debugger debugger;
