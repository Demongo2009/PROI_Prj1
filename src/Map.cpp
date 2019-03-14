
#include <iostream>
#include <cstdlib>
#include "include/Map.h"
#include "include/Enum.h"


Map::Map(Size size, Difficulty difficulty){
  area = size*size;
  board = std::calloc(size, sizeof(char*));
  int i=0;
  while(i<size){
    board[i] = std::calloc(size, sizeof(char));
  }
}

Map::~Map(){

  while(){

  }

}
