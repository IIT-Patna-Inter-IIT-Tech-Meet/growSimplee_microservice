## Important Libraries
- `#include <Wire.h>` -> Library for I2C communication
- `#include <Adafruit_GFX.h>` -> Library for graphics
- `#include <Adafruit_SSD1306.h>` -> Library for the display

## PIN Connection
- Vin -> 3.3v
- GND -> ground
- SCL-> GPIO 22
- SDA -> GPIO 21

## Methods
- `display.clearDisplay();` -> Sets every pixels to zero
- `display.setTextSize(1);` -> Sets the text size to 1
- `display.setCursor(0, 10);` -> Sets the cursor to the position (0, 10)
- `display.setTextColor(WHITE);` -> Sets the text color to white
- `display.println("Hello World!");` -> Prints the text "Hello World!" on the display
- `display.display();` -> Updates the display
- `startscrollright(0x00, 0x0F)` -> Scrolls the display from left to right
- `startscrollleft(0x00, 0x0F)` -> Scrolls the display from right to left
- `startscrolldiagright(0x00, 0x07)` -> Scrolls the display from left bottom Corner to right top Corner
- `startscrolldiagleft(0x00, 0x07)` -> Scrolls the display from right bottom Corner to left top Corner
- `display.stopscroll();` -> Stops the scrolling
- `display.drawPixel(64, 32, WHITE);` -> Draws a pixel at the position (64, 32)
- `display.drawLine(0, 0, 127, 20, WHITE);` -> Draws a line from (0, 0) to (127, 20)
- `display.drawRect(10, 10, 50, 30, WHITE);` -> Draws a rectangle with the top left corner at (10, 10) and the width and height of 50 and 30
- `display.drawRoundRect(10, 10, 30, 50, 2, WHITE);` -> Draws a rectangle with the top left corner at (10, 10) and the width and height of 30 and 50 and a radius of 2
- `display.fillRoundRect(10, 10, 30, 50, 2, WHITE);` -> Draws a filled rectangle with rounded corners  
- `display.drawCircle(64, 32, 10, WHITE);` -> Draws a circle 
- `display.fillCircle(64, 32, 10, WHITE);` -> Draws a filled circle
- `display.drawTriangle(10, 10, 55, 20, 5, 40, WHITE);` -> Draws a triangle
- `display.fillTriangle(10, 10, 55, 20, 5, 40, WHITE);` -> Draws a filled triangle
- `display.invertDisplay(true);` -> Inverts the display


### Setting other fonts
- `#include <Fonts/FreeSerif12pt7b.h>` -> includes the font
- `display.setFont(&FreeSerif12pt7b);` -> Update the fonts
