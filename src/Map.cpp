
#include <iostream>
#include <cstdlib>
#include "../include/Map.h"
#include "../include/Enums.h"


Map::Map(Size size, Difficulty difficulty){
  this->size = size;
  this->difficulty = difficulty;
  area = size*size;
  board = (char**)std::malloc(size * sizeof(char*));
  int i=0;
  while(i<size){
    board[i] = (char*)std::malloc(size * sizeof(char));
    ++i;
  }
}

Map::~Map(){
  int i=0;
  while(i<size){
    std::free(board[i]);
    ++i;
  }
  std::free(board);

}
