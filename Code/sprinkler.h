extern int sprinkler_state;

/* 
"Main" function for Sprinkler Page
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
void custom_sprinkler_page(int x, int y);

/*
Draws the elements of Sprinkler Screen, text and timebox
*/
void draw_sprinkler();
