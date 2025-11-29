#include "tic_tac_toe.h" //user defined function

int main(){
	char *board[COLUMN];
	for(int i=0; i<ROW; i++){
		board[i] = (char *)calloc(1, sizeof(char));
		if(board[i]==NULL){
			perror("Memory Allocation Failed");
			exit(-1);
		}
	} //dynamically allocating size to 2d array with array of pointers
	
	initialize_board(board); //initializing board with 0 value
	
	int turn=0;// to count turn which player
	
	printf("\n\nFor row and column enter between 1-3");
	
	while(1){
	
		if(turn>8){
			printf("\nTie Occured");
			exit(0);
		} //to check if all blocks are played or not
		
		printf("\n=================Board=================\n");
		for(int i=0; i<ROW; i++){
			for(int j=0; j<COLUMN; j++){
				printf(" %c", board[i][j]);
			}
			printf("\n");
		} //to display the board after each turn
			
		if(turn%2==0){
			if(turn_player1(board, &turn)==0){
				free_mem(board);
				exit(0);
			}; //if player 1 won free the allocated memory
		} //player 1 turn
		
		if(turn%2==1){
			if(turn_player2(board, &turn)==0){
				free_mem(board);
				exit(0);
			}; //if player 2 won free the allocated memory
		} //player 2 turn
		
		turn++; 
	}
}
