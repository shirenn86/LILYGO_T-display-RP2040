

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

// Include the header files that contain the icons
#include "Alert.h"
#include "Close.h"
#include "Info.h"

long count = 0; // Loop count


///////////////////////config
#define TFT_BL 4
#define PWR_ON 22
///////////////////////


void setup()
{
/////////////////////////
  pinMode(PWR_ON, OUTPUT);
  digitalWrite(PWR_ON, 1);
  pinMode(TFT_BL, OUTPUT);
  analogWrite(TFT_BL, 255);
//////////////////////////
  
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);	// landscape

  tft.fillScreen(TFT_BLACK);

  // Swap the colour byte order when rendering
  tft.setSwapBytes(true);

  // Draw the icons
  tft.pushImage(100, 100, infoWidth, infoHeight, info);
  tft.pushImage(140, 100, alertWidth, alertHeight, alert);
  tft.pushImage(180, 100, closeWidth, closeHeight, closeX);

  // Pause here to admire the icons!
  delay(2000);

}

void loop()
{
  // Loop filling and clearing screen
  tft.pushImage(random(tft.width() -  infoWidth), random(tft.height() -  infoHeight),  infoWidth,  infoHeight, info);
  tft.pushImage(random(tft.width() - alertWidth), random(tft.height() - alertHeight), alertWidth, alertHeight, alert);
  tft.pushImage(random(tft.width() - closeWidth), random(tft.height() - closeHeight), alertWidth, closeHeight, closeX);

  // Clear screen after 100 x 3 = 300 icons drawn
  if (1000 == count++) {
    count = 1;
    tft.setRotation(2 * random(2)); // Rotate randomly to clear display left>right or right>left to reduce monotony!
    tft.fillScreen(TFT_BLACK);
    tft.setRotation(3);
    delay(500);
  }
}
