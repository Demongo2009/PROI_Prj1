#include <iostream>
#include <string>
#include "../include/Menu.h"
#include "../include/MenuMain.h"



int main(){
  std::cout<<"Map generator. BATTLE CITY\n";
  MenuMain mainMenu = MenuMain(2,
  "[1] Generate\n[2] Exit");
  std::cout<<mainMenu.toString();

  int option;
  mainMenu.readInt(option);
  mainMenu.pointerMoveTo(option-1);


  mainMenu.executePointerCommand();
}
