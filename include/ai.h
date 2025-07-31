#pragma once
#include "tic_tac_toe.h"

int minimax(char board[][SIDE], int depth, bool isAI);
int bestMove(char board[][SIDE], int moveIndex);
