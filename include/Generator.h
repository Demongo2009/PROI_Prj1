
#include <iostream>
#include "include/Enums.h"


class Generator{

  Size size;
  Difficulty difficulty;

  Map generateRoad();

public:
  Generator(Size, Difficulty);
  Map generateMap();
  Map regenerateMap();
}
