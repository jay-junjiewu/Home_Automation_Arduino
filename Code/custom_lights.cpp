#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "graphics.h"   // Colours & graphics functions
#include "touch.h"      // Touch functions

#include "custom_lights.h" // Lights Mode Variables & Functions

// For slider at light sensor. value of intensity obtained with sliderx
int sliderx = 43;

int light_color = no_color;

// Lights Timer
int lights_off_hour = 10;
int lights_off_minute = 30;

// Flag whether the Lights Screen is initially filled: 1 means filled
int lights_fill = 0;

// "Main" function for Lights Page
void custom_light_page(int x, int y) 
{
  if (lights_fill == 0) 
  {
    lights_fill = 1;
    my_lcd.Fill_Screen(RGBENC(247, 251, 255)); //Light blue background
    draw_lighting();
    switch(light_color) // Draw Current Selected color
    {
      case red:
        my_lcd.Set_Draw_color(RED);
        my_lcd.Draw_Circle(43,110,12);
        break;
      case orange:
        my_lcd.Set_Draw_color(ORANGE);
        my_lcd.Draw_Circle(76,110,12);
        break;
      case yellow:
        my_lcd.Set_Draw_color(YELLOW);
        my_lcd.Draw_Circle(109,110,12);
        break;
      case green:
        my_lcd.Set_Draw_color(GREEN);
        my_lcd.Draw_Circle(142,110,12);
        break;
      case blue:
        my_lcd.Set_Draw_color(BLUE);
        my_lcd.Draw_Circle(175,110,12);
        break;
      case magenta:
        my_lcd.Set_Draw_color(MAGENTA);
        my_lcd.Draw_Circle(208,110,12);
        break;
    }

    // Draw Slider Box
    my_lcd.Set_Draw_color(DARK_GRAY);
    my_lcd.Fill_Rectangle(sliderx-10, 206,sliderx+10, 218);

    // Draw Current Time
    change_time(160, 270, lights_off_hour, lights_off_minute);
	}
	
  update_light_page(x, y);

  //return to main button
  if(chk_btn_rec(10,290,50,310,x,y))
  {
    page = menu;
    lights_fill = 0;
  } 
}

//ATTEMPTS to update the lights page based on a touch coordinate
void update_light_page(int x, int y) 
{
  char str[10]; // Placeholder used to display time as a string
  if(chk_btn_rec(33,100,53,120,x,y)) {
    light_color = red;
    clean_light_buttons();
    my_lcd.Set_Draw_color(RED);
    my_lcd.Draw_Circle(43,110,12);
    my_lcd.Set_Draw_color(WHITE);
    my_lcd.Draw_Circle(43,110,11);
  }
  if(chk_btn_rec(66,100,86,120,x,y)) {
    light_color = orange;
    clean_light_buttons();
    my_lcd.Set_Draw_color(ORANGE);
    my_lcd.Draw_Circle(76,110,12);
    my_lcd.Set_Draw_color(WHITE);
    my_lcd.Draw_Circle(76,110,11);
  }
  if(chk_btn_rec(99,100,119,120,x,y)) {
    light_color = yellow;
    clean_light_buttons();
    my_lcd.Set_Draw_color(YELLOW);
    my_lcd.Draw_Circle(109,110,12);
    my_lcd.Set_Draw_color(RGBENC(247, 251, 255));
    my_lcd.Draw_Circle(109,110,11);
  }
  if(chk_btn_rec(132,100,152,120,x,y)) {
    light_color = green;
    clean_light_buttons();
    my_lcd.Set_Draw_color(GREEN);
    my_lcd.Draw_Circle(142,110,12);
    my_lcd.Set_Draw_color(WHITE);
    my_lcd.Draw_Circle(142,110,11);
  }
  if(chk_btn_rec(165,100,185,120,x,y)) {
    light_color = blue;
    clean_light_buttons();
    my_lcd.Set_Draw_color(BLUE);
    my_lcd.Draw_Circle(175,110,12);
    my_lcd.Set_Draw_color(WHITE);
    my_lcd.Draw_Circle(175,110,11);
  }
  if(chk_btn_rec(198,100,218,120,x,y)) {
    light_color = magenta;
    clean_light_buttons();
    my_lcd.Set_Draw_color(MAGENTA);
    my_lcd.Draw_Circle(208,110,12);
    my_lcd.Set_Draw_color(WHITE);
    my_lcd.Draw_Circle(208,110,11);
  }

  // Update Time
  if(chk_btn_rec(158,262,200,286,x,y)) {
    time_increment(&lights_off_hour, &lights_off_minute);
    change_time(160, 270, lights_off_hour, lights_off_minute);
  }

  // Update Slider
  if(chk_btn_rec(43,186,188,238,x,y)){
    sliderx = x;
    my_lcd.Set_Draw_color(RGBENC(247, 251, 255));
    my_lcd.Fill_Rectangle(20,206,248,218);
    my_lcd.Set_Draw_color(BLACK);
    my_lcd.Fill_Rectangle(43,210,208,214);
    my_lcd.Set_Draw_color(DARK_GRAY);
    my_lcd.Fill_Rectangle(sliderx-10, 206,sliderx+10, 218);
  } 
}		

// Gets rid of the "selected" circle around the colored circles
void clean_light_buttons(void) 
{
  // Draw Circle in color of light blue background to clear "selected circle"
  my_lcd.Set_Draw_color(RGBENC(247, 251, 255));
  
  my_lcd.Draw_Circle(43,110,11);
  my_lcd.Draw_Circle(76,110,11);
  my_lcd.Draw_Circle(109,110,11);
  my_lcd.Draw_Circle(142,110,11);
  my_lcd.Draw_Circle(175,110,11);
  my_lcd.Draw_Circle(208,110,11);

  my_lcd.Draw_Circle(43,110,12);
  my_lcd.Draw_Circle(76,110,12);
  my_lcd.Draw_Circle(109,110,12);
  my_lcd.Draw_Circle(142,110,12);
  my_lcd.Draw_Circle(175,110,12);
  my_lcd.Draw_Circle(208,110,12);
}

// Draws the elements of Lighting Screen that won't change 
void draw_lighting(void) 
{
  show_string("Lightings", 70, 25, 2, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Colours", 35, 80, 1, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Intensity", 35, 180, 1, BLACK, RGBENC(247, 251, 255), 1);
  show_string("Lights off", 80, 273, 1, BLACK, RGBENC(247, 251, 255), 1);

  // Color Circles
  my_lcd.Set_Draw_color(RED);
  my_lcd.Fill_Circle(43,110,10);
  my_lcd.Set_Draw_color(ORANGE);
  my_lcd.Fill_Circle(76,110,10);
  my_lcd.Set_Draw_color(YELLOW);
  my_lcd.Fill_Circle(109,110,10);
  my_lcd.Set_Draw_color(GREEN);
  my_lcd.Fill_Circle(142,110,10);
  my_lcd.Set_Draw_color(BLUE);
  my_lcd.Fill_Circle(175,110,10);
  my_lcd.Set_Draw_color(MAGENTA);
  my_lcd.Fill_Circle(208,110,10);

  my_lcd.Set_Draw_color(BLACK);
  my_lcd.Fill_Rectangle(43,210,208,214);  // Slider Bar

  time_box(160, 270, lights_off_hour, lights_off_minute);

	draw_return();
}
