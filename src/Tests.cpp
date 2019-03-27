#include <iostream>
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include "../include/Editor.h"
#include "../include/Enums.h"
#include "../include/Generator.h"
#include "../include/Map.h"
#include "../include/Menu.h"
#include "../include/MenuMain.h"
#include "../include/Tile.h"


int main(){
  Generator g = Generator(SMALL,EASY);
  Map* map = g.generateMap();
  std::cout<<"Check if map is generated properly\n";
  assert(map!=nullptr);
  std::cout<<"OK\n";

  std::cout<<"Check if map has proper size\n";
  assert(map->getSize()!=0);
  std::cout<<"OK\n";


  std::cout<<"Check if tile changes properly\n";
  Tile t = Tile();
  t.changeTileType(WATER);
  assert(t.getTileType()==WATER);
  std::cout<<"OK\n";

  std::cout<<"Check if Menu creates properly\n";
  Menu m = Menu(1,"v");
  assert(m.getPointer()==0);
  std::cout<<"OK\n";

  std::cout<<"Check if MenuMain creates properly\n";
  MenuMain mm = MenuMain(3,"b\na\nc");
  int point = 2;
  mm.pointerMoveTo(point);
  assert(mm.getPointer()==point);
  std::cout<<"OK\n";



}
