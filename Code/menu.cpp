#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"    // Initial Declarations
#include "graphics.h"   // Colours & graphics functions
#include "touch.h"      // Touch functions

#include "menu.h"       // Menu Mode Variables & Functions

// Flag whether the Main Menu Screen is initially filled: 1 means filled
int menu_fill = 0;

// "Main" function for Menu Page
void menu_page(int x, int y, int *page) 
{
  if (menu_fill == 0) {
    draw_menu();
		menu_fill = 1;
	}

  if(chk_btn_rec(43,60,200,90,x,y)){
    *page = autonomous;
    menu_fill = 0;
  } 
  if(chk_btn_rec(43,110,200,140,x,y)){
    *page = custom_lights;
    menu_fill = 0;
  }  
  if(chk_btn_rec(43,160,200,190,x,y)){
    *page = custom_sprinkler;
    menu_fill = 0;
  } 
  if(chk_btn_rec(43,210,200,240,x,y)){
    *page = custom_blinds;
    menu_fill = 0;
  } 
  if(chk_btn_rec(43,260,200,290,x,y)){
    *page = custom_alarm;
    menu_fill = 0;
  } 
}

// Draws the Main Menu Screen
void draw_menu(void) 
{
	my_lcd.Fill_Screen(RGBENC(247, 251, 255)); //Light blue background
  show_string("MENU", 100, 25, 2, BLACK, RGBENC(247, 251, 255), 1);

  my_lcd.Set_Draw_color(LIGHT_GRAY);

  my_lcd.Fill_Round_Rectangle(43,60,200,90,15); 
  show_string("Autonomous Mode", 77, 72, 1, BLACK, LIGHT_GRAY, 1);

  my_lcd.Fill_Round_Rectangle(43,110,200,140,15); 
  show_string("Light Settings", 82, 122, 1, BLACK, LIGHT_GRAY, 1);

  my_lcd.Fill_Round_Rectangle(43,160,200,190,15); 
  show_string("Sprinkler Settings", 70, 172, 1, BLACK, LIGHT_GRAY, 1);

  my_lcd.Fill_Round_Rectangle(43,210,200,240,15); 
  show_string("Blinds Settings", 78, 222, 1, BLACK, LIGHT_GRAY, 1);

  my_lcd.Fill_Round_Rectangle(43,260,200,290,15); 
  show_string("Alarm Settings", 80, 272, 1, BLACK, LIGHT_GRAY, 1);
}
