
#include <iostream>
#define DIFFICULTY_AMOUNT 3
#define EDITOR_OPTIONS 3
#define TILE_TYPE_AMOUNT 5

void MenuMain::executePointerCommand(){
  switch (pointer) {
    case 0:
      generate();
      break;
    case 1:
      exit();
      break;
  }
}

void MenuMain::generate(){
  Difficulty generatorDifficulty = selectDifficulty();
  Size generatorSize = selectSize();

  Generator generator = Generator(generatorSize,generatorDifficulty)
  Map map* = generator.generateMap();

  if(wantToEdit()){
    editMap(map);
  }else{
    exit();
  }
}

void MenuMain::editMap(Map* map){
  Editor editor = Editor(map);
  std::cout<<map->toString();

  Menu editorMenu = Menu(EDITOR_OPTIONS,
    "[1] Go to tile [x,y]",
    "[2] Change selected tile to [BRICKS,BUSHES,ICE,WATER,EMPTY]",
    "[3] Quit editing and exit");
  while(1){
    std::cout<<editorMenu.toString();
    std::cout<<"Selected tile ["<<pointerX<<", "<<pointerY<<"]\n";

    int option;
    readInt(option);
    editorMenu.pointerMoveTo(option-1);
    std::cout<<editorMenu.toString();

    switch (option-1) {
      case 0:
        int x;
        readInt(x);
        int y;
        readInt(y);
        editor.setPointerTo(x,y);
        break;
      case 1:
        std::cout<<"Selected tile ["<<pointerX<<", "<<pointerY<<"]\n";

        Menu selectTile = Menu(TILE_TYPE_AMOUNT,
          "[1] Change to BRICKS",
          "[2] Change to BUSHES",
          "[3] Change to ICE",
          "[4] Change to WATER",
          "[5] Change to EMPTY");
        std::cout<<selectTile.toString();

        int option;
        readInt(option);
        selectTile.pointerMoveTo(option-1);
        std::cout<<selectTile.toString();
        switch (option-1) {
          case  0:
            changeTile();
            break;
          case 1:
            changeTile();
        }

    }

  }
}

Difficulty MenuMain::selectDifficulty(){
  Menu selectDifficulty = Menu(DIFFICULTY_AMOUNT,
    "[1] Create EASY difficulty map",
    "[2] Create NORMAL difficulty map",
    "[3] Create HARD difficulty map");
  std::cout<<selectDifficulty.toString();
  int option=0;

  readInt(option);
  selectDifficulty.pointerMoveTo(option-1);
  std::cout<<selectDifficulty.toString();

  Difficulty generatorDifficulty;
  switch (option-1) {
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
    "[1] Create SMALL size map",
    "[2] Create MEDIUM size map",
    "[3] Create LARGE size map");
  std::cout<<selectSize.toString();
  int option=0;

  readInt(option);
  selectSize.pointerMoveTo(option-1);
  std::cout<<selectSize.toString();

  Size generatorSize;
  switch (option-1) {
    case 0:
      generatorDifficulty=SMALL;
      break;
    case 1:
      generatorDifficulty=MEDIUM;
      break;
    case 2:
      generatorDifficulty=LARGE;
      break;
  }
  return generatorSize;
}
