It was part of a university project
# Project Description 
The LCD is connected to the Arduino and receives its action from the keypad 
through the Arduino and to its job through the function named keypadEvent(). 
When the project starts, the LCD prints “Enter Password“. The Arduino will check 
the password through the function named checkPassword(). If the entered 
characters is equal to the right password, the LCD prints “OPEN”. If the entered 
characters is not equal to the right password, the LCD prints “Try again“. 
When the magnet is kept away from the reed switch, the reed switch sense its 
magnetic field and the active buzzer starts its sound. 
When the temperature sensor senses a higher temperature than 30, the DC motor 
starts rotating and the serial monitor prints the temperature value. 
When the LDR detects darkness, it sends a signal to the Arduino to light the LED 
that is connected to it through the function named light().
