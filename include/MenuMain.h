#ifndef MENU_MAIN_H
#define MENU_MAIN_H

#include <iostream>
#include <string>
#include "../include/Menu.h"
#include "../include/Editor.h"

class MenuMain: public Menu{

public:
  MenuMain(int, std::string);
  void executePointerCommand();
  void generate();
  void edit();
  Difficulty selectDifficulty();
  Size selectSize();
  void editMap(Map*);
  bool wantToEdit(Map*);
  void changeSelectedTile(Editor);
};

#endif
