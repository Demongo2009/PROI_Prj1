
CC = g++
CFLAGS = -Wall -g
TARGET = main
SOURCESDIR = src
BUILDDIR = build
INCLUDEDIR = include
SOURCES = Generator.cpp Map.cpp
OBJECTS = $(BUILDDIR)/Main.o $(BUILDDIR)/Map.o $(BUILDDIR)/Generator.o $(BUILDDIR)/Tile.o $(BUILDDIR)/Menu.o $(BUILDDIR)/MenuMain.o $(BUILDDIR)/Editor.o

$(TARGET): Main.o Map.o Generator.o Tile.o Menu.o MenuMain.o Editor.o
	$(CC) $(CFLAGS) $(OBJECTS) -o bin/$(TARGET)

Main.o: $(INCLUDEDIR)/Menu.h $(INCLUDEDIR)/MenuMain.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Main.cpp -o $(BUILDDIR)/Main.o

Map.o: $(INCLUDEDIR)/Map.h $(INCLUDEDIR)/Enums.h $(INCLUDEDIR)/Tile.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Map.cpp -o $(BUILDDIR)/Map.o

Generator.o: $(INCLUDEDIR)/Generator.h $(INCLUDEDIR)/Enums.h $(INCLUDEDIR)/Map.h $(INCLUDEDIR)/Tile.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Generator.cpp -o $(BUILDDIR)/Generator.o

Tile.o: $(INCLUDEDIR)/Tile.h $(INCLUDEDIR)/Enums.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Tile.cpp -o $(BUILDDIR)/Tile.o

Menu.o: $(INCLUDEDIR)/Menu.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Menu.cpp -o $(BUILDDIR)/Menu.o

MenuMain.o: $(INCLUDEDIR)/Menu.h $(INCLUDEDIR)/MenuMain.h $(INCLUDEDIR)/Generator.h $(INCLUDEDIR)/Editor.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/MenuMain.cpp -o $(BUILDDIR)/MenuMain.o

Editor.o: $(INCLUDEDIR)/Editor.h
	$(CC) $(CFLAGS) -c $(SOURCESDIR)/Editor.cpp -o $(BUILDDIR)/Editor.o

.PHONY:clean
clean:
	-rm $(BUILDDIR)/*.o
