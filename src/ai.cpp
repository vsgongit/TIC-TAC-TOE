#include <algorithm>
#include "../include/ai.h"
#include "../include/game_logic.h"

int minimax(char board[][SIDE], int depth, bool isAI) {
    if (gameOver(board))
        return isAI ? -1 : +1;
    if (depth >= SIDE * SIDE)
        return 0;

    int bestScore = isAI ? -999 : 999;
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = isAI ? COMPUTERMOVE : HUMANMOVE;
                int score = minimax(board, depth + 1, !isAI);
                board[i][j] = ' ';
                bestScore = isAI ? std::max(bestScore, score) : std::min(bestScore, score);
            }
        }
    }
    return bestScore;
}

int bestMove(char board[][SIDE], int moveIndex) {
    int x = -1, y = -1, bestScore = -999;
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = COMPUTERMOVE;
                int score = minimax(board, moveIndex + 1, false);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    x = i; y = j;
                }
            }
        }
    }
    return x * SIDE + y;
}
