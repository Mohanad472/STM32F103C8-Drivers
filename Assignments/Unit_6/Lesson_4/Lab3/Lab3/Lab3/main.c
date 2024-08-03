/*
 * Lab3.c
 *
 * Created: 8/3/2024 2:51:59 PM
 * Author : Mohanad
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

int main(void)
{
	//Configure pins D5 D6 D7 as outputs
	DDRD |=	0b11100000;
	
	/*
	Interrupts configurations
		INT0 rising edge --> ISC01 ISC00 = 0 1
		
		INT1 rising edge --> ISC11 ISC10 = 1 1
		
		INT2 falling edge --> ISC2 = 0
	*/
	MCUCR |= 0b00001101;
	MCUCR &= ~(0b00000010);
	MCUCSR &= ~(0b01000000);
	
	//Interrupt mask
	GICR |= 0b11100000;
	
	//Global interrupt enable
	SREG |=0b10000000;
	
	//
	/* Replace with your application code */
    while (1) 
    {
    }
}

ISR (INT0_vect)
{
	PORTD |= 0b00100000;
	//wait one second
	_delay_ms(1000);
	PORTD &= ~(0b00100000);
	
	//clear interrupt flag of INT0
	GIFR &= ~(0b01000000);
}

ISR (INT1_vect)
{
	PORTD |= 0b01000000;
	//wait one second
	_delay_ms(1000);
	PORTD &= ~(0b01000000);
	
	//clear interrupt flag of INT0
	GIFR &= ~(0b10000000);
}

ISR (INT2_vect)
{
	PORTD |= 0b10000000;
	//wait one second
	_delay_ms(1000);
	PORTD &= ~(0b10000000);
	
	//clear interrupt flag of INT0
	GIFR &= ~(0b00100000);
}

