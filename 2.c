// An ultra sound unit the HC-SR04 is connected to a servo motor controlled by pwm. 
// it sweeps back and forth covering  a 90 degree angle .
// c code to send ultra sound and receive it ,
// work out the range of the echo and graph it on an 8x8 matrix of leds


  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <math.h>

//definitions
#define F_CPU 16000000UL
#define LED_DDR		DDRD
#define LED_PORT	PORTD
#define LED_PIN		PIND
//#define TRIGGER_PIN	PD4
//#define ECHO_PIN	PD5
#define SERVO_PIN	PD6
#define SERVO_DDR	DDRD
#define SERVO_PORT	PORTD

//variables
volatile long count;
volatile int edge;

//functions
void trigger_pulse();
long measure_distance();
void init_servo();

// timing variables
uint8_t servo_pos = 0;
unsigned long prev_time = 0;


int main(void)
{
	sei();
	
	//configure LED output
	LED_DDR = 0xff;
	
	//configure trigger pin
	//DDRD |= (1 << TRIGGER_PIN);
	
	//configure echo pin
	//DDRD &= ~(1 << ECHO_PIN);
	//PORTD |= (1 << ECHO_PIN);
	
	init_servo();
	
	while (1)
	{
		//send 10us pulse
		trigger_pulse();
		
		//measure distance
		long distance = measure_distance();
		
		//convert distance to time
		long time = distance * 58 / 1000;
		
		//rotate servo to new position
		int servo_pos = round((time - 500) / 1000.0 * 255);
		
		//set LED output based on distance
		if (distance >= 200) {
			LED_PORT = 0x00;
		}
		else if (distance < 200) {
			LED_PORT = 0xff;
		}
		else {
			LED_PORT = 0x00;
		}
		
		//delay before next measurement
		while (TCNT3 < 100000);
	}
}

void init_servo()
{
	//configure timer3
	TCCR3A |= (1 << WGM31);				//set to CTC mode
	TCCR3B |= (1 << CS31) | (1 << CS30);	//set prescaler to 64
	
	//set initial servo position
	OCR3A = 1500;
	
	//set servo pin as output
	SERVO_DDR |= (1 << SERVO_PIN);
}

void trigger_pulse()
{
	//set trigger pin high for 10us
	//PORTD |= (1 << TRIGGER_PIN);
	//_delay_us(10);
	//PORTD &= ~(1 << TRIGGER_PIN);
}

long measure_distance()
{
	//enable interrupt on rising edge
	//EIMSK |= (1 << INT0);
	//EICRA |= (1 << ISC01);
	
	//reset counter
	//TCNT1 = 0;
	//count = 0;
	//edge = 0;
	
	//wait for rising and falling edge
	//while (edge < 2);
	
	//disable interrupt
	//EIMSK &= ~(1 << INT0);
	
	//return count / 2;
	return 0;
}

ISR(TIMER3_COMPA_vect)
{
	//rotate servo
	int new_servo_pos = servo_pos + 5;
	if (new_servo_pos > 255) {
		new_servo_pos = 0;
	}
	OCR3A = new_servo_pos * 1000 / 255 + 500;
	servo_pos = new_servo_pos;
}
