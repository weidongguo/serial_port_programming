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
then a .bin file will be generated.
User can then copy this .bin file to the flash of the mbed board


----------------------------------------------------------------

This program:

Explores power-control (for energy saving)

1) Goal: Power down unused peripherals.
	 So, the program power down all peripherals except for the GPIO for LEDs and UART0 for serial port communication

2) Try getting in to sleep mode and then wake up from it.
	 The program sets up a Real Time Clock (RTC) interrupt to wake up from sleep mode.
	 The interrupt is sent whenever the clock hits second 5, so it happens every minute 
	 This interrupt calls an ISR to toggle the second and third LED.
