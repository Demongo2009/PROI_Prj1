#ifndef GENERATOR_H
#define GENERATOR_H

#include <iostream>
#include "../include/Enums.h"
#include "../include/Map.h"


class Generator{

  Size size;
  Difficulty difficulty;
  Map map;

  void initializeMap();
  void generateRoad();
  void makeSingleRoad();

public:
  Generator(Size, Difficulty);
  Map generateMap();
  Map regenerateMap();
};

#endif
