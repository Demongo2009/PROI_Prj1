#include <iostream>
#include "../include/Editor.h"

void Editor::setPointerTo(int x, int y){
  int size = map->getSize();
  if(x<0){
    x=0;
  }
  if(x>= size){
    x=size-1;
  }
  this->pointerX = x;
  if(y<0){
    y=0;
  }
  if(y>=size){
    y=size-1;
  }
  this->pointerY = y;
}

void Editor::changeTile(TileType tileType){
  map->changeTile(pointerX,pointerY,tileType);
}

int Editor::getPointerX(){
  return this->pointerX;
}

int Editor::getPointerY(){
  return this->pointerY;
}
