#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "graphics.h"   // Colours & graphics functions
#include "touch.h"      // Touch functions

#include "autonomous.h" // Autonomous Mode Variables & Functions

// Autonomous Home System State: 0 for OFF 1 for ON
int auto_mode = 0;
// Initially autonoous mode OFF, Y-coordinates of the button represents state system is on
int current_state_y = 240;
int next_state_y = 110;
// Flag whether the Autonomous Screen is initially filled: 1 means filled
int auto_fill = 0;

// "Main" function for Autonomous Page
void autonomous_page(int x, int y)
{
  if (auto_fill == 0) {
    draw_auto(auto_mode);
		auto_fill = 1;
	}

	switch_state(x, y);
        
	// Return to menu button
	if(chk_btn_rec(10,290,50,310,x,y)){
		page = menu;
    auto_fill = 0;
	}
}

//ATTEMPTS to change the state of autonomous system
void switch_state(int x, int y) 
{
  int temp;
	// Switch state if it the distance is within square hitbox
  // Button is at center of screen: x_coord = 240/2 = 120
  // (55/sqrt(2) + 55) / 2 = 47
  if (chk_btn_rec(120-47, next_state_y-47, 120+47, next_state_y+47, x, y)) {
    // Switch Modes
    auto_mode = !auto_mode;

    // Switch States
		temp = current_state_y;
		current_state_y = next_state_y;
		next_state_y = temp;

    draw_auto_mode(auto_mode);
	}
}

// Draws the Autonomous System Screen
void draw_auto(int mode) 
{
	my_lcd.Fill_Screen(RGBENC(247, 251, 255)); //Light blue background

  show_string("Automated System",25,25, 2 ,BLACK, RGBENC(247, 251, 255),1);
	
  draw_auto_mode(mode);

  draw_return();
}

// Draws Buttons Only
void draw_auto_mode(int mode) 
{
	if(mode) {
		//ON
    my_lcd.Set_Draw_color(BLUE);
		my_lcd.Fill_Circle(120,110,55); // Blue ON button

    my_lcd.Set_Draw_color(RGBENC(255, 220, 220));
		my_lcd.Fill_Circle(120,240,55); //Red OFF button

    show_string("ON",110,102,2,WHITE, BLUE,1);
    show_string("OFF",105,232,2,WHITE, RGBENC(255, 220, 220),1);
	} else {
		//OFF
    my_lcd.Set_Draw_color(RGBENC(232, 243, 255));
		my_lcd.Fill_Circle(120,110,55); // Blue ON button

    my_lcd.Set_Draw_color(RED);
		my_lcd.Fill_Circle(120,240,55); //Red OFF button

    show_string("ON",110,102,2,WHITE, RGBENC(232, 243, 255),1);
    show_string("OFF",105,232,2,WHITE, RED,1);
	}

	my_lcd.Set_Draw_color(BLUE);
	my_lcd.Draw_Circle(120,110,55);   // Blue border
	my_lcd.Draw_Circle(120,110,55-1);
	my_lcd.Draw_Circle(120,110,55-2);

  my_lcd.Set_Draw_color(RED);
	my_lcd.Draw_Circle(120,240,55);   //Red border
	my_lcd.Draw_Circle(120,240,55-1);
	my_lcd.Draw_Circle(120,240,55-2);
}
