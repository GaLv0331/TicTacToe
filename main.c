#include "tic_tac_toe.h" //user defined function

int main(){
	
	char *player1 = NULL, *player2 = NULL;
	playerInfo(&player1, &player2);
	
	char *board[COLUMN];

	for(int i=0; i<ROW; i++){
		board[i] = (char *)calloc(COLUMN, sizeof(char));
		if(board[i]==NULL){
			perror("Memory Allocation Failed");
			free(player1);
			free(player2);
			exit(EXIT_FAILURE);
		}
	} //dynamically allocating size to 2d array with array of pointers
	
	initialize_board(board); //initializing board with 0 value
	
	int turn=0, gameState = GAME_PENDING;// to count turn which player
	printf("\n\nFor row and column enter between 1-3");
	
	while(gameState != GAME_OVER){
			
		if(turn%2==0){
			gameState = playerTurn(board, turn, player1, 'X');
		} //player 1 turn
		
		if(turn%2==1){
			gameState = playerTurn(board, turn, player2, 'O');
		} //player 2 turn
		if(gameState != GAME_OVER){
			turn++;
		}
		displayBoard(board);			
	}
	
	free_mem(board, player1, player2);
}
