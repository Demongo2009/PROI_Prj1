#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "Enums.h"
#include "Tile.h"

class Map{

  Size size;
  Difficulty difficulty;
  int area;

public:
  Tile** board;
  Map(Size size, Difficulty difficulty);
  ~Map();
  void destroyTile();
  void printMap();
};

#endif
