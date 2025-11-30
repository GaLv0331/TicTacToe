#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//===================
//defined macros for board size
#define ROW 		3
#define COLUMN 	3

#define WON		0
#define TIE		1
#define PENDING	2

#define PLACED		0
#define OCCUPIED	1
#define INVALID_POS	2

#define GAME_OVER	0
#define GAME_PENDING	1
//===================
//function declarations
void playerInfo(char **player1, char**player2);
void displayBoard(char *board[COLUMN]);
void initialize_board(char *board[COLUMN]);
int winCondition(char *board[COLUMN], char playerMark, int turn);
int playerTurn(char *board[COLUMN], int turn, char *name, char playerMark);
int putMark(char *board[COLUMN], int row, int col, char mark);
void free_mem(char *boar[COLUMN], char *player1, char *player2);

#endif
