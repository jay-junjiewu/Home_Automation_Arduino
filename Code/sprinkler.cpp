#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "graphics.h"   // Colours & graphics functions
#include "touch.h"      // Touch functions

#include "sprinkler.h" // Sprinkler Mode Variables & Functions

int sprinkle_time = 2;    // Sprinkler Timer in Hours
int sprinkler_state = 0; 	// 0 when off, 1 when on

// Flag whether the Sprinkler Screen is initially filled: 1 means filled
int sprinkler_fill = 0;

// "Main" function for Sprinkler Page
void custom_sprinkler_page(int x, int y)
{
	if(sprinkler_fill == 0) {
		draw_sprinkler();
		button_switch(sprinkler_state, 180, 140); 
		sprinkler_fill = 1;
	}
  
  // Change time hour
  if(chk_btn_rec(53,132,95,156,x,y)){
    if(sprinkle_time < 23) {
      sprinkle_time = sprinkle_time + 1;
    }
    else {
      sprinkle_time = 0;
    }
    change_time(55,140, sprinkle_time,0);
  } 

  // ON/OFF button
  if(chk_btn_rec(162,122,198,158,x,y)){
    sprinkler_state = !sprinkler_state;
    button_switch(sprinkler_state, 180, 140);
  }

  //return to main button
  if(chk_btn_rec(10,290,50,310,x,y))
  {
    page = menu;
    sprinkler_fill = 0;
  } 
}

// Draws the elements of Sprinkler Screen, text and timebox
void draw_sprinkler() 
{
  my_lcd.Fill_Screen(RGBENC(247, 251, 255)); //Light blue background
  show_string("Sprinkler", 75, 25, 2, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Time", 35, 90, 1, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Duration", 35, 200, 1, BLACK, RGBENC(247, 251, 255), 1);
  show_string("15 minutes", 55, 230, 1, BLACK, RGBENC(247, 251, 255), 1);

  time_box(55,140,sprinkle_time,0);

	draw_return();
}
