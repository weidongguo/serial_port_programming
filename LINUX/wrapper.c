#include "wrapper.h"
#include "./RS232/rs232.h"
/*added by Wei*/
extern char comports[38][16]; // defined in rs232.c

int openSerialPort(const char *port, int baudrate, const char *mode){
	for(int i = 0 ; i < 38; i++){
		if(strcmp(comports[i], port) == 0){
			if(RS232_OpenComport(i, baudrate, mode))
				return -1;
			return i;
		}
	}
	return(-1); 
} 
// return -1 fail to open the port
