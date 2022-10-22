CC=gcc
CFLAGS= -std=c11 -Werror -Wall 
LDLIBS= -lm
OUTPUT=ps2

all: $(OUTPUT)

$(OUTPUT): main.o bmp.o playfair.o 
	cppcheck --enable=performance,unusedFunction --error-exitcode=1 *.c
	$(CC) $(CFLAGS) main.o bmp.o playfair.o $(LDLIBS) -o $(OUTPUT)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c $(LDLIBS) -o main.o
	
playfair.o: playfair.c playfair.h
	$(CC) $(CFLAGS) -c playfair.c $(LDLIBS) -o playfair.o
	
bmp.o: bmp.c bmp.h
	$(CC) $(CFLAGS) -c bmp.c $(LDLIBS) -o bmp.o
	
clean: 
	rm -rf $(OUTPUT) *.o


