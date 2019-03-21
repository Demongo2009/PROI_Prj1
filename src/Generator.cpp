
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
      this->linesForSizeRoad = 3;
      this->stepsForSizeMaxRoad = 5;
      this->linesForSizeBricks = 3;
      this->stepsForSizeMaxBricks = 5;
      this->linesForSizeBushes = 3;
      this->stepsForSizeMaxBushes = 5;
      this->linesForSizeIces = 3;
      this->stepsForSizeMaxIces = 5;
      this->linesForSizeWaters = 3;
      this->stepsForSizeMaxWaters = 5;
      this->roadsForSize = 1;
      this->bricksForSize = 1;
      this->bushesForSize = 1;
      this->icesForSize = 1;
      this->watersForSize = 1;
      break;
    case MEDIUM:
      this->linesForSizeRoad = 5;
      this->stepsForSizeMaxRoad = 6;
      this->linesForSizeBricks = 3;
      this->stepsForSizeMaxBricks = 5;
      this->linesForSizeBushes = 3;
      this->stepsForSizeMaxBushes = 5;
      this->linesForSizeIces = 3;
      this->stepsForSizeMaxIces = 5;
      this->linesForSizeWaters = 3;
      this->stepsForSizeMaxWaters = 5;
      this->roadsForSize = 1;
      this->bricksForSize = 1;
      this->bushesForSize = 1;
      this->icesForSize = 1;
      this->watersForSize = 1;
      break;
    case LARGE:
      this->linesForSizeRoad = 30;
      this->stepsForSizeMaxRoad = 5;
      this->linesForSizeBricks = 3;
      this->stepsForSizeMaxBricks = 2;
      this->linesForSizeBushes = 5;
      this->stepsForSizeMaxBushes = 1;
      this->linesForSizeIces = 10;
      this->stepsForSizeMaxIces = 1;
      this->linesForSizeWaters = 4;
      this->stepsForSizeMaxWaters = 1;
      this->roadsForSize = 1;
      this->bricksForSize = 40;
      this->bushesForSize = 10;
      this->icesForSize = 5;
      this->watersForSize = 3;
      break;
  }
}

Map* Generator::generateMap(){
  initializeMap();
  generateTiles();
  // for(int i=0; i<roadsForSize; ++i){
  //   generateRoad();
  // }
  return map;
}

void Generator::generateTiles(){
  for(int i=0;i<bushesForSize; ++i){
    generateTileGroup(BUSHES,linesForSizeBushes,stepsForSizeMaxBushes);
  }
  for(int i=0;i<icesForSize; ++i){
    generateTileGroup(ICE,linesForSizeIces,stepsForSizeMaxIces);
  }
  for(int i=0;i<watersForSize; ++i){
    generateTileGroup(WATER,linesForSizeWaters,stepsForSizeMaxWaters);
  }
  for(int i=0;i<bricksForSize; ++i){
    generateTileGroup(BRICKS,linesForSizeBricks,stepsForSizeMaxBricks);
  }

}


void Generator::generateTileGroup(TileType tileType, int linesForSize, int stepsForSizeMax){
  // std::uniform_int_distribution<> randomPoint(0,size-1);
  // int xPoint = randomPoint(gen);
  // int yPoint = randomPoint(gen);
  //
  // if(map->board[yPoint][xPoint].getTileType() != EMPTY){
  //   generateTile(tileType);
  // }else{
  //   map->board[yPoint][xPoint].changeTileType(tileType);
  // }
  std::uniform_int_distribution<> randomStartingPoint(0,size-1);
  int xStarting = randomStartingPoint(gen);
  int yStarting = randomStartingPoint(gen);
  std::uniform_int_distribution<> randomDirection(0,3);
  Direction startingDirection = (Direction)randomDirection(gen);

  makeSinglePolyline(xStarting,yStarting,linesForSize,stepsForSizeMax,startingDirection,tileType);
}

void Generator::generateRoad(){
  std::uniform_int_distribution<> randomStartingPoint(0,size-1);
  int xStarting = randomStartingPoint(gen);
  int yStarting = randomStartingPoint(gen);
  std::uniform_int_distribution<> randomDirection(0,3);
  Direction startingDirection = (Direction)randomDirection(gen);

  makeSinglePolyline(xStarting,yStarting,linesForSizeRoad,stepsForSizeMaxRoad,startingDirection,ROAD);
}

void Generator::makeSinglePolyline(int xNotChecked, int yNotChecked,
   int linesLeft,int stepsForSizeMax, Direction direction,TileType tileType){
  if(linesLeft==0){
    return;
  }
  --linesLeft;
  if( xNotChecked<0 || xNotChecked>=size || yNotChecked<0 || yNotChecked>=size){
    return;
  }
  std::uniform_int_distribution<> randomStepsNumber(1,stepsForSizeMax);
  makeSingleLine(xNotChecked,yNotChecked,randomStepsNumber(gen),direction,tileType);

  std::uniform_int_distribution<> dis03(0,3);
  Direction whichDirectionNext = (Direction)dis03(gen);
  Direction cameFormDirection =(Direction)((direction+2)%4);
  if(cameFormDirection == whichDirectionNext){
    whichDirectionNext = (Direction)((whichDirectionNext+2)%4);
  }

  makeSinglePolyline(xNotChecked,yNotChecked,linesLeft,stepsForSizeMax,whichDirectionNext,tileType);
  return;
}

void Generator::makeSingleLine(int& xNotChecked,int& yNotChecked,
   int stepsLeft, Direction direction, TileType tileType){
  if(stepsLeft==0){
    return;
  }
  --stepsLeft;
  if(xNotChecked<0 || xNotChecked>=size || yNotChecked<0 ||yNotChecked>=size){
    return;
  }
  map->board[yNotChecked][xNotChecked].changeTileType(tileType);
  // takeStep(xNotChecked,yNotChecked,direction);
  Direction nextDirection = correctDirection(xNotChecked,yNotChecked,direction);

  // makeSingleLine(xNotChecked,yNotChecked,stepsLeft,direction);
  makeSingleLine(xNotChecked,yNotChecked,stepsLeft,nextDirection,tileType);
  return;
}

// void Generator::takeStep(int& xNotChecked,int& yNotChecked,
//    Direction direction){
//   switch (direction) {
//     case DOWN:
//       --yNotChecked;
//       break;
//     case RIGHT:
//       ++xNotChecked;
//       break;
//     case UP:
//       ++yNotChecked;
//       break;
//     case LEFT:
//       --xNotChecked;
//       break;
//   }
// }

Direction Generator::correctDirection(int &xNotChecked,int &yNotChecked,
  Direction direction){
  switch (direction) {
    case DOWN:
      if((yNotChecked-1)<0 ){
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
      if((xNotChecked-1)<0 ){
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
