#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Debugger.h"

class Oled
{
private:
    const int SCREEN_WIDTH = 128;
    const int SCREEN_HEIGHT = 64;
    const int OLED_RESET = -1;

    Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

    void testdrawline();      // Draw many lines
    void testdrawrect();      // Draw rectangles (outlines)
    void testfillrect();      // Draw rectangles (filled)
    void testdrawcircle();    // Draw circles (outlines)
    void testfillcircle();    // Draw circles (filled)
    void testdrawroundrect(); // Draw rounded rectangles (outlines)
    void testfillroundrect(); // Draw rounded rectangles (filled)
    void testdrawtriangle();  // Draw triangles (outlines)
    void testfilltriangle();  // Draw triangles (filled)
    void testdrawchar();      // Draw characters of the default font
    void testdrawstyles();    // Draw 'stylized' characters
    void testscrolltext();    // Draw scrolling text

public:
    bool begin();
    void print(String text);
};

extern Oled oled;