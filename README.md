# tec-RADAR-Infrared

`0.c`;  code, example of how to use ultrasonic sensors to measure distance. It uses the getDistance() function to send a trigger pulse and get the echo time, and then uses that to calculate the distance. If the distance is less than or equal to 10, then the distance is displayed on an 8x8 LED Matrix.

`1.c`; An ultra sound unit the HC-SR04 is connected to a servo motor controlled by pwm. c code to send ultra sound and receive it , work out the range and graph it on an 8x8 matrix of leds.  code  send and receive an ultra sound signal using an HC-SR04 unit connected to a servo motor controlled by pwm. The code sets up the TRIG and ECHO pins as output and input respectively, and then sends a trigger pulse to the TRIG pin. It then waits for the echo start before measuring the time difference between echo start and echo end, which is used to calculate the distance in cm. The distance is then printed out on the console. This code can be used to graph the range on an 8x8 matrix of LEDs, by using the distance calculated to light up the corresponding LED.

`2.c`; code is written in C and is designed to use an HC-SR04 ultrasonic unit connected to a servo motor controlled by PWM to sweep back and forth covering a 90 degree angle. The code sends an ultrasonic pulse and receives its echo to measure the range of the echo and graph it on an 8x8 matrix of LEDs. 
The code starts by including the AVR/IO and AVR/Interrupt libraries and the math library. It then defines constants, variables and functions and then declares timing variables. The main loop begins with triggering a pulse and measuring the distance of the echo. It then converts this distance to time and rotates the servo to the new position. Lastly, the LED output is set based on the distance, and a delay is added before the next measurement. The init_servo() function is used to configure a timer and set the servo pin as an output. The trigger_pulse() function triggers a 10 us pulse and the measure_distance() function enables interrupt on rising edge and waits for rising and falling edge before disabling it and returning the count divided by 2. Finally, the ISR is used to rotate the servo each time the timer reaches its compare value.

## infrared sensor
- HC-SR04
![image](https://user-images.githubusercontent.com/58069246/214206262-d15646f3-065e-4e99-b2a0-1c896be40d84.png)


- Sharp GP2Y0A02
![image](https://user-images.githubusercontent.com/58069246/214206325-188a5a42-1eb9-465b-9468-700e0264729c.png)


- SEN0259
![image](https://user-images.githubusercontent.com/58069246/214206350-e7888a2f-972c-4717-b820-ccebfe75061e.png)


## sweep motor
- servo



### Ref
- https://mtelectronics.tech.blog/2020/02/02/arduino-infrared-radar/
- https://au.element14.com/    /sen0259/
- https://www.amazon.com.au/MiLESEEY-Rangefinder-Magnification-Scanning-Carrying/dp/B07RW24BQB/ref=asc_df_B07RW24BQB/?tag=googleshopdsk-22&linkCode=df0&hvadid=463569621553&hvpos=&hvnetw=g&hvrand=18168480720988693001&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=1000286&hvtargid=pla-828775351134&th=1
- https://www.mileseeytools.com/products/best-golf-rangefinder-binoculars-bpfs2
- 

