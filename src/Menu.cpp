#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstdarg>

Menu::Menu(int argAmount, std::string ...){
  pointer = 0;
  selectionTextsAmount = argAmount;
  selectionTexts = (string*)std::malloc(argAmount * sizeof(string));
  va_list ap;
  va_start(ap,argAmount);
  for(int i=0;i<n;++i){
    selectionTexts[i]= va_arg(ap,std::string);
  }
  va_end(ap);
}

~Menu(){
  std::free(selectionTexts);
}

string Menu::toString(){
  std::stringstream ss;

  for(int i=0; i<selectionTextsAmount; ++i){
    if(i==pointer){
      ss<<"    ";
    }
    ss<<selectionTexts[i]<<"\n";
  }

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

void Menu::readIntOrEnter(int &i){
  std::cin>>i;
  while(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000000000, '\n');
    std::cout<<"Wrong input"<<std::endl;
    std::cin>>i;
  }

}
