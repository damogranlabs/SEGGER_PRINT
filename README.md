SEGGER_PRINT
===================

Use Segger J-link as programmer and "uart bridge". 
Same syntax as with UART library.

Example:
- void printString(char *data);	
- void printNumber(int32_t number, uint8_t base);	
- void printFloat(double number);
- void printLn(void);	
- void writeData(void *data, uint8_t dataSize);

