
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
  Direction startingDirection = (Direction)randomDirection(gen);
  int tunnelsNumber = tunnelsForSize;
  makeSingleRoad(xStarting,yStarting,tunnelsNumber,startingDirection);
  // switch (startingDirection) {
  //   case DOWN:
  //     break;
  //   case RIGHT:
  //     makeSingleRoad(xStarting,yStarting,tunnelsNumber,RIGHT);
  //     break;
  //   case UP:
  //     makeSingleRoad(xStarting,yStarting,tunnelsNumber,UP);
  //     break;
  //   case LEFT:
  //     makeSingleRoad(xStarting,yStarting,tunnelsNumber,LEFT);
  //     break;
  // }

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

  makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,direction);
  // switch (whichDirectionNext) {
  //   case DOWN:
  //     break;
  //   case RIGHT:
  //     makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,RIGHT);
  //     break;
  //   case UP:
  //     makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,UP);
  //     break;
  //   case LEFT:
  //     makeSingleRoad(xNotChecked,yNotChecked,tunnelsLeft,LEFT);
  //     break;
  // }
  return;
}

void Generator::makeSingleTunnel(int &xNotChecked,int &yNotChecked,
   int stepsLeft, Direction direction){
  if(stepsLeft==0){
    return;
  }
  --stepsLeft;
  map->board[yNotChecked][xNotChecked] = 'D';
  direction = correctDirection(xNotChecked,yNotChecked,direction);

  makeSingleTunnel(xNotChecked,yNotChecked,stepsLeft,direction);
  return;
}

Direction Generator::correctDirection(int &xNotChecked,int &yNotChecked,
  Direction direction){
  switch (direction) {
    case DOWN:
      if((yNotChecked-1)<0){
        return correctDirection(xNotChecked,yNotChecked,RIGHT);
      }else{
        --yNotChecked;
      }
      break;
    case RIGHT:
      if((xNotChecked+1)>=size){
        return correctDirection(xNotChecked,yNotChecked,UP);
      }else{
        ++xNotChecked;
      }
      break;
    case UP:
      if((yNotChecked+1)>=size){
        return correctDirection(xNotChecked,yNotChecked,LEFT);
      }else{
        ++yNotChecked;
      }
      break;
    case LEFT:
      if((xNotChecked-1)<0){
        return correctDirection(xNotChecked,yNotChecked,DOWN);
      }else{
        --xNotChecked;
      }
      break;
  }
  return direction;
}



void Generator::initializeMap(){
  map = new Map(size, difficulty);
}
