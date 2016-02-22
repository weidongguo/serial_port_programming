Team: Chromium OS Failure Analysis (project 1)
Programmer: Weidong Guo

To obtain gcc-arm-embedded on Ubuntu, try the following

Step1: Inside Ubuntu, open a terminal and input
	"sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa"

Step2: Continue to input
	"sudo apt-get update"

Step3: Continue to input to install toolchain
  "sudo apt-get install gcc-arm-embedded"

After installation,
just simply type "make",
then a *.bin file will be generated.
User can then copy this *.bin file to the flash of the mbed board

User can run ./copyToBoard.sh to do the copying automatically.

----------------------------------------------------------------

This program:

Explores power-control (for energy saving)

1) Goal: Power down unused peripherals.
	 So, the program power down all peripherals except for the GPIO for LEDs and UART0 for serial port communication

2) Experience with sleep mode and then wake up from it.
	 The program sets up a Real Time Clock (RTC) interrupt to wake up from sleep mode.
	 The interrupt is sent whenever the clock hits second 5, so it happens every minute 
	 So for the first 5 seconds, user can transfer bytes through serial port. After that, the program enters
	 into sleep mode. 
	 
	 Then, after 1 minute, 
	 The interrupt is triggered and calls an ISR to toggle the flag onSerial. At the same time, the program wakes up from sleep mode
	 because of the interrupt.
	 Now the program can transfer bytes through serial port again
	 
	 Essentailly the program will be
	 receiving bytes from serial port for 1 minute and sleep for 1 minute and keeps alternatiing.
	 
	 Please note that during the sleep mode, user can still send byte to the board, but it will not react until it wakes up from
	 the sleep mode. Most importantly, the built-in buffer for the serial port only supports roughly 16 bytes, so it cannot buffer
	 much.

