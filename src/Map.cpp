
#include <iostream>
#include <cstdlib>
#include "../include/Map.h"
#include "../include/Enums.h"
#include "../include/Tile.h"


Map::Map(Size size, Difficulty difficulty){
  this->size = size;
  this->difficulty = difficulty;
  area = size*size;

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

void Map::printMap(){
  for(int i=0; i<size+2; ++i){
    std::cout<<'Z';
  }
  std::cout<<std::endl;

  for(int i=0; i<size; ++i){
    std::cout<<'Z';
    for(int j=0; j<size; ++j){
      std::cout<<board[i][j];
    }
    std::cout<<'Z'<<std::endl;
  }

  for(int i=0; i<size+2; ++i){
    std::cout<<'Z';
  }
  std::cout<<std::endl;
}
