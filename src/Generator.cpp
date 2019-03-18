
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
  int tunnelsNumber = tunnelsForSize;
  switch (startingDirection) {
    case DOWN:
      makeSingleRoad(xStarting,yStarting,tunnelsNumber,DOWN);
      break;
    case RIGHT:
      makeSingleRoad(xStarting,yStarting,tunnelsNumber,RIGHT);
      break;
    case UP:
      makeSingleRoad(xStarting,yStarting,tunnelsNumber,UP);
      break;
    case LEFT:
      makeSingleRoad(xStarting,yStarting,tunnelsNumber,LEFT);
      break;
  }

}

void Generator::makeSingleRoad(int xNotChecked, int yNotChecked,
   int tunnelsLeft, Direction direction){
  if(tunnelsLeft==0){
    return;
  }
  --tunnelsLeft;
  if( xNotChecked<0 || xNotChecked>=size || yNotChecked<0 || yNotChecked>=size){
    return;
  }
  std::uniform_int_distribution<> randomStepsNumber(1,stepsForSizeMax);
  makeSingleTunnel(xNotChecked,yNotChecked,randomStepsNumber(gen),direction);

  std::uniform_int_distribution<> dis03(0,3);
  int whichDirectionNext = dis03(gen);
  int cameFormDirection = (direction+2)%4;
  if(cameFormDirection == whichDirectionNext){
    whichDirectionNext = (whichDirectionNext+2)%4;
  }

  switch (whichDirectionNext) {
    case DOWN:
      makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,DOWN);
      break;
    case RIGHT:
      makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,RIGHT);
      break;
    case UP:
      makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,UP);
      break;
    case LEFT:
      makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,LEFT);
      break;
  }
  return;
}

void Generator::makeSingleTunnel(int &xNotChecked,int &yNotChecked,
   int stepsLeft, Direction direction){
  if(stepsLeft==0){
    return;
  }
  --stepsLeft;
  if( xNotChecked<0 || xNotChecked>=size || yNotChecked<0 || yNotChecked>=size){
    return;
  }
  map->board[yNotChecked][xNotChecked] = 'D';

  switch (direction) {
    case DOWN:
      --yNotChecked;
      makeSingleTunnel(xNotChecked,yNotChecked,stepsLeft,DOWN);
      break;
    case RIGHT:
      ++xNotChecked;
      makeSingleTunnel(xNotChecked,yNotChecked,stepsLeft,RIGHT);
      break;
    case UP:
      ++yNotChecked;
      makeSingleTunnel(xNotChecked,yNotChecked,stepsLeft,UP);
      break;
    case LEFT:
      --xNotChecked;
      makeSingleTunnel(xNotChecked,yNotChecked,stepsLeft,LEFT);
      break;
  }
  return;
}



void Generator::initializeMap(){
  map = new Map(size, difficulty);
}
