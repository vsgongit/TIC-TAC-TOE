#include <cstdio>
#include "../include/game_logic.h"

bool rowCrossed(char board[][SIDE]) {
    for (int i = 0; i < SIDE; i++)
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return true;
    return false;
}

bool columnCrossed(char board[][SIDE]) {
    for (int i = 0; i < SIDE; i++)
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return true;
    return false;
}

bool diagonalCrossed(char board[][SIDE]) {
    return (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ');
}

bool gameOver(char board[][SIDE]) {
    return rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board);
}

void declareWinner(int whoseTurn) {
    if (whoseTurn == COMPUTER)
        printf("COMPUTER has won\n");
    else
        printf("HUMAN has won\n");
}
