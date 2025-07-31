#include <cstdio>
#include "../include/tic_tac_toe.h"
#include "../include/board.h"
#include "../include/game_logic.h"
#include "../include/ai.h"

void playTicTacToe(int whoseTurn) {
    char board[SIDE][SIDE];
    initialise(board);
    showInstructions();

    int moveIndex = 0;

    while (!gameOver(board) && moveIndex < SIDE * SIDE) {
        int cellID, x, y;

        if (whoseTurn == HUMAN) {
            printf("You can insert in the following positions: ");
            for (int i = 0; i < SIDE; i++)
                for (int j = 0; j < SIDE; j++)
                    if (board[i][j] == ' ')
                        printf("%d ", (i * SIDE + j) + 1);
            printf("\n\nEnter the position: ");
            scanf("%d", &cellID);
            cellID--;

            x = cellID / SIDE;
            y = cellID % SIDE;

            if (cellID >= 0 && cellID < 9 && board[x][y] == ' ') {
                board[x][y] = HUMANMOVE;
                printf("\nHUMAN placed %c at %d\n\n", HUMANMOVE, cellID + 1);
                showBoard(board);
                moveIndex++;
                whoseTurn = COMPUTER;
            } else {
                printf("\nInvalid move! Try again.\n\n");
            }

        } else {
            int best = bestMove(board, moveIndex);
            x = best / SIDE;
            y = best % SIDE;
            board[x][y] = COMPUTERMOVE;
            printf("COMPUTER placed %c at %d\n\n", COMPUTERMOVE, best + 1);
            showBoard(board);
            moveIndex++;
            whoseTurn = HUMAN;
        }
    }

    if (!gameOver(board))
        printf("It's a draw!\n");
    else
        declareWinner(whoseTurn == HUMAN ? COMPUTER : HUMAN);
}
