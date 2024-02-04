#include "Oled.h"

bool Oled::begin()
{
    debugger.println(F("[OLED] Starting OLED..."));

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        debugger.println(F("[OLED] SSD1306 allocation failed"));
        return false;
    }
    display.clearDisplay();

    testdrawchar(); // Draw characters of the default font

    delay(2000);
    display.clearDisplay();

    display.display();

    debugger.println(F("[OLED] OLED Ok!"));
    debugger.println();

    return true;
}

void Oled::print(String text)
{
    display.clearDisplay();
    display.setTextSize(1); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(10, 0);
    display.println("LED STATUS");

    display.setTextSize(4); // Draw 2X-scale text
    display.setCursor(10, 18);
    display.println(text);
    display.display(); // Show initial text
}

Oled oled;