
#include <iostream>
#include "include/Enums.h"

class Map{

  char** board;
  Size size;
  Difficulty difficulty;
  int area;

public:
  Map(Size size, Difficulty difficulty)
  :size(size), difficulty(difficulty);
  ~Map();
  void destroyTile();
}
