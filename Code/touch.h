/*
Checks if LCD press is within a rectangle
    <x_coordinate of top left corner>, <y_coordinate of top left corner>,
    <x_coordinate of bottom right corner>, <y_coordinate of bottom right corner>,
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
int chk_btn_rec(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t px,int16_t py);

/*
Draws the return box to take us back to Main Menu
*/
void draw_return(void);

/*
Takes in a time in 24 hour system and increments it by 30 min
    <hour: 0-23>, <minute: 00 or 30>
*/
void time_increment(int *hour, int *minute);

/*
Draws an ON/OFF button
    <state: 1 for on, 0 for off>,
    <x_coordinate of center>, <y_coordinate of center>
*/
void button_switch(int state, int x, int y);

/*
Draws a time box border then calls change_time()
    <x_coordinate of text>, <y_coordinate of text>,
    <hour: 0-23>, <minute: 00 or 30>
*/
void time_box(int x, int y, int hours, int minutes);

/*
Draws white background inside border and adds the time
    <x_coordinate of text>, <y_coordinate of text>,
    <hour: 0-23>, <minute: 00 or 30>
*/
void change_time(int x, int y, int hours, int minutes);
