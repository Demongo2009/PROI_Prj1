#ifndef TILE_H
#define TILE_H

#include <iostream>
#include "Enums.h"

class Tile{
  TileType tileType;
public:
  Tile():tileType(EMPTY){};
  Tile(TileType tileType):tileType(tileType){};
  TileType getType();
  void changeTileType(TileType);

  friend std::ostream& operator<<(std::ostream& os, const Tile& t);
};

std::ostream& operator<<(std::ostream& os, const Tile& t){
  char c;
  switch (t.tileType) {
    case EMPTY:
      c = ' ';
      break;
    case ROAD:
      c = 'D';
      break;
    case BUSHES:
      c = '#';
      break;
    case ICE:
      c = '@';
      break;
    case WATER:
      c = 'M';
      break;
    case BRICKS:
      c = 'H';
      break;
    case IRON:
      c = 'Z';
      break;
  }
  os << c;
  return os;
}

#endif
