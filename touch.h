/*
Checks if LCD press is within a rectangle
    <x_coordinate of top left corner>, <y_coordinate of top left corner>,
    <x_coordinate of bottom right corner>, <y_coordinate of bottom right corner>
    <x_coordinate of LCD press>, <y_coordinate of LCD press>,
*/
int chk_btn_rec(int16_t x1,int16_t y1,int16_t x2,int16_t y2,int16_t px,int16_t py);