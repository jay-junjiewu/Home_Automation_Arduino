extern int auto_mode;

/* 
"Main" function for Autonomous Page
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
void autonomous_page(int x, int y);

/*
ATTEMPTS to change the state of autonomous system
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
void switch_state(int x, int y);

/*
Draws the full Autonomous System Screen
    <mode: 0 for OFF, 1 for ON>
*/
void draw_auto(int mode);

/*
Draws the Autonomous System Buttons Only
    <mode: 0 for OFF, 1 for ON>
*/
void draw_auto_mode(int mode);
