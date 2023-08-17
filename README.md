# Home_Automation

This project is a home automation system build using an 8bit LCD module and Arduino.

This project requires the LCDWIKI and Touchscreen library.

    File                : MEEBO_Arduino

    Hardware Environment: Arduino Uno or Nano or Mega

    Build Environment   : Arduino IDE

## Hardware Configuration
Set the pins to the correct ones for your development shield or breakout board.

                      LCD_CS  LCD_CD  LCD_WR  LCD_RD  LCD_RST  SD_SS  SD_DI  SD_DO  SD_SCK 
     Arduino Uno        A3      A2      A1      A0      A4      10     11     12      13                           
    Arduino Nano        A3      A2      A1      A0      A4      10     11     12      13  
    Arduino Mega2560    A3      A2      A1      A0      A4      10     11     12      13                           

                      LCD_D0  LCD_D1  LCD_D2  LCD_D3  LCD_D4  LCD_D5  LCD_D6  LCD_D7  
     Arduino Uno        8       9       2       3       4       5       6       7
    Arduino Nano        8       9       2       3       4       5       6       7
    Arduino Mega2560    8       9       2       3       4       5       6       7 

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
