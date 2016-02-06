/*	serial port programming
 */
#include <stdio.h>
#include "./RS232/rs232.h"
#include "wrapper.h"

#if DEBUG_PRINT == 1
	#define DPRINT printf
#else
	#define DPRINT(...) do{}while(0)
#endif

int main(int argc, char* argv[]){
	//const char port[] = "/dev/ttyACM0";
	char mode[] = "8N1";	
	int baud_rate = 115200;
	int port_num;
	unsigned char buf[4096];

	printf("%d\n", argc);
	
	if( (port_num = openSerialPort(argv[1], baud_rate, mode) ) == -1){;
		printf("fail to open serial port\n");
		return 0;
	}

	char c = '2';	
	while(1){
		int n = RS232_PollComport(port_num, buf, sizeof(buf)-1);
		if( n > 0 ){ //read something
			buf[n] = '\0'; //mark end of string		
			printf("Received %d bytes: %s\n", n, buf);
		}
		usleep(1000000); //sleep for 1sec
		RS232_SendByte(port_num, c);
		usleep(1000);
		c++; 
		if(c>='5')
			c = '2';
		
	}

	return 0;
}
