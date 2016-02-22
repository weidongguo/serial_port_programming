TEAM: 			Chromium OS Failure Analysis (Project 1)
Programmer: Weidong Guo

This LINUX program takes in the port as the 1st argument, and a file as the second argument.
e.g.
$ sudo ./a.out /dev/ttyACM0 <filename>

It simply sends the file to the serial port ttyACM0 or whatever port specified with a delay of 30ms per byte
Make sure that the baud rate for the device from the other end uses the same baud rate 9600
