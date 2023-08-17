#define   BLACK			  0x0000		  /*   0,   0,   0 */
#define   NAVY			  0x000F      /*   0,   0, 128 */
#define   DARK_GREEN	0x03E0      /*   0, 128,   0 */
#define   DARK_CYAN		0x03EF      /*   0, 128, 128 */
#define   MAROON		  0x7800      /* 128,   0,   0 */
#define   PURPLE		  0x780F      /* 128,   0, 128 */
#define   OLIVE			  0x7BE0      /* 128, 128,   0 */
#define   LIGHT_GRAY	0xC618      /* 192, 192, 192 */
#define   DARK_GRAY		0x7BEF      /* 128, 128, 128 */
#define   BLUE			  0x001F 
#define   BLUE_BG			0xBFFF 
#define   GREEN			  0x07E0      /*   0, 255,   0 */
#define   CYAN        0x07FF      /*   0, 255, 255 */
#define   RED         0xF800      /* 255,   0,   0 */
#define   MAGENTA		  0xF81F      /* 255,   0, 255 */
#define   YELLOW		  0xFFE0      /* 255, 255, 0   */
#define   WHITE			  0xFFFF      /* 255, 255, 255 */
#define 	ORANGE			0xFBE0      /* 255, 128,   0 */ 

#define		RGBENC(r,g,b)	((r&0x1F)<<11) | ((g&0x3F)<<5) | (b&0x1F)
#define 	DECODE_R(e) (e>>11)&0x1F
#define 	DECODE_G(e) (e>>5)&0x3F
#define 	DECODE_B(e) (e)&0x1F

/*
Displays String on LCD
    <string>, <x_coordinate>, <y-coordinate>, <size: multiplier, 1 for 5x7>, 
          <font color>, <background color>, <display on LCD: 1 for yes, 0 for no>
*/
void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,bool mode);