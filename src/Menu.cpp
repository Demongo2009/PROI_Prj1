#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstdarg>
#include "../include/Menu.h"

// Menu::Menu(int argAmount, std::string ...){
//   pointer = 0;
//   selectionTextsAmount = argAmount;
//   selectionTexts = (std::string*)std::malloc(argAmount * sizeof(std::string));
//   va_list ap;
//   va_start(ap,argAmount);
//   for(int i=0;i<argAmount;++i){
//     selectionTexts[i]= va_arg(ap,std::string);
//   }
//   va_end(ap);
// }
Menu::Menu(int argAmount, std::string text){
  pointer = 0;
  selectionTextsAmount = argAmount;
  selectionTexts = text;
}


// Menu::~Menu(){
//   std::free(selectionTexts);
// }

std::string Menu::toString(){
  std::stringstream ss;

  ss<<selectionTexts<<"\n";

  return ss.str();
}

void Menu::pointerMoveUpDown(Direction direction){
  switch (direction) {
    case UP:
      --pointer;
      break;
    case DOWN:
      ++pointer;
      break;
    default:
      break;
  }
  if(pointer<0){
    pointer = selectionTextsAmount-1;
  }
  if(pointer>=selectionTextsAmount){
    pointer = 0;
  }
  return;
}

void Menu::pointerMoveTo(int position){
  if(position>=selectionTextsAmount){
    position=selectionTextsAmount-1;
  }
  if(position<0){
    position=0;
  }
  pointer = position;
}

int Menu::getPointer(){
  return pointer;
}

void Menu::readInt(int &i){
  std::cin>>i;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000000000, '\n');
    std::cout<<"Wrong input"<<std::endl;
    std::cin>>i;
  }

}
