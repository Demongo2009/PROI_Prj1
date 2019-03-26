
#include <iostream>
#include "../include/MenuMain.h"
#include "../include/Enums.h"
#include "../include/Generator.h"
#include "../include/Editor.h"
#include <cstdarg>
#define DIFFICULTY_AMOUNT 3
#define EDITOR_OPTIONS 3
#define TILE_TYPE_AMOUNT 5

MenuMain::MenuMain(int argAmount, std::string text):Menu(argAmount, text){

}

void MenuMain::executePointerCommand(){
  switch (pointer) {
    case 0:
      generate();
      break;
    case 1:
      exit(0);
      break;
  }
}

void MenuMain::generate(){
  Difficulty generatorDifficulty = selectDifficulty();
  Size generatorSize = selectSize();

  Generator generator = Generator(generatorSize,generatorDifficulty);
  Map* map = generator.generateMap();

  if(wantToEdit(map)){
    editMap(map);
  }else{
    exit(0);
  }
}

bool MenuMain::wantToEdit(Map* map){
  std::cout<<map->toString();
  std::cout<<"Do you want to edit map?\n";
  Menu yesNo = Menu(2,
    "[1] Yes\n[2] No");
  std::cout<<yesNo.toString();

  int option;
  readInt(option);
  yesNo.pointerMoveTo(option-1);


  switch(yesNo.getPointer()){
    case 0:
      return true;
      break;
    case 1:
      return false;
      break;
  }
}

void MenuMain::editMap(Map* map){
  Editor editor = Editor(map);
  std::cout<<map->toString();

  Menu editorMenu = Menu(EDITOR_OPTIONS,
    "[1] Go to tile [x,y]\n[2] Change selected tile to [BRICKS,BUSHES,ICE,WATER,EMPTY]\n[3] Quit editing and exit");
  while(1){
    std::cout<<editorMenu.toString();
    std::cout<<"Selected tile ["<<editor.getPointerX()<<", "<<editor.getPointerY()<<"]\n";

    int option;
    readInt(option);
    editorMenu.pointerMoveTo(option-1);


    switch (editorMenu.getPointer()) {
      case 0:
        int x;
        std::cout<<"Enter x:\n";
        readInt(x);
        int y;
        std::cout<<"Enter y:\n";
        readInt(y);
        editor.setPointerTo(x,y);
        break;
      case 1:
        changeSelectedTile(editor);
        break;
      case 2:
        exit(0);
        break;
    }
    std::cout<<map->toString();
  }
}

void MenuMain::changeSelectedTile(Editor editor){
  std::cout<<"Selected tile ["<<editor.getPointerX()<<", "<<editor.getPointerY()<<"]\n";

  Menu selectTile = Menu(TILE_TYPE_AMOUNT,
    "[1] Change to BRICKS\n[2] Change to BUSHES\n[3] Change to ICE\n[4] Change to WATER\n[5] Change to EMPTY");
  std::cout<<selectTile.toString();

  int option;
  readInt(option);
  selectTile.pointerMoveTo(option-1);


  switch (selectTile.getPointer()) {
    case  0:
      editor.changeTile(BRICKS);
      break;
    case 1:
      editor.changeTile(BUSHES);
      break;
    case 2:
      editor.changeTile(ICE);
      break;
    case 3:
      editor.changeTile(WATER);
      break;
    case 4:
      editor.changeTile(EMPTY);
      break;
  }

}

Difficulty MenuMain::selectDifficulty(){
  Menu selectDifficulty = Menu(DIFFICULTY_AMOUNT,
    "[1] Create EASY difficulty map\n[2] Create NORMAL difficulty map\n[3] Create HARD difficulty map");
  std::cout<<selectDifficulty.toString();
  int option=0;

  readInt(option);
  selectDifficulty.pointerMoveTo(option-1);


  Difficulty generatorDifficulty;
  switch (selectDifficulty.getPointer()) {
    case 0:
      generatorDifficulty=EASY;
      break;
    case 1:
      generatorDifficulty=NORMAL;
      break;
    case 2:
      generatorDifficulty=HARD;
      break;
  }
  return generatorDifficulty;
}

Size MenuMain::selectSize(){
  Menu selectSize = Menu(DIFFICULTY_AMOUNT,
    "[1] Create SMALL size map\n[2] Create MEDIUM size map\n[3] Create LARGE size map");
  std::cout<<selectSize.toString();
  int option=0;

  readInt(option);
  selectSize.pointerMoveTo(option-1);


  Size generatorSize;
  switch (selectSize.getPointer()) {
    case 0:
      generatorSize=SMALL;
      break;
    case 1:
      generatorSize=MEDIUM;
      break;
    case 2:
      generatorSize=LARGE;
      break;
  }
  return generatorSize;
}
