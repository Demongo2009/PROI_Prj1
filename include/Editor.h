#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include "../include/Map.h"


class Editor{
  Map *map;
  int pointerX;
  int pointerY;
public:
  Editor(Map* map):map(map){};
  void setPointerTo(int, int);
  void pointerGoDirection();
  void changeTile(TileType);
  int getPointerX();
  int getPointerY();
};

#endif
