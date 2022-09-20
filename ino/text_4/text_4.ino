
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
#define IWIDTH  270
#define IHEIGHT 135
TFT_eSprite img = TFT_eSprite(&tft);
//----------------------------------------


void setup(){
  
  pinMode(PWR_ON, OUTPUT);
  digitalWrite(PWR_ON, 1);
  pinMode(TFT_BL, OUTPUT);
  analogWrite(TFT_BL, 0);
  pinMode(RedLED, OUTPUT);
  pinMode(BatVol, INPUT);
  pinMode(BOTTON2,INPUT);


  adc_init();
  adc_gpio_init(26);
  adc_select_input(0);
  tft.init();
  tft.setRotation(1);                     //向き
  
  img.setTextSize(3);                     //sprite
  img.setTextFont(7);                     //sprite
  
  tft.setSwapBytes(true);
  delay(25);
  analogWrite(TFT_BL, 255);               //Back Light


  Serial.begin(115200);
  Serial.println("Hello Pico");

//------------------------------------202209
  img.createSprite(IWIDTH, IHEIGHT);
  img.fillSprite(TFT_BLACK);
//------------------------------------

  img.setTextColor(0xc618);
  img.pushSprite(0, 0);
}

void loop(){


if (!digitalRead(BOTTON2)){
      img.setTextColor(random(TFT_WHITE));
      Serial.println("Hello Pico");
  }

//    tft.setTextColor(random(TFT_WHITE));

  img.fillSprite(TFT_BLACK);
  img.setCursor (-22, -3);
  img.setTextSize(3);img.print("14.");
    img.setCursor (203, 40);
    img.setTextSize(2);img.print("6");
  img.pushSprite(-22, -3);

digitalWrite(RedLED, !digitalRead(RedLED));
delay(500);


  img.fillSprite(TFT_BLACK);
  img.setCursor (-22,-3);
  img.setTextSize(3);img.print("15.");
    img.setCursor (203,40);
    img.setTextSize(2);img.print("7");
  img.pushSprite(-22,-3);

digitalWrite(RedLED, !digitalRead(RedLED));
delay(500);

}
