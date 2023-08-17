#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "autonomous.h" // Autonomous Mode Variables & Functions
#include "graphics.h"   // Colours & graphics functions
#include "touch.h"      // Touch functions

int auto_mode = 0;
int current_state_y = 240;
int next_state_y = 110;

// "Main" function for Autonomous Page
void autonomous_page (int x, int y, int *current_state_y, int *next_state_y, int *auto_mode)
{
	switch_state(x, y, current_state_y, next_state_y, auto_mode);
        
	//return to n=menu button
	/*if(chk_btn_rect(x,y,10,290,50,310)){
		*page = menu;
		*fill = 0;
	} */
}

//ATTEMPTS to change the state of autonomous system
void switch_state(int x, int y, int *current_state_y, int *next_state_y, int *auto_mode) 
{
  int temp;
	// Switch state if it the distance is within square hitbox
  // Button is at center of screen: x_coord = 240/2 = 120
  // (55/sqrt(2) + 55) / 2 = 47
  if (chk_btn_rec(120-47, *next_state_y-47, 120+47, *next_state_y+47, x, y)) {
    // Switch Modes
    *auto_mode = !(*auto_mode);

    // Switch States
		temp = *current_state_y;
		*current_state_y = *next_state_y;
		*next_state_y = temp;

    draw_auto_mode(*auto_mode);
	}
}

// Draws the Autonomous System Screen
void draw_auto(int auto_mode) 
{
	my_lcd.Fill_Screen(RGBENC(247, 251, 255)); //Light blue background

  show_string("Automated System",75,25, 1 ,BLACK, RGBENC(247, 251, 255),1);
	
  draw_auto_mode(auto_mode);
}

// Draws Buttons Only
void draw_auto_mode(int auto_mode) 
{
	if(auto_mode) {
		//ON
    my_lcd.Set_Draw_color(BLUE);
		my_lcd.Fill_Circle(120,110,55); // Blue ON button

    my_lcd.Set_Draw_color(RGBENC(255, 220, 220));
		my_lcd.Fill_Circle(120,240,55); //Red OFF button

    show_string("ON",115,107,1,WHITE, BLUE,1);
    show_string("OFF",115,237,1,WHITE, RGBENC(255, 220, 220),1);
	} else {
		//OFF
    my_lcd.Set_Draw_color(RGBENC(232, 243, 255));
		my_lcd.Fill_Circle(120,110,55); // Blue ON button

    my_lcd.Set_Draw_color(RED);
		my_lcd.Fill_Circle(120,240,55); //Red OFF button

    show_string("ON",115,107,1,WHITE, RGBENC(232, 243, 255),1);
    show_string("OFF",115,237,1,WHITE, RED,1);
	}

	my_lcd.Set_Draw_color(BLUE);
	my_lcd.Draw_Circle(120,110,55);   // Blue border
	my_lcd.Draw_Circle(120,110,55-1); // Blue border
	my_lcd.Draw_Circle(120,110,55-2); // Blue border

  my_lcd.Set_Draw_color(RED);
	my_lcd.Draw_Circle(120,240,55);   //Red border
	my_lcd.Draw_Circle(120,240,55-1); //Red border
	my_lcd.Draw_Circle(120,240,55-2); //Red border
}