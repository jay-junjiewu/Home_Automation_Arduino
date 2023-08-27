#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "graphics.h"   // Colours & graphics functions

#include "touch.h"      // Touch functions

// Checks if LCD press is within a rectangle
int chk_btn_rec(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t px,int16_t py)
{
    if((px > x1 && px < x2) && (py > y1 && py < y2))
    {
      //press inside the rectangle
      return 1;  
    } 
    else
    {
      //press outside the rectangle
      return 0;  
    }
 }

// Draws the return box to take us back to Main Menu
 void draw_return(void)
 {
  my_lcd.Set_Draw_color(0x05E0); // Dark Green
  my_lcd.Fill_Round_Rectangle(10,290,50,310,5); 
  show_string("return", 12, 296, 1, BLACK, 0x05E0, 1);
}

// Takes in a time in 24 hour system and increments it by 30 min
void time_increment(int *hour, int *minute)
{
	if (*minute > 29) {
		*hour = *hour + 1;
		*minute = 0;
	}
	else {
		*minute = 30;
	}
	if (*hour >= 24) {
		*hour = 0;
	}
}

// Draws an ON/OFF button
void button_switch(int state, int x, int y) 
{
  // Button Border
  my_lcd.Set_Draw_color(BLACK);
	my_lcd.Fill_Circle(x,y,20);

	if (state == 0) {
    my_lcd.Set_Draw_color(DARK_GRAY);
	  my_lcd.Fill_Circle(x,y,18);
    show_string("OFF", x-7, y-3, 1, WHITE, DARK_GRAY, 1);
	}
	else {
    my_lcd.Set_Draw_color(GREEN);
	  my_lcd.Fill_Circle(x,y,18);
    show_string("ON", x-5, y-3, 1, BLACK, GREEN, 1);		
	}
}

// Draws a time box border then calls change_time()
void time_box(int x, int y, int hours, int minutes)
{
  // Time Border
  my_lcd.Set_Draw_color(BLACK);
  my_lcd.Fill_Rectangle(x-10,y-11,x+38,y+19);
  change_time(x, y, hours, minutes);
}

// Draws white background inside border and adds the time
void change_time(int x, int y, int hours, int minutes)
{
  char str[10];   // Placeholder used to display time as a string
  my_lcd.Set_Draw_color(WHITE);
  my_lcd.Fill_Rectangle(x-7,y-8,x+35,y+16);
  sprintf(str, "%d:%d0", hours, minutes/10);
  show_string(str, x, y, 1, BLACK, WHITE, 1);
}