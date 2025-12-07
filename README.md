Main Optimization Content:

1. Optimization of LED_1 and LED_2 switches. The original code used four if-condition functions to control the LEDs, but the author here implements the logic using only one function (8 bytes + 2 if-condition checks), ensuring both input safety and program stability.

2. Optimization of the button function to prevent the issue where the LED does not light up when the button is pressed. The logic is clearer.

3. Optimization of the main.c function in the source code to avoid multiple loop condition checks. Only one line of code is needed to call two functions, improving the program's readability and encapsulation.
