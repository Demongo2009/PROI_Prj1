
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../include/Generator.h"
#include "../include/Enums.h"
#include "../include/Map.h"

Generator::Generator(Size size, Difficulty difficulty){
  this->size = size;
  this->difficulty = difficulty;
  initializeMap();
}

Map Generator::generateMap(){
  initializeMap();
  generateRoad();
}

void Generator::generateRoad(){
  std::srand(std::time(nullptr));

  int maxEnumeratedBorder = size*2 + (size-2)*2;
  int startingPoint = std::rand()%maxEnumeratedBorder;
  int singleBorderIndex = startingPoint%size;
  switch (startingPoint%4) {
    case 0:
      makeSingleRoad(singleBorderIndex,0,DOWN);
      break;
    case 1:
      makeSingleRoad(size-1, singleBorderIndex,RIGHT);
      break;
    case 2:
      makeSingleRoad(singleBorderIndex,size-1,UP);
      break;
    case 3:
      makeSingleRoad(0,singleBorderIndex,LEFT);
      break;
  }

}

void Generator::makeSingleRoad(int xNotChecked, int yNotChecked, Direction cameFromDirection){
  if( xNotChecked<0 || xNotChecked>=size || yNotChecked<0 || yNotChecked>=size){
    return;
  }
  board[yNotChecked][xNotChecked] = 'D';
  int whichDirectionNext = std::rand()%4;
  if(cameFromDirection == whichDirectionNext){
    whichDirectionNext= (whichDirectionNext+2)%4;
  }

  switch (whichDirectionNext) {
    case DOWN:
      makeSingleRoad(yNotChecked-1,xNotChecked,UP);
      break;
    case RIGHT:
      makeSingleRoad(yNotChecked,xNotChecked+1,LEFT)
      break;
    case UP:
      makeSingleRoad(yNotChecked+1,xNotChecked,DOWN);
      break;
    case LEFT:
      makeSingleRoad(yNotChecked,xNotChecked-1,RIGHT);
      break;
  }

  return;

}



void Generator::initializeMap(){
  map = new Map(size, difficulty);
}
