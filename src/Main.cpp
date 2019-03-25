#include <iostream>
#include <string>
#include "../include/Enums.h"
#include "../include/Map.h"
#include "../include/Generator.h"



int main(){
  std::cout<<"tak"<<std::endl;
  Generator* generator = new Generator(LARGE,EASY);
  Map* map = generator->generateMap();
  std::cout<<map->toString();
}
