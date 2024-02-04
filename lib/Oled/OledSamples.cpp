#include "Oled.h"

void Oled::testDrawline()
{
    int16_t i;

    display.clearDisplay(); // Clear display buffer

    for (i = 0; i < display.width(); i += 4)
    {
        display.drawLine(0, 0, i, display.height() - 1, WHITE);
        display.display(); // Update screen with each newly-drawn line
        delay(1);
    }
    for (i = 0; i < display.height(); i += 4)
    {
        display.drawLine(0, 0, display.width() - 1, i, WHITE);
        display.display();
        delay(1);
    }
    delay(250);

    display.clearDisplay();

    for (i = 0; i < display.width(); i += 4)
    {
        display.drawLine(0, display.height() - 1, i, 0, WHITE);
        display.display();
        delay(1);
    }
    for (i = display.height() - 1; i >= 0; i -= 4)
    {
        display.drawLine(0, display.height() - 1, display.width() - 1, i, WHITE);
        display.display();
        delay(1);
    }
    delay(250);

    display.clearDisplay();

    for (i = display.width() - 1; i >= 0; i -= 4)
    {
        display.drawLine(display.width() - 1, display.height() - 1, i, 0, WHITE);
        display.display();
        delay(1);
    }
    for (i = display.height() - 1; i >= 0; i -= 4)
    {
        display.drawLine(display.width() - 1, display.height() - 1, 0, i, WHITE);
        display.display();
        delay(1);
    }
    delay(250);

    display.clearDisplay();

    for (i = 0; i < display.height(); i += 4)
    {
        display.drawLine(display.width() - 1, 0, 0, i, WHITE);
        display.display();
        delay(1);
    }
    for (i = 0; i < display.width(); i += 4)
    {
        display.drawLine(display.width() - 1, 0, i, display.height() - 1, WHITE);
        display.display();
        delay(1);
    }

    delay(2000); // Pause for 2 seconds
}

void Oled::testDrawrect(void)
{
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2; i += 2)
    {
        display.drawRect(i, i, display.width() - 2 * i, display.height() - 2 * i, WHITE);
        display.display(); // Update screen with each newly-drawn rectangle
        delay(1);
    }

    delay(2000);
}

void Oled::testFillrect(void)
{
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2; i += 3)
    {
        // The INVERSE color is used so rectangles alternate white/black
        display.fillRect(i, i, display.width() - i * 2, display.height() - i * 2, INVERSE);
        display.display(); // Update screen with each newly-drawn rectangle
        delay(1);
    }

    delay(2000);
}

void Oled::testDrawcircle(void)
{
    display.clearDisplay();

    for (int16_t i = 0; i < max(display.width(), display.height()) / 2; i += 2)
    {
        display.drawCircle(display.width() / 2, display.height() / 2, i, WHITE);
        display.display();
        delay(1);
    }

    delay(2000);
}

void Oled::testFillcircle(void)
{
    display.clearDisplay();

    for (int16_t i = max(display.width(), display.height()) / 2; i > 0; i -= 3)
    {
        // The INVERSE color is used so circles alternate white/black
        display.fillCircle(display.width() / 2, display.height() / 2, i, INVERSE);
        display.display(); // Update screen with each newly-drawn circle
        delay(1);
    }

    delay(2000);
}

void Oled::testDrawroundrect(void)
{
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2 - 2; i += 2)
    {
        display.drawRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i,
                              display.height() / 4, WHITE);
        display.display();
        delay(1);
    }

    delay(2000);
}

void Oled::testFillroundrect(void)
{
    display.clearDisplay();

    for (int16_t i = 0; i < display.height() / 2 - 2; i += 2)
    {
        // The INVERSE color is used so round-rects alternate white/black
        display.fillRoundRect(i, i, display.width() - 2 * i, display.height() - 2 * i,
                              display.height() / 4, INVERSE);
        display.display();
        delay(1);
    }

    delay(2000);
}

void Oled::testDrawtriangle(void)
{
    display.clearDisplay();

    for (int16_t i = 0; i < max(display.width(), display.height()) / 2; i += 5)
    {
        display.drawTriangle(
            display.width() / 2, display.height() / 2 - i,
            display.width() / 2 - i, display.height() / 2 + i,
            display.width() / 2 + i, display.height() / 2 + i, WHITE);
        display.display();
        delay(1);
    }

    delay(2000);
}

void Oled::testFilltriangle(void)
{
    display.clearDisplay();

    for (int16_t i = max(display.width(), display.height()) / 2; i > 0; i -= 5)
    {
        // The INVERSE color is used so triangles alternate white/black
        display.fillTriangle(
            display.width() / 2, display.height() / 2 - i,
            display.width() / 2 - i, display.height() / 2 + i,
            display.width() / 2 + i, display.height() / 2 + i, INVERSE);
        display.display();
        delay(1);
    }

    delay(2000);
}

void Oled::testDrawchar(void)
{
    display.clearDisplay();

    display.setTextSize(1);      // Normal 1:1 pixel scale
    display.setTextColor(WHITE); // Draw white text
    display.setCursor(0, 0);     // Start at top-left corner
    display.cp437(true);         // Use full 256 char 'Code Page 437' font

    // Not all the characters will fit on the display. This is normal.
    // Library will draw what it can and the rest will be clipped.
    for (int16_t i = 0; i < 256; i++)
    {
        if (i == '\n')
            display.write(' ');
        else
            display.write(i);
    }

    display.display();
    delay(2000);
}

void Oled::testDrawstyles(void)
{
    display.clearDisplay();

    display.setTextSize(1);      // Normal 1:1 pixel scale
    display.setTextColor(WHITE); // Draw white text
    display.setCursor(0, 0);     // Start at top-left corner
    display.println(F("Hello, world!"));

    display.setTextColor(BLACK, WHITE); // Draw 'inverse' text
    display.println(3.141592);

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.print(F("0x"));
    display.println(0xDEADBEEF, HEX);

    display.display();
    delay(2000);
}

void Oled::testScrolltext(void)
{
    display.clearDisplay();

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(10, 0);
    display.println(F("scroll"));
    display.display(); // Show initial text
    delay(100);

    // Scroll in various directions, pausing in-between:
    display.startscrollright(0x00, 0x0F);
    delay(2000);
    display.stopscroll();
    delay(1000);
    display.startscrollleft(0x00, 0x0F);
    delay(2000);
    display.stopscroll();
    delay(1000);
    display.startscrolldiagright(0x00, 0x07);
    delay(2000);
    display.startscrolldiagleft(0x00, 0x07);
    delay(2000);
    display.stopscroll();
    delay(1000);
}
