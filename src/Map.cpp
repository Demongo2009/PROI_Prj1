
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "../include/Map.h"
#include "../include/Enums.h"
#include "../include/Tile.h"


Map::Map(Size size, Difficulty difficulty){
  this->size = size;
  this->difficulty = difficulty;
  this->area = size*size;

  board = (Tile**)std::malloc(size * sizeof(Tile*));

  for(int i=0; i<size; ++i){
    board[i] = (Tile*)std::malloc(size * sizeof(Tile));
  }

  for(int i=0; i<size; ++i){
    for(int j=0; j<size; ++j){
      board[i][j] = Tile();
    }
  }
}

Map::~Map(){

  for(int i=0; i<size; ++i){
    std::free(board[i]);
  }

  std::free(board);
}

Size Map::getSize(){
  return this->size;
}

std::string Map::toString(){
  std::stringstream ss;
  for(int i=0; i<size+2; ++i){
    ss<<"Z";
  }
  ss<<"\n";

  for(int i=0; i<size; ++i){
    ss<<"Z";
    for(int j=0; j<size; ++j){
      ss<<board[i][j];
    }
    ss<<"Z\n";
  }

  for(int i=0; i<size+2; ++i){
    ss<<"Z";
  }
  ss<<"\n";
  return ss.str();
}

void Map::changeTile(int x, int y, TileType tileType){
  board[y][x].changeTileType(tileType);
}
