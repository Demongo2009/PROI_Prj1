#ifndef ENUMS_H
#define ENUMS_H

#include <iostream>

enum Size{SMALL=10, MEDIUM=20, LARGE=30};
typedef enum Size Size;
enum Difficulty{EASY, NORMAL, HARD};
typedef enum Difficulty Difficulty;
enum Direction{DOWN,RIGHT,UP,LEFT};
typedef enum Direction Direction;
enum TileType{EMPTY,ROAD,BUSHES,ICE,WATER,BRICKS,IRON};
typedef enum TileType TileType;

#endif
