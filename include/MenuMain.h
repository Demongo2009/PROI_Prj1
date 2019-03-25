#ifndef MENU_MAIN_H
#define MENU_MAIN_H

#include <iostream>
#include <string>

class MenuMain: public Menu{

public:
  void executePointerCommand();
  void generate();
  void edit();
  Difficulty selectDifficulty();
  Size selectSize();
  void editMap(Map*);
};

#endif
