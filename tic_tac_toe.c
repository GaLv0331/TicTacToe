#include "tic_tac_toe.h"
//==========================function to initailize the board with 0 value==========================
void initialize_board(char *board[COLUMN]){
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			board[i][j] = '0';	
		}
	}
}
//==========================player 1 turn==========================
int turn_player1(char *board[COLUMN], int *turn){
	int position_row=0, position_column=0;
	printf("\n===========Player 1 Turn===========");
		do{
			printf("\nEnter position in row: ");
			scanf("%d", &position_row);
			printf("\nEnter position in column: ");
			scanf("%d", &position_column);
			
			position_row -= 1; //mapping user input
			position_column -=1;
			
		}while(pos_occupied_player1(board, &position_row, &position_column)!=0);
		//to place the player mark on the position
		for(int i=0; i<ROW; i++){
			for(int j=0; j<COLUMN; j++){
				if(position_row == i && position_column == j){
					board[position_row][position_column] = 'x';
				}
			}
		}
		//to check if the player has won or not
		if(*turn>2){
			if(win_conditions_player1(board)==0){
				printf("\nPlayer 1 WON");
				printf("\n=================Board=================\n");
				for(int i=0; i<ROW; i++){
					for(int j=0; j<COLUMN; j++){
						printf(" %c", board[i][j]);
					}
					printf("\n");
				}
				return 0; //to indicate player has won
			}
		}
	return 1; //indicating player has not won
}
//==========================player 2 turn==========================
int turn_player2(char *board[COLUMN], int *turn){
	int position_row=0, position_column=0;
	printf("\n===========Player 2 Turn===========");
		do{
			printf("\nEnter position in row: ");
			scanf("%d", &position_row);
			printf("\nEnter position in column: ");
			scanf("%d", &position_column);
			position_row -= 1;
			position_column -=1;
		}while(pos_occupied_player2(board, &position_row, &position_column)!=0);
		for(int i=0; i<ROW; i++){
			for(int j=0; j<COLUMN; j++){
				if(position_row == i && position_column == j){
					board[position_row][position_column] = 'o';
				}
			}
		}
		if(*turn>2){
			if(win_conditions_player2(board)==0){
				printf("\nPlayer 2 WON");
				printf("\n=================Board=================\n");
				for(int i=0; i<ROW; i++){
					for(int j=0; j<COLUMN; j++){
						printf(" %c", board[i][j]);
					}
					printf("\n");
				}				
				return 0;
			}
		}
		return 1;
}

int pos_occupied_player1(char *board[COLUMN], int *position_row, int *position_column){ //to check pos occupied or not by another player
	if(*position_column<0 || *position_column>3){
		printf("\nInvalid Column Re-enter: ");
		return 1;
	}
	if(*position_row<0 || *position_row>3){
		printf("\nInvalid Row Re-enter: ");
		return 1;
	}	
	if(board[*position_row][*position_column]=='x' || board[*position_row][*position_column]=='o'){
		printf("\nposition Already Occupied");
		return 1;	
	}
	return 0;
}

int pos_occupied_player2(char *board[COLUMN], int *position_row, int *position_column){
	if(*position_column<0 || *position_column>3){
		printf("\nInvalid Column Re-enter: ");
		return 1;
	}
	if(*position_row<0 || *position_row>3){
		printf("\nInvalid Row Re-enter: ");
		return 1;
	}
	if(board[*position_row][*position_column]=='x' || board[*position_row][*position_column]=='o'){
		printf("\nposition Already Occupied");
		return 1;	
	}
	return 0;
}

int win_conditions_player1(char *board[COLUMN]){ //to check win conditions
	int count=0, count_diagonal=0, count_anti_diagonal=0;
	int j=COLUMN-1;;
	for(int i=0; i<ROW; i++){
		if(board[i][i]=='x'){
			count_diagonal++;
		}	
		if(board[i][j]=='x'){
			count_anti_diagonal++;
			j--;
			
		}
	}
		
	if(count_diagonal == 3 || count_anti_diagonal == 3){
		return 0;
	}
//===========================================================	
	for(int i=0; i<ROW; i++){
		if(board[i][0]=='x'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
	
	for(int j=0; j<ROW; j++){
		if(board[0][j]=='x'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
//===========================================================
	for(int i=0; i<ROW; i++){
		if(board[i][1]=='x'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
	
	for(int j=0; j<ROW; j++){
		if(board[1][j]=='x'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
//===========================================================
	for(int i=0; i<ROW; i++){
		if(board[i][2]=='x'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
	
	for(int j=0; j<ROW; j++){
		if(board[2][j]=='x'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}

	
	return 1;
}

int win_conditions_player2(char *board[COLUMN]){
	int count=0, count_diagonal=0, count_anti_diagonal=0;
	int j=COLUMN-1;;
	for(int i=0; i<ROW; i++){
		if(board[i][i]=='o'){
			count_diagonal++;
		}	
		if(board[i][j]=='o'){
			count_anti_diagonal++;
			j--;	
		}
	}
		
	if(count_diagonal == 3 || count_anti_diagonal == 3){
		return 0;
	}
	
//===========================================================	
	for(int i=0; i<ROW; i++){
		if(board[i][0]=='o'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
	
	for(int j=0; j<ROW; j++){
		if(board[0][j]=='o'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
//===========================================================
	for(int i=0; i<ROW; i++){
		if(board[i][1]=='o'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
	
	for(int j=0; j<ROW; j++){
		if(board[1][j]=='o'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
//===========================================================
	for(int i=0; i<ROW; i++){
		if(board[i][2]=='o'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
	
	for(int j=0; j<ROW; j++){
		if(board[2][j]=='o'){
			count++;
		}
	}
	if(count == 3){
		return 0;
	}else{count = 0;}
	
	return 1;
}

void free_mem(char *board[COLUMN]){
	for(int i=0; i<ROW; i++){
		free(board[i]);
	}
	//free(board);
}
