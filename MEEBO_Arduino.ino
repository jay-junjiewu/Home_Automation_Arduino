#include <TouchScreen.h> // Touch library
#include <LCDWIKI_GUI.h> // Core graphics library
#include <LCDWIKI_KBV.h> // Hardware-specific library

#include "initial.h"     // Initial Declarations
#include "autonomous.h"  // Autonomous Mode Variables & Functions
#include "graphics.h"    // Colours & graphics functions
#include "touch.h"       // Touch functions

// Different Pages that the LCD can be on
enum pages {
	autonomous,
	menu,
	custom_lights,
	custom_blinds,
	custom_sprinkler,
	custom_alarm
};

// Current Page of LCD
int	page = autonomous;
                    
void setup(void) 
{ 
  Serial.begin(9600);
  my_lcd.Init_LCD();
  Serial.println(my_lcd.Read_ID(), HEX);

  // Initially on Autonomous Screen
  draw_auto(auto_mode);
}

void loop(void)
{
  
  // Blinks LED to register a touch
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  digitalWrite(13, LOW);

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
			
    if (page == autonomous) {
			autonomous_page(p.x, p.y, &current_state_y, &next_state_y, &auto_mode);
		}

  }
}
