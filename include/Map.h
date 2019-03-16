#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "../include/Enums.h"

class Map{

  char** board;
  Size size;
  Difficulty difficulty;
  int area;

public:
  Map(Size size, Difficulty difficulty);
  ~Map();
  void destroyTile();
};

#endif
