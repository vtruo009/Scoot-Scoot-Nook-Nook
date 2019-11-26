/*
 * ADC_C.c
 *
 * Created: 7/28/2016 4:56:54 PM
 *  Author: User
 */ 

#include "ADC_H.h"

/*void ADC_Init()
{
	DDRA = 0x00;		//Make ADC port as input
	ADCSRA = 0x87;		//Enable ADC, fr/128
	ADMUX = 0x40;		//Vref: Avcc, ADC channel: 0
}

int ADC_Read(char channel)
{
	int ADC_value;
	
	ADMUX = (0x40) | (channel & 0x07); //set input channel to read
	ADCSRA |= (1<<ADSC);	//start conversion
	while((ADCSRA &(1<<ADIF))== 0);	//monitor end of conversion interrupt flag
	
	ADCSRA |= (1<<ADIF);	//clear interrupt flag
	ADC_value = (int)ADCL;	//read lower byte
	ADC_value = ADC_value + (int)ADCH*256; //read higher 2 bits, Multiply with weightage

	return ADC_value;		//return digital value
}*/

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC);
}

void ADC_channel(unsigned char channel){
	if(channel < 8 && channel >= 0){
		//CLEAR ADMUX2:0
		ADMUX &= 0xF8;
		//Set ADMUX
		ADMUX |= (channel & 0x07);
	}
}

unsigned short ADC_read(unsigned char channel){
		unsigned short myADC = 0x0000;
		ADC_channel(channel);
		ADCSRA |= (1 << ADSC);
		while(ADCSRA & (1 << ADSC));
		myADC = ADC;
		return myADC;
} 
