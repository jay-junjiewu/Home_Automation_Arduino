#define TS_MINX 124
#define TS_MAXX 906
#define TS_MINY 83  
#define TS_MAXY 893

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM 9   // can be a digital pin
#define XP 8   // can be a digital pin

// We have a status line for like, is FONA working
#define STATUS_X 10
#define STATUS_Y 65

// Pressure of the touch "z-coordinates"
#define MINPRESSURE 10
#define MAXPRESSURE 1000

extern LCDWIKI_KBV my_lcd;
extern TouchScreen ts;
