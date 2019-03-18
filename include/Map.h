#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "../include/Enums.h"

class Map{

  Size size;
  Difficulty difficulty;
  int area;

public:
  char** board;
  Map(Size size, Difficulty difficulty);
  ~Map();
  void destroyTile();
  void printMap();
};

#endif
