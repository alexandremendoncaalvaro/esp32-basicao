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

    void testDrawline();      // Draw many lines
    void testDrawrect();      // Draw rectangles (outlines)
    void testFillrect();      // Draw rectangles (filled)
    void testDrawcircle();    // Draw circles (outlines)
    void testFillcircle();    // Draw circles (filled)
    void testDrawroundrect(); // Draw rounded rectangles (outlines)
    void testFillroundrect(); // Draw rounded rectangles (filled)
    void testDrawtriangle();  // Draw triangles (outlines)
    void testFilltriangle();  // Draw triangles (filled)
    void testDrawchar();      // Draw characters of the default font
    void testDrawstyles();    // Draw 'stylized' characters
    void testScrolltext();    // Draw scrolling text

public:
    bool begin();
    void print(String text);
};

extern Oled oled;