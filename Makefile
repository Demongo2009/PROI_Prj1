
CC = g++
CFLAGS = -Wall -g
TARGET = animals
SOURCES = Main.cpp
OBJECTS = Main.o


$TARGET: Main.o
	$(CC) $(CFLAGS)  build/$(OBJECTS) -o bin/$(TARGET)

Main.o:
	$(CC) $(CFLAGS) -c src/Main.cpp -o build/Main.o

.PHONY:clean
clean:
	-rm build/*.o 
