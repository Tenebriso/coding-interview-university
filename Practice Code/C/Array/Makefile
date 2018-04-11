CC=gcc
CFLAGS=-Wall -fstack-protector --param=ssp-buffer-size=4 -D_FORTIFY_SOURCE=2 -Wformat -Wformat-security -Werror=format-security

main: main.o dynamic_array.o
	     $(CC) $(CFLAGS) -o main main.o dynamic_array.o 

main.o: main.c
	$(CC) $(CFLAGS) -c main.c
dynamic_array.o: dynamic_array.c
	$(CC) $(CGFLAGS) -c dynamic_array.c

clean:
	rm main *.o
