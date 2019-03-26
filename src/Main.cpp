#include <iostream>
#include <string>
#include "../include/Menu.h"
#include "../include/MenuMain.h"



int main(){
  std::cout<<"Map generator. BATTLE CITY\n";
  MenuMain mainMenu = MenuMain(2,
  "[1] Generate",
  "[2] Exit");

  int option;
  mainMenu.readInt(option);
  mainMenu.pointerMoveTo(option-1);
  std::cout<<mainMenu.toString();

  mainMenu.executePointerCommand();
}
