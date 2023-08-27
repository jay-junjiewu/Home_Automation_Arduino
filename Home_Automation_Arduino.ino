/***********************************************************************************
*This program is an demo autonomous home system called "MEEBO"
*This demo was made for LCD modules with 8bit data port
*This program requires the LCDKIWI and Touchscreen library.

* File                : MEEBO_Arduino
* Hardware Environment: Arduino UNO&Mega2560
* Build Environment   : Arduino

*Set the pins to the correct ones for your development shield or breakout board.
*                  LCD_CS  LCD_CD  LCD_WR  LCD_RD  LCD_RST  SD_SS  SD_DI  SD_DO  SD_SCK 
*     Arduino Uno    A3      A2      A1      A0      A4      10     11     12      13                            
*Arduino Mega2560    A3      A2      A1      A0      A4      10     11     12      13                           

*                  LCD_D0  LCD_D1  LCD_D2  LCD_D3  LCD_D4  LCD_D5  LCD_D6  LCD_D7  
*     Arduino Uno    8       9       2       3       4       5       6       7
*Arduino Mega2560    8       9       2       3       4       5       6       7 
*
**********************************************************************************/
#include <TouchScreen.h>    // Touch library
#include <LCDWIKI_GUI.h>    // Core graphics library
#include <LCDWIKI_KBV.h>    // Hardware-specific library

#include "initial.h"        // Initial Declarations
#include "graphics.h"       // Colours & graphics functions
#include "touch.h"          // Touch functions

#include "autonomous.h"     // Autonomous Mode Variables & Functions
#include "menu.h"           // Menu Mode Variables & Functions
#include "custom_lights.h"  // Lights Mode Variables & Functions
#include "sprinkler.h"      // Sprinkler Mode Variables & Functions
#include "blinds.h"         // Blinds Mode Variables & Functions
#include "alarm.h"          // Alarm Mode Variables & Functions
                    
void setup(void) 
{ 
  Serial.begin(9600);
  my_lcd.Init_LCD();
  Serial.println(my_lcd.Read_ID(), HEX);

  pinMode(13, OUTPUT);  // Sprinkler
  pinMode(A5, OUTPUT);  // Blinds

  // Colours: D10 is LSB, D12 is MSB for 3-8 MUX
  pinMode(10, OUTPUT);  
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  // Initially on Main Menu Screen
  draw_menu();
}

void loop(void)
{
  // Polls the touchscreen until it reads a potential touch
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

 if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
  {
    // x and y coordinates of the Registered Touch
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, my_lcd.Get_Display_Width());
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, my_lcd.Get_Display_Height());

    /*
    // Used to troubleshoot
    my_lcd.Set_Draw_color(BLACK);
    my_lcd.Draw_Pixel(p.x, p.y);
    */
		if (page == menu) {
			menu_page(p.x, p.y, &page);
		}
    if (page == autonomous) {
			autonomous_page(p.x, p.y);
      if(auto_mode == 0) {
        // Turn everything OFF when Autonomous Mode is OFF
        light_color = no_color;
        sprinkler_state = 0;
        blind_state = 0;
      }
		}
    if (page == custom_lights) {
			custom_light_page(p.x, p.y);
		}
    if (page == custom_sprinkler) {
			custom_sprinkler_page(p.x, p.y);
		}
    if (page == custom_blinds) {
			custom_blinds_page(p.x, p.y);
		}
    if (page == custom_alarm) {
			custom_alarm_page(p.x, p.y);
		}

    /*
     * If Autonomous Mode ON, all settings are default and cannot be changed
     * To change individual settings, turn OFF Autonomous Mode so 
     * that it is in "customisable mode"
     * 
     */
    if (auto_mode) {
      /*Autonomous Mode default settings:
          Light = Green (D10-12 = 100)
          Sprinkler ON (D13)
          Blinds ON {A5}
      */
      digitalWrite(10, LOW);  //100
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);

      digitalWrite(13, HIGH);
      digitalWrite(A5, HIGH);

    } else {
      switch(light_color)
      {
        case red:
          digitalWrite(10, HIGH); //001
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          break;
        case orange:
          digitalWrite(10, LOW);  //010
          digitalWrite(11, HIGH);
          digitalWrite(12, LOW);
          break;
        case yellow:
          digitalWrite(10, HIGH);  //011
          digitalWrite(11, HIGH);
          digitalWrite(12, LOW);
          break;
        case green:
          digitalWrite(10, LOW);  //100
          digitalWrite(11, LOW);
          digitalWrite(12, HIGH);
          break;
        case blue:
          digitalWrite(10, HIGH);  //101
          digitalWrite(11, LOW);
          digitalWrite(12, HIGH);
          break;
        case magenta:
          digitalWrite(10, LOW);  //110
          digitalWrite(11, HIGH);
          digitalWrite(12, HIGH);
          break;
        case no_color:
          digitalWrite(10, LOW);  //000
          digitalWrite(11, LOW);
          digitalWrite(12, LOW);
          break;
      }

      if(sprinkler_state) {
        digitalWrite(13, HIGH);
      } else {
        digitalWrite(13, LOW);
      }

      if(blind_state) {
        digitalWrite(A5, HIGH);
      } else {
        digitalWrite(A5, LOW);
      }
      
    }
    // Delay between touches
    delay(200);
  }
}
