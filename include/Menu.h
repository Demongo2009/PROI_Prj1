#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <cstdarg>
#include "../include/Enums.h"
#include "../include/Map.h"

class Menu{
protected:
  std::string selectionTexts;
  int selectionTextsAmount;
  int pointer;
public:
  Menu(int, std::string);
  // ~Menu();
  std::string toString();
  void pointerMoveUpDown(Direction);
  void pointerMoveTo(int);
  int getPointer();
  void readInt(int&);
  friend class MenuMain;
};

#endif
