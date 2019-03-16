
CC = g++
CFLAGS = -Wall -g
TARGET = main
TTARGET = testing
SOURCESDIR = src
BUILDDIR = build
INCLUDEDIR = include
SOURCES = Generator.cpp Map.cpp
OBJECTS = Generator.o Map.o


$TARGET: $(BUILDDIR)/Map.o $(BUILDDIR)/Generator.o 
	$(CC) $(CFLAGS)  build/*.o -o bin/$(TTARGET)

$(BUILDDIR)/Map.o: $(INCLUDEDIR)/Map.h $(INCLUDEDIR)/Enums.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Map.cpp -o $(BUILDDIR)/Map.o

$(BUILDDIR)/Generator.o: $(INCLUDEDIR)/Generator.h $(INCLUDEDIR)/Enums.h $(INCLUDEDIR)/Map.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Generator.cpp -o $(BUILDDIR)/Generator.o



.PHONY:clean
clean:
	-rm $(BUILDDIR)/*.o
