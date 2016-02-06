ARG = -g -Wall -DDEBUG_PRINT=1
C = g++

a.out: main.o RS232/rs232.o wrapper.o
	$(C) main.o ./RS232/rs232.o wrapper.o $(ARG)

main.o: main.cpp RS232/rs232.h
	$(C) -c main.cpp $(ARG)

wrapper.o: wrapper.c wrapper.h
	$(C) -c wrapper.c $(ARG)

clean:
	rm -f *.out *.o
