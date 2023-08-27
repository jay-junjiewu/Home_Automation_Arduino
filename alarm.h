/* 
"Main" function for Alarms Page
    <x_coordinate of LCD press>, <y_coordinate of LCD press>
*/
void custom_alarm_page(int x, int y);

/*
Draws the elements of Alarm Screen, text and number buttons
*/
void draw_alarm();

/*
Shifts the alarm numbers one place to the right
    <current hour>, <current minutes>, <number to shift in>
*/
void alarm_shift(int *timeh, int *timem, int number);

/*
Draws an alarm time box border then calls alarm_change_time()
    <x_coordinate of text>, <y_coordinate of text>,
    <hour: 0-23>, <minute: 00 or 30>
*/
void alarm_time_box(int x, int y, int hours, int minutes);

/*
Draws white background inside border and adds the alarm_time
    <x_coordinate of text>, <y_coordinate of text>,
    <hour: 0-23>, <minute: 00 or 30>
*/
void alarm_change_time(int x, int y, int hours, int minutes);