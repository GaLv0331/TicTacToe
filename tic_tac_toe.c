#include "tic_tac_toe.h"

void playerInfo(char **player1, char**player2){

	char tempBuffer[25] = {0};
	
	printf("\nEnter Player 1 Name: ");
	scanf(" %[^\n]", tempBuffer);
	
	*player1 = (char *)malloc(strlen(tempBuffer)+1);
	if(*player1==NULL){
		perror("Player1 Name");
		exit(EXIT_FAILURE);
	}
	strncpy(*player1, tempBuffer, strlen(tempBuffer)+1);
	
	memset(tempBuffer, 0, sizeof(tempBuffer));

	printf("\nEnter Player 2 Name: ");
	scanf(" %[^\n]", tempBuffer);
	
	*player2 = (char *)malloc(strlen(tempBuffer)+1);
	if(*player2==NULL){
		perror("Player1 Name");
		exit(EXIT_FAILURE);
	}
	strncpy(*player2, tempBuffer, strlen(tempBuffer)+1);	
	
	return;
	
}

//==========================function to initailize the board with 0 value==========================
void initialize_board(char *board[COLUMN]){
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			board[i][j] = '-';	
		}
	}
}
//=================================================================
void displayBoard(char *board[COLUMN]){
	printf("\n=================Board=================\n");
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	} //to display the board after each turn	
}
//==================================================================

int putMark(char *board[COLUMN], int row, int col, char mark){
	if(row<0 || row>=ROW || col<0 || col>=COLUMN){
		printf("\nInvalid Position");
		return INVALID_POS;
	}
	if(board[row][col] != '-'){
		printf("\nPosition Occupied");
		return OCCUPIED;
	}
	board[row][col] = mark;
	return PLACED;
}

//===================================================================
int playerTurn(char *board[COLUMN], int turn, char *name, char playerMark){
	
	int posRow = 0, posCol = 0;
	printf("\n=========%s=========", name);
	do{
		printf("\nEnter position in row: ");
		scanf("%d", &posRow);
		printf("\nEnter position in column: ");
		scanf("%d", &posCol);
		posRow--; posCol--;
	}while(putMark(board, posRow, posCol, playerMark)!=PLACED);
	
	if(turn+1 >= ((ROW*2)-1)){
		int winState = winCondition(board, playerMark, turn);
		if(winState == WON){
			printf("\n%s WON", name);
			return GAME_OVER;
		}
		if(winState == TIE){
			printf("\nTie Occured");
			return GAME_OVER;
		}
	}
	return GAME_PENDING;
	
}

int winCondition(char *board[COLUMN], char playerMark, int turnCount){

	for(int i=0; i<ROW; i++){
		int rowCount = 0;
		int colCount = 0;
		for(int j=0; j<COLUMN; j++){
			if(board[i][j] == playerMark){
				rowCount++;
			}
			if(board[j][i]==playerMark){
				colCount++;
			}
		}
		if(rowCount == ROW){
			return WON;
		}
		
		if(colCount == COLUMN){
			return WON;
		}
	}
	
	int diagonalCount = 0, antiDiagonalCount = 0;
	for(int i=0; i<ROW; i++){
		if(board[i][i] == playerMark){
			diagonalCount++;
		}
		if(board[i][COLUMN-1-i] == playerMark){
			antiDiagonalCount++;
		}
	}
	
	if(diagonalCount == ROW || antiDiagonalCount == ROW){
		return WON;
	}

	if(turnCount+1 >= (ROW*COLUMN)){
		return TIE;
	}	
	
	return PENDING;
	
}

void free_mem(char *board[COLUMN], char *player1, char *player2){
	for(int i=0; i<ROW; i++){
		free(board[i]);
	}
	free(player1);
	free(player2);
}
