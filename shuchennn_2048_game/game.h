//
// Created by shuchennnn on 24-12-18.
//

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义游戏棋盘的大小，这里是4x4
#define BOARD_SIZE 4

// 棋盘的数据结构，使用二维数组来表示
typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
} GameBoard;

// 函数声明，用于初始化游戏棋盘
void initBoard(GameBoard *board);
// 函数声明，用于在棋盘上随机生成一个新的数字（2或者4）
void addRandomTile(GameBoard *board);
// 函数声明，用于打印游戏棋盘
void printBoard(GameBoard board);
// 函数声明，用于判断游戏是否结束（没有可移动空间且没有空白格）
int isGameOver(GameBoard board);
// 函数声明，用于向左移动并合并数字
void moveLeft(GameBoard *board);
// 函数声明，用于向右移动并合并数字
void moveRight(GameBoard *board);
// 函数声明，用于向上移动并合并数字
void moveUp(GameBoard *board);
// 函数声明，用于向下移动并合并数字
void moveDown(GameBoard *board);

#endif