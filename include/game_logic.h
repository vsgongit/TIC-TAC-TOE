#pragma once
#include "tic_tac_toe.h"

bool rowCrossed(char board[][SIDE]);
bool columnCrossed(char board[][SIDE]);
bool diagonalCrossed(char board[][SIDE]);
bool gameOver(char board[][SIDE]);
void declareWinner(int whoseTurn);
