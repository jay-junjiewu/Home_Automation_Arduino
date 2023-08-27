#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "graphics.h"   // Colours & graphics functions
#include "touch.h"      // Touch functions

#include "alarm.h" // Alarm Mode Variables & Functions

int alarm_hour = 7;				//time for alarm
int alarm_minute = 30;
int alarm_state = 0; 				// 0 when off, 1 when on

// Flag whether the Alarm Screen is initially filled: 1 means filled
int alarm_fill = 0;

// "Main" function for Alarms Page
void custom_alarm_page(int x, int y)
{
	if(alarm_fill == 0) {
		draw_alarm();
		button_switch(alarm_state, 180, 103); 
    alarm_time_box(80, 100, alarm_hour, alarm_minute);
    alarm_fill = 1;
	}

  // Button 1
  if(chk_btn_rec(43,140,74,170,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 1);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 4
  if(chk_btn_rec(43,180,74,210,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 4);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 7
  if(chk_btn_rec(43,220,74,250,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 7);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 2
  if(chk_btn_rec(105,140,136,170,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 2);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 5
  if(chk_btn_rec(105,180,136,210,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 5);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 8
  if(chk_btn_rec(105,220,136,250,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 8);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 0
  if(chk_btn_rec(105,260,136,290,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 0);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 3
  if(chk_btn_rec(167,140,198,170,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 3);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 6
  if(chk_btn_rec(167,180,198,210,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 6);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button 9
  if(chk_btn_rec(167,220,198,250,x,y)) {
		alarm_shift(&alarm_hour, &alarm_minute, 9);
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}
  // Button AC
  if(chk_btn_rec(167,260,198,290,x,y)) {
		alarm_hour = 0;
    alarm_minute = 0;
    alarm_change_time(80, 100, alarm_hour, alarm_minute);
	}

  // ON/OFF button
  if(chk_btn_rec(180-18,103-18,180+18,103+18,x,y) && !(alarm_hour >= 24 || alarm_minute >= 60)){
    alarm_state = !alarm_state;
    button_switch(alarm_state, 180, 103);
  }

  // Checks for valid time
  if (alarm_hour >= 24 || alarm_minute >= 60) {
    show_string("INVALID", 72, 125, 1, RED, RGBENC(247, 251, 255), 1);
	} else {
    my_lcd.Set_Draw_color(RGBENC(247, 251, 255));
    my_lcd.Fill_Rectangle(70,125,130,140); 
	}	

  //return to main button
  if(chk_btn_rec(10,290,50,310,x,y))
  {
    if(alarm_hour >= 24 || alarm_minute >= 60) {
				alarm_state = 0;
		}
    page = menu;
    alarm_fill = 0;
  } 
}

// Draws the elements of Alarm Screen, text and number buttons
void draw_alarm() 
{
  my_lcd.Fill_Screen(RGBENC(247, 251, 255)); //Light blue background
  show_string("Alarm", 90, 25, 2, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Time set", 35, 70, 1, BLACK, RGBENC(247, 251, 255), 1);

  my_lcd.Set_Draw_color(LIGHT_GRAY);

  // Draw Button Pad
  my_lcd.Fill_Round_Rectangle(43,140,74,170,10); 
  show_string("1", 43+14, 140+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(43,180,74,210,10); 
  show_string("4", 43+14, 180+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(43,220,74,250,10); 
  show_string("7", 43+14, 220+12, 1, BLACK, LIGHT_GRAY, 1);  

  my_lcd.Fill_Round_Rectangle(105,140,136,170,10); 
  show_string("2", 105+14, 140+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(105,180,136,210,10); 
  show_string("5", 105+14, 180+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(105,220,136,250,10); 
  show_string("8", 105+14, 220+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(105,260,136,290,10); 
  show_string("0", 105+14, 260+12, 1, BLACK, LIGHT_GRAY, 1);

  my_lcd.Fill_Round_Rectangle(167,140,198,170,10); 
  show_string("3", 167+14, 140+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(167,180,198,210,10); 
  show_string("6", 167+14, 180+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(167,220,198,250,10); 
  show_string("9", 167+14, 220+12, 1, BLACK, LIGHT_GRAY, 1);
  my_lcd.Fill_Round_Rectangle(167,260,198,290,10); 
  show_string("AC", 167+11, 260+12, 1, BLACK, LIGHT_GRAY, 1);

	draw_return();
}

// Shifts the alarm numbers one place to the right
void alarm_shift(int *timeh, int *timem, int number) 
{
	*timeh = *timeh * 10;
	*timeh = *timeh + *timem / 10;
	*timeh = *timeh % 100;
	
	*timem = *timem * 10;
	*timem = *timem + number;
	*timem = *timem % 100;
}

// Draws a alarm time box border then calls change_time()
void alarm_time_box(int x, int y, int hours, int minutes)
{
  // Time Border
  my_lcd.Set_Draw_color(BLACK);
  my_lcd.Fill_Rectangle(x-10,y-11,x+38,y+19);
  alarm_change_time(x, y, hours, minutes);
}

// Draws white background inside border and adds the alarm time
void alarm_change_time(int x, int y, int hours, int minutes)
{
  char str[10];   // Placeholder used to display time as a string
  my_lcd.Set_Draw_color(WHITE);
  my_lcd.Fill_Rectangle(x-7,y-8,x+35,y+16);
  sprintf(str, "%d:%d0", hours, minutes/10);
  sprintf(str, "%d%d:%d%d  ", hours/10, hours%10, minutes/10, minutes%10);
  show_string(str, x, y, 1, BLACK, WHITE, 1);
}
