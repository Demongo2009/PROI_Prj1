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
  int linesForSizeRoad;
  int stepsForSizeMaxRoad;
  int linesForSizeBricks;
  int stepsForSizeMaxBricks;
  int linesForSizeBushes;
  int stepsForSizeMaxBushes;
  int linesForSizeIces;
  int stepsForSizeMaxIces;
  int linesForSizeWaters;
  int stepsForSizeMaxWaters;
  int roadsForSize;
  int bricksForSize;
  int bushesForSize;
  int icesForSize;
  int watersForSize;

  void initializeMap();
  void generateRoad();
  void generateTiles();
  void generateTileGroup(TileType,int,int);
  void makeSinglePolyline(int,int,int,int,Direction,TileType);
  void makeSingleLine(int&,int&,int,Direction,TileType);
  Direction correctDirection(int&,int&,Direction);
  // void takeStep(int&,int&,Direction);
public:
  Generator(Size size, Difficulty difficulty);
  Map* generateMap();
  Map* regenerateMap();
};

#endif
