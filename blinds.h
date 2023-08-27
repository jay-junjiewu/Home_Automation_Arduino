extern int blind_state;

/* 
"Main" function for Blinds Page
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
void custom_blinds_page(int x, int y);

/*
Draws the elements of Blinds Screen, text and timebox
*/
void draw_blinds();
