/*
 * LCD.c
 *
 * Created: 2/29/2024 3:18:48 PM
 *  Author: Mohanad
 */ 

#include "LCD.h"

void LCD_kick()
{
	// reset the enable and then set it to make sure its not busy
	LCD_CTRL &= ~(1<<EN_SWITCH);	//command mode
	_delay_ms(30);
	LCD_CTRL |= (1<<EN_SWITCH);	//command mode
}

LCD_go_to_xy(int row, int col)
{
	if(row == 1)
	{
		if(col < 16 && col > 0)
		{
			LCD_write_cmd(LCD_BEGIN_AT_FIRST_ROW + col);
		}
	}
	else if(row == 2)
	{
		if(col < 16 && col > 0)
		{
			LCD_write_cmd(LCD_BEGIN_AT_SECOND_ROW + col);
		}
	}
}

void LCD_clear_screen(void)
{
	LCD_write_cmd(LCD_CLEAR_SCREEN);
}

void LCD_is_busy(void)
{
	#ifdef FOUR_BIT_MODE
		
	#endif
	// set pins directions as input
	//DATA_DIR_LCD_PORT = 0x00;
	DATA_DIR_LCD_PORT &= ~(0xFF<<DATA_SHIFT);	// for four-bit mode
	
	// put LCD in read mode (RW on)
	LCD_CTRL |= (1<<RW_SWITCH);	//read mode
	
	// put LCD in command mode (RS off)
	LCD_CTRL &= ~(1<<RS_SWITCH);	//command mode
	
	LCD_kick();
	
	// set the MC pins in output mode
	DATA_DIR_LCD_PORT |= 0xFF;		
	
	// put LCD in write mode (RW off)
	LCD_CTRL &= ~(1<<RW_SWITCH);	//write mode
	
}

void LCD_init(void)
{
	_delay_ms(20);
	LCD_is_busy();
	// set the control pins in the MC to be output
	DATA_DIR_CTRL_PORT |= (1<<EN_SWITCH) | (1<<RS_SWITCH) | (1<<RW_SWITCH);
	
	// clear output values for the ctrl pins until we need them
	LCD_CTRL &= ~((1<<EN_SWITCH) | (1<<RS_SWITCH) | (1<<RW_SWITCH));
	
	// set the data pins directions in the MC to be output
	DATA_DIR_LCD_PORT = 0xFF;
	LCD_clear_screen();	
	#ifdef EIGHT_BIT_MODE
		LCD_write_cmd(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
		LCD_write_cmd(0x02);						// required for the initialization of 4-bit mode
		LCD_write_cmd(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_write_cmd(LCD_ENTRY_MODE);
	LCD_write_cmd(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_cmd(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_write_cmd(unsigned char command)
{
	// turn RS off for command mode
	// turn RW off so you can write
	LCD_is_busy();
	#ifdef EIGHT_BIT_MODE
	LCD_DATA = command
	LCD_CTRL &= ~((1<<RS_SWITCH) | (1<<RW_SWITCH));
	LCD_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_DATA = (LCD_DATA & 0x0F) | (command & 0xF0);	// send the first four msb 
	LCD_CTRL &= ~((1<<RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	LCD_kick();
	LCD_DATA = (LCD_DATA & 0x0F) | (command << 4);		// send the second four msb
	LCD_CTRL &= ~((1<<RS_SWITCH) | (1<<RW_SWITCH));
	_delay_ms(1);
	LCD_kick();
	#endif
}

void LCD_write_char(unsigned char data)
{
	// turn RS on for data mode
	// turn RW off so you can write
	LCD_is_busy();
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	#ifdef EIGHT_BIT_MODE
	LCD_DATA = data;
	LCD_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_DATA = (LCD_DATA & 0x0F) | (data & 0xF0);	// send the first four msb
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_kick();
	LCD_DATA = (LCD_DATA & 0x0F) | (data << 4);		// send the second four msb
	LCD_CTRL &= ~(1<<RW_SWITCH);
	LCD_CTRL |= (1<<RS_SWITCH);
	_delay_ms(1);
	LCD_kick();
	#endif
}

void LCD_write_string(char* data)
{
	int count = 0;			// counter for the total chars written on the LCD display (max 32 chars)
	
	while(*data > 0)
	{
		count++;
		LCD_write_char(*data++);
		if(count == 16)		// the cursor exceeded the end of the first line
		{
			LCD_go_to_xy(2,0);
		}
		else if(count == 32)	// the cursor exceeded the end of the second line
		{
			LCD_write_cmd(LCD_CLEAR_SCREEN);
			LCD_go_to_xy(1,0);
			count = 0;
		}
	}	
}

void LCD_custom_char()
{
	LCD_write_cmd(64);
	LCD_write_char(0);
	LCD_write_char(14);
	LCD_write_char(17);
	LCD_write_char(2);
	LCD_write_char(4);
	LCD_write_char(4);
	LCD_write_char(0);
	LCD_write_char(4);
	LCD_write_cmd(LCD_BEGIN_AT_FIRST_ROW);
	LCD_write_char(0);
	_delay_ms(10);
}
