#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include "Enums.h"
#include "Tile.h"

class Map{

  Tile** board;
  Size size;
  Difficulty difficulty;
  int area;

public:
  Map(Size size, Difficulty difficulty);
  ~Map();
  void destroyTile();
  std::string toString();
  void changeTile(int,int,TileType);
};

#endif
