// An ultra sound unit the HC-SR04 is connected to a servo motor controlled by pwm.
//  c code to send ultra sound and receive it , work out the range and graph it on an 8x8 matrix of leds



#include <stdio.h>
#include <math.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRIG 5
#define ECHO 6

void setup() {
        wiringPiSetup();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
        //stop trigger pin for a while
        digitalWrite(TRIG, LOW);
        delay(30);
}

int getCM() {
        //Send trigger pulse
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);

        //Wait for echo start
        while(digitalRead(ECHO) == LOW);

        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;

        //Get distance in cm
        int distance = travelTime / 58;

        return distance;
}

int main(void) {
        setup();

        printf("Distance: %dcm\n", getCM());
        return 0;
}
