 /*
 * Arduino like functions for serial printing of numbers and strings
 * Created by: Domen Jurkovic, 25.12.2015
 
 * https://www.segger.com/jlink-rtt.html
 */

#ifndef SEGGER_PRINT_H
#define SEGGER_PRINT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

//uint8_t base:
#define	DEC	10
#define BIN 2
#define HEX 16
#define OCT 8

/****************************************************************************************/
/* Segger print functions */
/****************************************************************************************/
uint32_t segger_send_byte(uint8_t byte);
uint8_t segger_receive_byte(void);


/****************************************************************************************/
/* PRINT/WRITE FUNCTIONS */
/****************************************************************************************/
//print WITHOUT new line and carriage return
void printString(char *data);	//send/print string overserial port UART.
void printNumber(int32_t number, uint8_t base);	//send/print SINGED/UNSIGNED int32_t number over serial port UART.
void printFloat(double number);

//print WITH new line and carriage return
void printStringLn(char *data);	//send/print string overserial port UART.
void printNumberLn(int32_t number, uint8_t base);	//send/print SINGED/UNSIGNED number over serial port UART.
void printFloatLn(double number);
void printLn(void);	//print new line and carriage return

//send raw data, any type.
void writeData(void *data, uint8_t dataSize);

//"private" function. Can be used if needed.
void printUnsignedNumber(uint32_t n, uint8_t base);	//send/print UNSIGNED uint32_t over serial port UART.

#endif

