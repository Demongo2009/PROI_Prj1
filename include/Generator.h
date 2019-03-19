#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include "../include/Enums.h"
#include "../include/Map.h"
#include "../include/Tile.h"


class Generator{
  Size size;
  Difficulty difficulty;
  Map* map;
  int tunnelsForSize;
  int stepsForSizeMax;
  int roadsForSize;

  void initializeMap();
  void generateRoad();
  void generateTiles();
  void makeSingleRoad(int,int,int, Direction);
  void makeSingleTunnel(int&,int&,int, Direction);
  // Direction correctDirection(int&,int&,Direction);
  void takeStep(int&,int&,Direction);
public:
  Generator(Size size, Difficulty difficulty);
  Map* generateMap();
  Map* regenerateMap();
};

#endif
