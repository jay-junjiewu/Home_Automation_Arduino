# Home_Automation

This project is a home automation system built using an 8-bit LCD module and Arduino.

This project requires the LCDWIKI and Touchscreen library.

    File                : Home_Automation_Arduino.ino

    Hardware Environment: Arduino Uno or Nano or Mega

    Build Environment   : Arduino IDE
    
## Table of Contents
- [Code Files](#code-files)
- [Hardware Configuration](#hardware-configuration)
- [Contributing](#contributing)
- [License](#license)


## Code Files

#### `Home_Automation_Arduino.ino`
Description: This file contains the main logic for reading and processing touchscreen input. It then calls the appropriate mode functions depending on the mode that it is currently on. It also outputs the results of extern variables (`auto_mode`, `page`, `light_color`, `sprinkler_state`, and `blind_state`) to external LEDs.

#### `initial.h` & `initial.cpp`
Description: These files contain the initial `#define` and declarations. Creates the "Touchscreen" and "LCDWIKI_KBV" objects to be used in the whole program.  
`extern int page`: The current menu page that the LCD is on. Different page codes are declared in `enum pages`.  

#### `graphics.h` & `graphics.cpp`
Description: These files contain the `#define` for hex and RGB colours. Also has a function to display a string on the LCD.  


#### `touch.h` & `touch.cpp`
Description: These files contain helper functions that may be called when LCD is touched.  

#### `autonomous.h` & `autonomous.cpp`
Description: These files contain the variables and functions for the autonomous page.  
`extern int auto_mode`: The current autonomous state, 0 for OFF, 1 for ON.  

#### `menu.h` & `menu.cpp`
Description: These files contain the variables and functions for the main menu page.  

#### `custom_lights.h` & `custom_lights.cpp`
Description: These files contain the variables and functions for the custom lights page.  
`extern int light_color`: The current light colour. Different colour codes are declared in `enum color`.  

#### `sprinkler.h` & `sprinkler.cpp`
Description: These files contain the variables and functions for the sprinkler page.  
`extern int sprinkler_state`: The current sprinkler state, 0 for OFF, 1 for ON.  

#### `blinds.h` & `blinds.cpp`
Description: These files contain the variables and functions for the blinds page.  
`extern int blind_state`: The current blinds state, 0 for OFF, 1 for ON.  

#### `alarm.h` & `alarm.cpp`
Description: These files contain the variables and functions for the alarm page.  


## Hardware Configuration
Set the pins to the correct ones for your development shield or breakout board. I have not used the SD card on the LCD module so the SD card pins can be left unconnected.

                      LCD_CS  LCD_CD  LCD_WR  LCD_RD  LCD_RST  SD_SS  SD_DI  SD_DO  SD_SCK 
     Arduino Uno        A3      A2      A1      A0      A4      10     11     12      13                           
    Arduino Nano        A3      A2      A1      A0      A4      10     11     12      13  
    Arduino Mega2560    A3      A2      A1      A0      A4      10     11     12      13                           

                      LCD_D0  LCD_D1  LCD_D2  LCD_D3  LCD_D4  LCD_D5  LCD_D6  LCD_D7  
     Arduino Uno        8       9       2       3       4       5       6       7
    Arduino Nano        8       9       2       3       4       5       6       7
    Arduino Mega2560    8       9       2       3       4       5       6       7 

I used LEDs to represent the sprinkler, blinds and lighting systems
* Sprinkler LED:     D13
* Blinds LED:        A5 as digital pin
* Colours:           D12-D10 gets mapped to A2-A0 in 3-8 decoder (74HC138) respectively, where D10 is LSB

      decoder        A2   A1   A0
      Arduino       D12  D11  D10
  
      no_color       0    0    0
      red            0    0    1
      orange         0    1    0
      yellow         0    1    1
      green          1    0    0
      blue           1    0    1
      magenta        1    1    0


## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. 

If you have any questions or suggestions, feel free to contact me at junjiewu0930@gmail.com.


## License

[MIT](https://choosealicense.com/licenses/mit/)
