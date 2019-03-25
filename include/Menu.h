#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

class Menu{
protected:
  string* selectionTexts;
  int selectionTextsAmount;
  int pointer;
public:
  Menu(int, std::string ...);
  ~Menu();
  string toString();
  void pointerMoveUpDown(Direction);
  void pointerMoveTo(int);
  int getPointer();
  void readInt(int);
  void readChar();
};

#endif
