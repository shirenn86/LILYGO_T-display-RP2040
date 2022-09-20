
#include <TFT_eSPI.h> 
#include <stdio.h>
#include "hardware/adc.h"

/* 
#define TFT_MISO -1
#define TFT_MOSI 3
#define TFT_SCLK 2
#define TFT_CS 5  // Chip select control pin
#define TFT_DC 1  // Data Command control pin
#define TFT_RST 0 // Reset pin (could connect to RST pin) */
#define TFT_BL 4
#define PWR_ON 22
#define BOTTON1 6
#define BOTTON2 7
#define RedLED 25
#define BatVol 26

#define LOAD_FONT4

TFT_eSPI tft = TFT_eSPI();

//----------------------------------------202209
#define IWIDTH  240
#define IHEIGHT 135
TFT_eSprite img = TFT_eSprite(&tft);
//----------------------------------------


const float conversion_factor = 3.3f / (1 << 12);


void setup(){
  
  pinMode(PWR_ON, OUTPUT);
  digitalWrite(PWR_ON, 1);
  pinMode(TFT_BL, OUTPUT);
  analogWrite(TFT_BL, 0);
  pinMode(RedLED, OUTPUT);
  pinMode(BatVol, INPUT);

  Serial.begin(115200);   //115200
  adc_init();
  adc_gpio_init(26);
  adc_select_input(0);
  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);                     //向き
  img.setTextSize(2);
  img.setTextFont(7);
  tft.setSwapBytes(true);
  delay(25);
  analogWrite(TFT_BL, 255); 
  Serial.println("Hello Pico");

//------------------------------------202209
  img.createSprite(IWIDTH, IHEIGHT);
  img.fillSprite(TFT_BLACK);
//------------------------------------

  img.setTextColor(TFT_ORANGE);
  img.pushSprite(0, 0);
}

void loop(){
  
//    tft.fillScreen(TFT_BLACK);
//    tft.setCursor(0, 0);
//    tft.setTextColor(TFT_ORANGE);
//    tft.setTextColor(random(TFT_WHITE));
//    tft.print("14.6");

  img.fillSprite(TFT_BLACK);
  img.setCursor (0, 0);
  img.print("14.6");
  img.pushSprite(0, 0);
//  img.fillSprite(TFT_BLACK);


digitalWrite(RedLED, !digitalRead(RedLED));
delay(500);

  img.fillSprite(TFT_BLACK);
  img.setCursor (0, 0);
//  img.fillSprite(TFT_BLACK);
  img.print("14.7");
  img.pushSprite(0, 0);


//    tft.fillScreen(TFT_BLACK);
//    tft.setCursor(0, 0);tft.setTextColor(TFT_ORANGE);
//    tft.print("14.7");

digitalWrite(RedLED, !digitalRead(RedLED));
delay(500);

}
