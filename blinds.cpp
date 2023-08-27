#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "graphics.h"   // Colours & graphics functions
#include "touch.h"      // Touch functions

#include "blinds.h" // Blinds Mode Variables & Functions

int blindUp_hour = 7;				//time for blinds to go up
int blindUp_minute = 30;
int blindDown_hour = 18;		//time for blinds to go down
int blindDown_minute = 30;
int blind_state = 0; 				// 0 when off, 1 when on

// Flag whether the Blinds Screen is initially filled: 1 means filled
int blinds_fill = 0;

// "Main" function for Sprinkler Page
void custom_blinds_page(int x, int y)
{
	if(blinds_fill == 0) {
		draw_blinds();
		button_switch(blind_state, 76, 130); 
		blinds_fill = 1;
	}
  
  // Change up time hour
  if(chk_btn_rec(68-2,220-8,68+40,220+16,x,y)){
    time_increment(&blindUp_hour, &blindUp_minute);
    change_time(68,220, blindUp_hour,blindUp_minute);
  } 

  // Change down time hour
  if(chk_btn_rec(165,212,207,236,x,y)){
    time_increment(&blindDown_hour, &blindDown_minute);
    change_time(167,220, blindDown_hour,blindDown_minute);
  } 

  // ON/OFF button
  if(chk_btn_rec(58,112,94,148,x,y)){
    blind_state = !blind_state;
    button_switch(blind_state, 76, 130);
  }

  //return to main button
  if(chk_btn_rec(10,290,50,310,x,y))
  {
    page = menu;
    blinds_fill = 0;
  } 
}

// Draws the elements of Blinds Screen, text and timebox
void draw_blinds() 
{
  my_lcd.Fill_Screen(RGBENC(247, 251, 255)); //Light blue background
  show_string("Blinds", 90, 25, 2, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Switch", 35, 80, 1, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Time Setting", 35, 180, 1, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Up", 38, 220, 1, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Down", 127, 220, 1, BLACK, RGBENC(247, 251, 255), 1);

  time_box(68,220, blindUp_hour,blindUp_minute);
  time_box(167,220, blindDown_hour,blindDown_minute);

	draw_return();
}
