/*
 * ADC_H.h
 *
 * Created: 7/28/2016 4:50:16 PM
 *  Author: User
 */ 


#ifndef ADC_H_H_
#define ADC_H_H_

#define F_CPU 8000000UL					/* Define CPU Frequency e.g. here its 8 Mhz */
#include <avr/io.h>						/* Include AVR std. library file */
#include <util/delay.h>
#define ipin PINA
#define iport PORTA

/*void ADC_Init();
int ADC_Read(char);*/

//void ADC_init();
// void ADC_channel(unsigned char channel);
// unsigned short ADC_read(unsigned char channel);

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

#endif /* ADC_H_H_ */
