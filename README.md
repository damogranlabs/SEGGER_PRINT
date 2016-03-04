# SEGGER PRINT

## Quick Description
Use Segger J-link as programmer and "uart bridge". 
Same syntax as with UART library for nRF51 and STM32.


Example:
```
	void printString(char *data);	
	void printNumber(int32_t number, uint8_t base);	
	void printFloat(double number);
	void printLn(void);	
	void writeData(void *data, uint8_t dataSize);
```

