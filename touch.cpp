#include <TouchScreen.h> //touch library
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library

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