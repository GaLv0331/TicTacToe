#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdio.h>
#include <stdlib.h>
//===================
//defined macros for board size
#define ROW 3
#define COLUMN 3
//===================
//function declarations
int pos_occupied_player1(char *board[COLUMN], int *row, int *column);
int pos_occupied_player2(char *board[COLUMN], int *row, int *column);
int win_conditions_player1(char *board[COLUMN]);
int win_conditions_player2(char *board[COLUMN]);
void initialize_board(char *board[COLUMN]);
int  turn_player1(char *board[COLUMN], int *turn);
int turn_player2(char *board[COLUMN], int *turn);
void free_mem(char *boar[COLUMN]);

#endif
