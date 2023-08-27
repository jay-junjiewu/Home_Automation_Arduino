#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

#include "initial.h"

// Current Page of LCD
int	page = menu;

//if the IC model is known or the modules is unreadable,you can use this constructed function
//LCDWIKI_KBV my_lcd(ILI9341,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
LCDWIKI_KBV my_lcd = LCDWIKI_KBV(ILI9341,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
//if the IC model is not known and the modules is readable,you can use this constructed function
//LCDWIKI_KBV my_lcd(240,320,A3,A2,A1,A0,A4);//width,height,cs,cd,wr,rd,reset

// Creates the TouchScreen Object
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 334);