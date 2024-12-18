//
// Created by shuchennnn on 24-12-18.
//

#include "game.h"

int main() {
    GameBoard board;
    initBoard(&board);
    addRandomTile(&board);
    addRandomTile(&board);

    while (!isGameOver(board)) {
        printBoard(board);
        printf("Enter direction (w/a/s/d for up/left/down/right): ");
        char input;
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                moveUp(&board);
            break;
            case 'a':
                moveLeft(&board);
            break;
            case's':
                moveDown(&board);
            break;
            case 'd':
                moveRight(&board);
            break;
            default:
                printf("Invalid input. Try again.\n");
            continue;
        }
        addRandomTile(&board);
    }
    printf("Game Over!\n");
    return 0;
}