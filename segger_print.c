/*
 *	Created by: Domen Jurkovic, 9-Feb-2016
 *	Arduino like functions for serial printing of numbers and strings via Segger J-link
 
 * https://www.segger.com/jlink-rtt.html
*/

#include "segger_print.h"

/****************************************************************************************/
/* Segger print functions */
/****************************************************************************************/
uint32_t segger_send_byte(uint8_t byte){
	return SEGGER_RTT_Write(0, &byte, 1);	
}

// currently only single receive character is implemented
uint8_t segger_receive_byte(void){
	uint8_t byte = 0;
	SEGGER_RTT_Read(0, &byte, 1); 
	return byte;
}


/****************************************************************************************/
/* PRINT/WRITE FUNCTIONS */
/****************************************************************************************/

/*
	Send/print character/string over UART. 
	Printable data for viewing on terminal.
	Call this function:		printString("test data");
	Data must be string.
*/
void printString(char *data){
	uint16_t i;
	uint16_t str_length = strlen(data);
	for(i = 0; i < str_length; i++)
	{
		segger_send_byte(data[i]);
	}
}

/*
	Send/print unsigned or signed number over UART. 
	Printable data for viewing on terminal.
	Call this function:		printNumber(number, DEC);		printNumber(2246, DEC);	
	Base: DEC, HEX, OCT, BIN
	Data must be number, int32_t.
*/
void printNumber(int32_t number, uint8_t base){
	if (number < 0) 
	{
		printString("-");
		number = -number;
		printUnsignedNumber(number, base);
	}
	else 
	{
		printUnsignedNumber(number, base);
	}
}
//print WITH new line and carriage return
void printStringLn(char *data){
	uint16_t i;
	uint16_t str_length = strlen(data);
	for(i = 0; i < str_length; i++)
	{
		segger_send_byte(data[i]);
	}
	printLn();
}

/*
	Send/print unsigned or signed number over UART. 
	Printable data for viewing on terminal.
	Call this function:		printNumber(number, DEC);		printNumber(2246, DEC);	
	Base: DEC, HEX, OCT, BIN
	Data must be number, int32_t.
*/
void printNumberLn(int32_t number, uint8_t base){
	if (number < 0) 
	{
		printString("-");
		number = -number;
		printUnsignedNumber(number, base);
	}
	else 
	{
		printUnsignedNumber(number, base);
	}
	printLn();
}

void printLn(){
	printString("\r\n");
}

/*
	Send raw data over UART. 
	Not "printable" data.
	Call this function:		writeData(&data, sizeof(data));
	Data can be any type.
*/
void writeData(void *data, uint8_t dataSize){
  uint8_t i, d;
  
  d = dataSize/2;
 
  for(i = 0; i < d; i++)
  {
    segger_send_byte(*( ((uint16_t *)data) + i ) );
  }
 
}

/*
	This is "private" function. It is used by other functions like: printNumber(int32_t number, uint8_t base). 
	However, it can be used by user.
	Send/print unsigned number over UART. 
	Printable data for viewing on terminal.
	Call this function:		printUnsignedNumber(number, DEC);		printUnsignedNumber(2246, DEC);	
	Base: DEC, HEX, OCT, BIN
	Data must be number, int32_t.
*/
void printUnsignedNumber(uint32_t n, uint8_t base){
	char buf[8 * sizeof(long) + 1]; // Assumes 8-bit chars plus zero byte.
	char *str = &buf[sizeof(buf) - 1];
	unsigned long m;
	char c;
  *str = '\0';

  //prevent crash if called with base == 1
  if (base < 2) base = 10;

  do 
	{
    m = n;
    n /= base;
    c = m - base * n;
    *--str = c < 10 ? c + '0' : c + 'A' - 10;
	} while(n);

	printString(str); 
}

// pay attention on "double" type range
// ? - max 6 digits after decimal point?
void printFloat(double number){
	char float_as_string[20];
	sprintf(float_as_string, "%f", number);
  printString(float_as_string);
}

void printFloatLn(double number){
	printFloat(number);
	printLn();
}
