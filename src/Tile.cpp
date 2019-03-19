#include <iostream>
#include "../include/Tile.h"
#include "../include/Enums.h"

TileType Tile::getType(){
  return tileType;
}

void Tile::changeTileType(TileType newTileType){
  tileType = newTileType;
}
