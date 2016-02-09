SEGGER_PRINT
===================

Use Segger J-link as programmer and "uart bridge". 
Same syntax as with UART library.

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

