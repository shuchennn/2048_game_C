//
// Created by shuchennnn on 24-12-18.
//

#include "game.h"

// 初始化游戏棋盘，将所有格子设置为0（表示空白）
void initBoard(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
}

// 在棋盘上随机生成一个新的数字（2或者4），找到一个空白格放置
void addRandomTile(GameBoard *board) {
    int emptyCells[BOARD_SIZE * BOARD_SIZE][2];
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }
    if (count == 0) {
        return;
    }
    srand(time(NULL));
    int randomIndex = rand() % count;
    int value = (rand() % 2 == 0)? 2 : 4;
    board->board[emptyCells[randomIndex][0]][emptyCells[randomIndex][1]] = value;
}

// 打印游戏棋盘，格式化输出，让用户能直观看到当前棋盘状态
void printBoard(GameBoard board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%4d", board.board[i][j]);
        }
        printf("\n");
    }
}

// 判断游戏是否结束，即没有可移动空间且没有空白格了
int isGameOver(GameBoard board) {
    // 先检查是否有空白格
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j] == 0) {
                return 0;
            }
        }
    }
    // 检查水平方向是否可移动
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 1; j++) {
            if (board.board[i][j] == board.board[i][j + 1]) {
                return 0;
            }
        }
    }
    // 检查垂直方向是否可移动
    for (int j = 0; j < BOARD_SIZE; j++) {
        for (int i = 0; i < BOARD_SIZE - 1; i++) {
            if (board.board[i][j] == board.board[i + 1][j]) {
                return 0;
            }
        }
    }
    return 1;
}

// 向左移动并合并数字的逻辑实现
void moveLeft(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        int writeIndex = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j]!= 0) {
                if (writeIndex > 0 && board->board[i][writeIndex - 1] == board->board[i][j]) {
                    board->board[i][writeIndex - 1] *= 2;
                    board->board[i][j] = 0;
                } else {
                    board->board[i][writeIndex] = board->board[i][j];
                    if (writeIndex!= j) {
                        board->board[i][j] = 0;
                    }
                    writeIndex++;
                }
            }
        }
    }
}

// 向右移动并合并数字的逻辑实现，和向左移动思路类似，只是方向相反
void moveRight(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        int writeIndex = BOARD_SIZE - 1;
        for (int j = BOARD_SIZE - 1; j >= 0; j--) {
            if (board->board[i][j]!= 0) {
                if (writeIndex < BOARD_SIZE - 1 && board->board[i][writeIndex + 1] == board->board[i][j]) {
                    board->board[i][writeIndex + 1] *= 2;
                    board->board[i][j] = 0;
                } else {
                    board->board[i][writeIndex] = board->board[i][j];
                    if (writeIndex!= j) {
                        board->board[i][j] = 0;
                    }
                    writeIndex--;
                }
            }
        }
    }
}

// 向上移动并合并数字的逻辑实现，相当于转置棋盘后向左移动再转置回来
void moveUp(GameBoard *board) {
    GameBoard tempBoard;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            tempBoard.board[j][i] = board->board[i][j];
        }
    }
    moveLeft(&tempBoard);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[j][i] = tempBoard.board[i][j];
        }
    }
}

// 向下移动并合并数字的逻辑实现，相当于转置棋盘后向右移动再转置回来
void moveDown(GameBoard *board) {
    GameBoard tempBoard;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            tempBoard.board[j][i] = board->board[i][j];
        }
    }
    moveRight(&tempBoard);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[j][i] = tempBoard.board[i][j];
        }
    }
}