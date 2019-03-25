#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>

class Editor{
  Map *map;
  int pointerX;
  int pointerY;
public:
  Editor(Map* map):map(map){};
  void setPointerTo();
  void pointerGoDirection();
  void changeTile(TileType);

};

#endif
