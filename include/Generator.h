#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include "../include/Enums.h"
#include "../include/Map.h"


class Generator{

  Size size;
  Difficulty difficulty;
  Map* map;
  int tunnelsForSize;
  int stepsForSizeMax;

  void initializeMap();
  void generateRoad();
  void makeSingleRoad(int,int,int, Direction);
  void makeSingleTunnel(int&,int&,int, Direction);
  Direction correctDirection(int&,int&,Direction);


public:
  Generator(Size size, Difficulty difficulty)
  :size(size)
  ,difficulty(difficulty)
  ,map(nullptr){
    switch (size) {
      case SMALL:
        tunnelsForSize = 3;
        stepsForSizeMax = 5;
        break;
      case MEDIUM:
        tunnelsForSize = 5;
        stepsForSizeMax = 6;
        break;
      case LARGE:
        tunnelsForSize = 10;
        stepsForSizeMax = 5;
        break;
    }
  }
  Map* generateMap();
  Map* regenerateMap();
};

#endif
