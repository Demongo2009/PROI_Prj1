
CC = g++
CFLAGS = -Wall -g
TARGET = main
TTARGET = testing
SOURCESDIR = src
BUILDDIR = build
INCLUDEDIR = include
SOURCES = Generator.cpp Map.cpp
OBJECTS = Generator.o Map.o


$(TTARGET): Main.o Map.o Generator.o
	$(CC) $(CFLAGS) $(BUILDDIR)/Main.o $(BUILDDIR)/Generator.o $(BUILDDIR)/Map.o -o bin/$(TTARGET)

Main.o: $(INCLUDEDIR)/Generator.h $(INCLUDEDIR)/Enums.h $(INCLUDEDIR)/Map.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Main.cpp -o $(BUILDDIR)/Main.o

Map.o: $(INCLUDEDIR)/Map.h $(INCLUDEDIR)/Enums.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Map.cpp -o $(BUILDDIR)/Map.o

Generator.o: $(INCLUDEDIR)/Generator.h $(INCLUDEDIR)/Enums.h $(INCLUDEDIR)/Map.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Generator.cpp -o $(BUILDDIR)/Generator.o



.PHONY:clean
clean:
	-rm $(BUILDDIR)/*.o
