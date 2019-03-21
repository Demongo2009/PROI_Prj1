#include <iostream>
#include "../include/Tile.h"
#include "../include/Enums.h"

TileType Tile::getTileType(){
  return tileType;
}

void Tile::changeTileType(TileType newTileType){
  tileType = newTileType;
}
