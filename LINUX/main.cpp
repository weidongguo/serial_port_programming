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

/* void transferFileSerialPort(int file_fd, int port_num, int ms) 
 * @brief			transfer a file byte by byte through a serial port
 * @param[in]	int file_fd 	-file descriptor for the file to be transfered
 * 						int port_num	-port_num that is used by the RS232 library
 														 it actually it's an key for a file descriptor
														 pointing to the port(e.g. /dev/ttyACM0)
 *						int ms				-delay between byte 
 * @return		none
 *						
 */
void transferFileToSerialPort(int file_fd, int port_num, int ms){
	char c; unsigned char readByte;
	while( read(file_fd, &c, 1) == 1 ){
		RS232_SendByte(port_num, c);			
		if( RS232_PollComport(port_num, &readByte, 1) == 1)
			printf("%c", readByte, readByte); fflush(stdout); //may need to comment this out, since sys.call add delay too
		usleep(ms*1000); //may need to add delay here, will test that
	}
	printf("\n**End of file transfer**\n");
}


int main(int argc, char* argv[]){
	//const char port[] = "/dev/ttyACM0";
	char mode[] = "8N1";	
	int baud_rate = 9600;//115200;
	int port_num;
	int file_fd;

	if(argc != 3){
		printf("Invalid command line argument\ne.g. sudo ./a.out /dev/ttyACM0 filename\n");	
		return 0;
	}
	if( (port_num = openSerialPort(argv[1], baud_rate, mode) ) == -1){;
		printf("fail to open serial port\n");
		return 0;
	}
	
	if( (file_fd = open(argv[2], O_RDWR)) == -1 ){	
		printf("Invalid filename\n");
		return 0;
	}
	
	transferFileToSerialPort(file_fd, port_num, 30);			

	return 0;
}
