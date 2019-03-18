
#include <iostream>
#include <cstdlib>
#include "../include/Map.h"
#include "../include/Enums.h"


Map::Map(Size size, Difficulty difficulty){
  this->size = size;
  this->difficulty = difficulty;
  area = size*size;

  board = (char**)std::malloc(size * sizeof(char*));

  for(int i=0; i<size; ++i){
    board[i] = (char*)std::malloc(size * sizeof(char));
  }

  for(int i=0; i<size; ++i){
    for(int j=0; j<size; ++j){
      board[i][j] = ' ';
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
