// Different colours that the lights can be on
enum color {
  no_color = 0,
	red = 1,
	orange = 2,
	yellow = 3,
	green = 4,
	blue = 5,
	magenta = 6
};

extern int light_color;

/* 
"Main" function for Light Page
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
void custom_light_page (int x, int y);

/*
ATTEMPTS to update the lights page based on a touch coordinate
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
void update_light_page(int x, int y);

/*
Gets rid of the "selected" circle around the colored circles
*/
void clean_light_buttons(void);

/*
Draws the elements of Lighting Screen that won't change 
  e.g. text, color circles, slider bar, time box, return button
*/
void draw_lighting(void);