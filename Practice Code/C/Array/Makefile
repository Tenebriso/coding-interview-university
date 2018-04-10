CC=gcc
CFLAGS=-Wall

main: main.o dynamic_array.o
	     $(CC) $(CFLAGS) -o main main.o dynamic_array.o 

main.o: main.c

dynamic_array.o: dynamic_array.c

clean:
	rm main *.o
