
/*      Author: Van Truong
 *  	Partner(s) Name: An Pho
 *      Lab Section:
 *      Assignment: Lab #9  Exercise #1
 *      Exercise Description: [optional - include for your own benefit]
 *
 *      I acknowledge all content contained herein, excluding template or example
 *      code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#include <avr/interrupt.h>
#endif

void set_PWM(double frequency) {
	static double current_frequency;
	if (frequency != current_frequency) {
		if (!frequency) { TCCR3B &= 0x08; }
		else { TCCR3B |= 0x03; }
		if (frequency < .954) { OCR3A = 0xFFFF; }
		else if (frequency > 31250) { OCR3A = 0x0000; }
		else { OCR3A = (short) (8000000 / (128 * frequency)) - 1; }
		
		TCNT3 = 0;
		current_frequency = frequency;
	}
}

void PWM_on() {
	TCCR3A = (1 << COM3A0);
	TCCR3B = (1 << WGM32) | (1<< CS31) | (1 << CS30);
	set_PWM(0);
}

void PWM_off() {
	TCCR3A = 0x00;
	TCCR3B = 0x00;
}

enum States {init, wait, button1, button2, button3} states;
	
void MusicFnct() {
	unsigned char C4 = ~PINA & 0x01;
	unsigned char D4 = ~PINA & 0x02;
	unsigned char E4 = ~PINA & 0x04;
	switch (states) {
		case init:
			states = wait;
			break;

		case wait:
			if(!C4 && !D4 && !E4) {
				states = wait;
			}
			else if(C4 && !D4 && !E4) {
				states = button1;
			}
			else if(!C4 && D4 && !E4) {
				states = button2;
			}
			else if(!C4 && !D4 && E4) {
				states = button3;
			}
			else {
				states = wait;
			}
			break;

		case button1:
			if(C4 && !D4 && !E4) {
				states = button1;	
			}
			else {
				states = wait;	
			}
			break;

		case button2:
			if(!C4 && D4 && !E4) {
				states = button2;	
			}
			else {
				states = wait;	
			}
			break;

		case button3:
			if(!C4 && !D4 && E4) {
				states = button3;
			}
			else {
				states = wait;	
			}
			break;

		default:
			PWM_off();
			states = init;
			break;
	}
	
	switch(states) {
		case init:
			break;

		case wait:
			set_PWM(0);
			break;

		case button1:
			set_PWM(261.63);
			break;

		case button2:
			set_PWM(293.66);
			break;

		case button3:
			set_PWM(329.63);
			break;

		default:
			break;
	}
	
}
int main(void)
{
    /* Replace with your application code */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	PWM_on();
	states = init;
	while (1) 
    	{
		MusicFnct();
    	}

}



			

