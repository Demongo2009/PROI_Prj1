
#include <iostream>
#include <random>
#include "../include/Generator.h"
#include "../include/Enums.h"
#include "../include/Map.h"
#include "../include/Tile.h"


std::random_device rD;
std::mt19937 gen(rD());

Generator::Generator(Size size, Difficulty difficulty){
  this->size = size;
  this->difficulty = difficulty;
  this->map = nullptr;
  switch (size) {
    case SMALL:
      this->tunnelsForSize = 3;
      this->stepsForSizeMax = 5;
      this->roadsForSize = 1;
      break;
    case MEDIUM:
      this->tunnelsForSize = 5;
      this->stepsForSizeMax = 6;
      this->roadsForSize = 1;
      break;
    case LARGE:
      this->tunnelsForSize = 10;
      this->stepsForSizeMax = 5;
      this->roadsForSize = 1;
      break;
  }
}

Map* Generator::generateMap(){
  initializeMap();
  for(int i=0; i<roadsForSize; ++i){
    generateRoad();
  }
  generateTiles();
  return map;
}

void Generator::generateTiles(){

}

void Generator::generateRoad(){
  std::uniform_int_distribution<> randomStartingPoint(0,size-1);
  int xStarting = randomStartingPoint(gen);
  int yStarting = randomStartingPoint(gen);
  std::uniform_int_distribution<> randomDirection(0,3);
  Direction startingDirection = (Direction)randomDirection(gen);

  int tunnelsNumber = tunnelsForSize;
  makeSingleRoad(xStarting,yStarting,tunnelsNumber,startingDirection);
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
  Direction whichDirectionNext = (Direction)dis03(gen);
  Direction cameFormDirection =(Direction)((direction+2)%4);
  if(cameFormDirection == whichDirectionNext){
    whichDirectionNext = (Direction)((whichDirectionNext+2)%4);
  }

  makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,whichDirectionNext);
  return;
}

void Generator::makeSingleTunnel(int& xNotChecked,int& yNotChecked,
   int stepsLeft, Direction direction){
  if(stepsLeft==0){
    return;
  }
  --stepsLeft;
  if(xNotChecked<0 || xNotChecked>=size || yNotChecked<0 ||yNotChecked>=size){
    return;
  }
  map->board[yNotChecked][xNotChecked].change;
  takeStep(xNotChecked,yNotChecked,direction);

  makeSingleTunnel(xNotChecked,yNotChecked,stepsLeft,direction);
  return;
}

void Generator::takeStep(int& xNotChecked,int& yNotChecked,
   Direction direction){
  switch (direction) {
    case DOWN:
      --yNotChecked;
      break;
    case RIGHT:
      ++xNotChecked;
      break;
    case UP:
      ++yNotChecked;
      break;
    case LEFT:
      --xNotChecked;
      break;
  }
}

// Direction Generator::correctDirection(int &xNotChecked,int &yNotChecked,
//   Direction direction){
//   switch (direction) {
//     case DOWN:
//       if((yNotChecked-1)<0){
//         return correctDirection(xNotChecked,yNotChecked,RIGHT);
//       }else{
//         --yNotChecked;
//       }
//       break;
//     case RIGHT:
//       if((xNotChecked+1)>=size){
//         return correctDirection(xNotChecked,yNotChecked,UP);
//       }else{
//         ++xNotChecked;
//       }
//       break;
//     case UP:
//       if((yNotChecked+1)>=size){
//         return correctDirection(xNotChecked,yNotChecked,LEFT);
//       }else{
//         ++yNotChecked;
//       }
//       break;
//     case LEFT:
//       if((xNotChecked-1)<0){
//         return correctDirection(xNotChecked,yNotChecked,DOWN);
//       }else{
//         --xNotChecked;
//       }
//       break;
//   }
//   return direction;
// }



void Generator::initializeMap(){
  map = new Map(size, difficulty);
}
