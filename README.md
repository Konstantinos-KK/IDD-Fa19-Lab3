# Data Logger (and using cool sensors!)

*A lab report by Konstantinos Karras Kallidromitis.*

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?** 0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?** 10bit Since  2^10 = 1024

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.** [Video](https://youtu.be/CJYmjiJpKtA)

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?** When no force is applied the voltage is zero. With a force the voltage jumps up close to 1023 (5V).

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)** Logarithmic. A small change in force results to a large increase in voltage (decrease in resistance).

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?** Using the map function we modify the code. [Fade](https://github.com/Konstantinos-KK/IDD-Fa19-Lab3/blob/master/map_a0.ino)

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**
I used a 22k Ohm resistance to get reasonable results. The flex sensor was connected as the FSR, the softpot and photocell also used a 22k Ohm and were connected as shown below:

<p align="center"> <b> Circuit Diagram for photoresistor and softpot </b> </p>
<p float="left">
  <img src="https://github.com/Konstantinos-KK/IDD-Fa19-Lab3/blob/master/photoresistor.png" width="425" />
  <img src="https://github.com/Konstantinos-KK/IDD-Fa19-Lab3/blob/master/example_circuit_bb-pulldown.png" width="425" /> 
</p>

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)** The relationship with the flex sensor and softspot is linear. The photocell and the fsr have a logarithmic relationship which results in a sudden huge change in resistance.

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**  Since range is limitless for each axis, I change the RGB lights based on which direction has the largest acceleration. [Code](https://github.com/Konstantinos-KK/IDD-Fa19-Lab3/blob/master/rgd_acc.ino) [Video](https://youtu.be/HjVnfO53Nik)

### 3. IR Proximity Sensor

Section Ignored

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

**b. Upload your merged code to your lab report repository and link to it here.**

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**  [Video](https://youtu.be/QXh4ccJM0ao) [Code](https://github.com/Konstantinos-KK/IDD-Fa19-Lab3/blob/master/graphic.ino)

<p align="center"> <b> Graphic Display </b> <p>
<p align="center">
  <img width="600" src="https://github.com/Konstantinos-KK/IDD-Fa19-Lab3/blob/master/read_a0.jpg">
</p>


## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

**c. How many byte-sized data samples can you store on the Atmega328?**

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
