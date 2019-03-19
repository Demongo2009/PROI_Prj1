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
  int roadsForSize;

  void initializeMap();
  void generateRoad();
  void makeSingleRoad(int,int,int, Direction);
  void makeSingleTunnel(int&,int&,int, Direction);
  // Direction correctDirection(int&,int&,Direction);
  void takeStep(int&,int&,Direction);


public:
  Generator(Size size, Difficulty difficulty)
  :size(size)
  ,difficulty(difficulty)
  ,map(nullptr){
    switch (size) {
      case SMALL:
        this->tunnelsForSize = 3;
        this->stepsForSizeMax = 5;
        this->roadsForSize = 3;
        break;
      case MEDIUM:
        this->tunnelsForSize = 5;
        this->stepsForSizeMax = 6;
        this->roadsForSize = 5;
        break;
      case LARGE:
        this->tunnelsForSize = 10;
        this->stepsForSizeMax = 5;
        this->roadsForSize = 7;
        break;
    }
  }
  Map* generateMap();
  Map* regenerateMap();
};

#endif
