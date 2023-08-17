// Autonomous Home System State: 0 for OFF 1 for ON
extern int auto_mode;

// Initially autonoous mode OFF, Y-coordinates of the button represents state system is on
extern int current_state_y;
extern int next_state_y;

/* 
"Main" function for Autonomous Page
    <x_coordinate of LCD press>, <y_coordinate of LCD press>,
    <current state y_coordinate of button>, <next state y_coordinate of button>,
    <mode: 0 for OFF, 1 for ON>
*/
void autonomous_page (int x, int y, int *current_state_y, int *next_state_y, int *auto_mode);

/*
ATTEMPTS to change the state of autonomous system
    <x_coordinate of LCD press>, <y_coordinate of LCD press>,
    <current state y_coordinate of button>, <next state y_coordinate of button>,
    <mode: 0 for OFF, 1 for ON>
*/
void switch_state(int x, int y, int *current_state_y, int *next_state_y, int *auto_mode);

/*
Draws the Autonomous System Screen
    <mode: 0 for OFF, 1 for ON>
*/
void draw_auto(int auto_mode);

/*
Draws the Autonomous System Buttons Only
    <mode: 0 for OFF, 1 for ON>
*/
void draw_auto_mode(int auto_mode);