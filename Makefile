ARG = -g -Wall -DDEBUG_PRINT=1
C = g++

a.out: main.o RS232/rs232.o
	$(C) main.o ./RS232/rs232.o $(ARG)

main.o: main.cpp RS232/rs232.h
	$(C) -c main.cpp $(ARG)

clean:
	rm -f *.out *.o
