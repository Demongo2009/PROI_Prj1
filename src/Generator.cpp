
#include <iostream>
#include <random>
#include "../include/Generator.h"
#include "../include/Enums.h"
#include "../include/Map.h"

// Generator::Generator(Size size, Difficulty difficulty){
//   this->size = size;
//   this->difficulty = difficulty;
//   map = new Map(size, difficulty);
// }

std::random_device rD;
std::mt19937 gen(rD());


Map* Generator::generateMap(){
  initializeMap();
  generateRoad();
  generateRoad();
  generateRoad();
  return map;
}

void Generator::generateRoad(){
  // int maxEnumeratedBorder = size*2 + (size-2)*2;
  // std::uniform_int_distribution<> dis03(0,3);
  // int startingWall = dis03(gen);
  //
  // std::uniform_int_distribution<> dis0size01(0,size-1);
  std::uniform_int_distribution<> randomStartingPoint(0,size/2-1);
  int xStarting = randomStartingPoint(gen);
  int yStarting = randomStartingPoint(gen);
  std::uniform_int_distribution<> randomDirection(0,3);
  int startingDirection = randomDirection(gen);
  switch (startingDirection) {
    case DOWN:
      makeSingleRoad(xStarting,yStarting,DOWN);
      break;
    case RIGHT:
      makeSingleRoad(xStarting,yStarting,RIGHT);
      break;
    case UP:
      makeSingleRoad(xStarting,yStarting,UP);
      break;
    case LEFT:
      makeSingleRoad(xStarting,yStarting,LEFT);
      break;
  }

}

void Generator::makeSingleRoad(int xNotChecked, int yNotChecked, Direction direction){
  if( xNotChecked<0 || xNotChecked>=size || yNotChecked<0 || yNotChecked>=size){
    return;
  }
  map->board[yNotChecked][xNotChecked] = 'D';

  std::uniform_int_distribution<> dis03(0,3);
  int whichDirectionNext = dis03(gen);
  if(cameFromDirection == whichDirectionNext){
    whichDirectionNext= (whichDirectionNext+2)%4;
  }

  switch (whichDirectionNext) {
    case DOWN:
      makeSingleRoad(xNotChecked,yNotChecked-1,UP);
      break;
    case RIGHT:
      makeSingleRoad(xNotChecked+1,yNotChecked,LEFT);
      break;
    case UP:
      makeSingleRoad(xNotChecked,yNotChecked+1,DOWN);
      break;
    case LEFT:
      makeSingleRoad(xNotChecked-1,yNotChecked,RIGHT);
      break;
  }

  return;

}



void Generator::initializeMap(){
  map = new Map(size, difficulty);
}
