#include<stdio.h>
#include <stdlib.h>
#include "k.h"


bool is_game_won(const struct game game){
	int i,y;
	for( i=0;i<SIZE;i++){
		for( y=0;y<SIZE;y++){
			if(game.board[i][y] == 'K'){
				return true;
			}
		}
	}
	return false;
}
bool is_move_possible(const struct game game){
	int i,y;
	for( i=0;i<SIZE;i++){
		for( y=0;y<SIZE;y++){
			if(game.board[i][y] == ' '){
				return true;
			}
			if(game.board[i][y] == game.board[i+1][y] && i+1<SIZE){
		
				return true;
			}
			if(game.board[i][y] == game.board[i-1][y] && i-1>-1){
		
				return true;
			}
			if(game.board[i][y] == game.board[i][y+1] && y+1<SIZE){
		
				return true;
			}
			if(game.board[i][y] == game.board[i][y-1] && y-1>-1){
			
				return true;
			}
		}
	}
	return false;
}

bool update(struct game *game, int dy, int dx){
	bool result=false;
	if(dx == 1 && dy == 0){
	for(int i=SIZE-1;i>-1;i--){
		for(int y=SIZE-1;y>-1;y--){
			if(game->board[i][y] == ' ' && y>-1){
				for(int a=y-1;a>-1;a--){
					if(game->board[i][a]!=' '){
						game->board[i][y]= game->board[i][a];
						game->board[i][a]=' ';
						a=0;
					}
				}
				result=true;
			} 	
						}
		}
			for(int i=SIZE-1;i>-1;i--){
		for(int y=SIZE-1;y>-1;y--){
						if(game->board[i][y]==game->board[i][y-1] && game->board[i][y]!= ' ' && y>0){
							if(game->board[i][y]=='A'){
								game->board[i][y-1]='B';
								game->board[i][y]=' ';
								game->score=game->score+4;
							}
							if(game->board[i][y]=='B'){
								game->board[i][y-1]='C';
								game->board[i][y]=' ';
								game->score=game->score+8;
							}
							if(game->board[i][y]=='C'){
								game->board[i][y-1]='D';
								game->board[i][y]=' ';	
								game->score=game->score+16;
							}
							if(game->board[i][y]=='D'){
								game->board[i][y-1]='E';
								game->board[i][y]=' ';
								game->score=game->score+32;
								
							}
							if(game->board[i][y]=='E'){
								game->board[i][y-1]='F';
								game->board[i][y]=' ';
								game->score=game->score+64;
								
							}
							if(game->board[i][y]=='F'){
								game->board[i][y-1]='G';
								game->board[i][y]=' ';
								game->score=game->score+128;
								
							}
							if(game->board[i][y]=='G'){
								game->board[i][y-1]='H';
								game->board[i][y]=' ';
								game->score=game->score+256;
								
							}
							if(game->board[i][y]=='H'){
								game->board[i][y-1]='I';
								game->board[i][y]=' ';
								game->score=game->score+512;
								
							}
							if(game->board[i][y]=='I'){
								game->board[i][y-1]='J';
								game->board[i][y]=' ';
								game->score=game->score+1024;
								
							}
							if(game->board[i][y]=='J'){
								game->board[i][y-1]='K';
								game->board[i][y]=' ';
								game->score=game->score+2048;
								
							}
						y--;
						}		
				}
			}
			for(int i=SIZE-1;i>-1;i--){
		for(int y=SIZE-1;y>-1;y--){
			if(game->board[i][y] == ' ' && y>-1){
				for(int a=y-1;a>-1;a--){
					if(game->board[i][a]!=' '){
						game->board[i][y]= game->board[i][a];
						game->board[i][a]=' ';
						a=0;
					}
				}
			
			} 	
			
			}
		}		
	}
	
		if(dx == -1 && dy == 0){
	for(int i=0;i<SIZE;i++){
		for(int y=0;y<SIZE;y++){
			if(game->board[i][y] == ' ' && y<SIZE){
				for(int a=y+1;a<SIZE;a++){
					if(game->board[i][a]!=' '){
						game->board[i][y]= game->board[i][a];
						game->board[i][a]=' ';
						a=SIZE;
					}
				}	
				result=true;
			}
		}
			}
			for(int i=0;i<SIZE;i++){
		for(int y=0;y<SIZE;y++){
						if(game->board[i][y]==game->board[i][y+1] && game->board[i][y]!= ' ' && y<SIZE-1){
							if(game->board[i][y]=='A'){
								game->board[i][y+1]='B';
								game->board[i][y]=' ';
								game->score=game->score+4;
							
							}
							if(game->board[i][y]=='B'){
								game->board[i][y+1]='C';
								game->board[i][y]=' ';
								game->score=game->score+8;
							}
							if(game->board[i][y]=='C'){
								game->board[i][y+1]='D';
								game->board[i][y]=' ';
								game->score=game->score+16;	
							}
							if(game->board[i][y]=='D'){
								game->board[i][y+1]='E';
								game->board[i][y]=' ';
								game->score=game->score+32;	
							}
							if(game->board[i][y]=='E'){
								game->board[i][y+1]='F';
								game->board[i][y]=' ';
								game->score=game->score+64;	
							}
							if(game->board[i][y]=='F'){
								game->board[i][y+1]='G';
								game->board[i][y]=' ';
								game->score=game->score+128;	
							}
							if(game->board[i][y]=='G'){
								game->board[i][y+1]='H';
								game->board[i][y]=' ';
								game->score=game->score+256;	
							}
							if(game->board[i][y]=='H'){
								game->board[i][y+1]='I';
								game->board[i][y]=' ';
								game->score=game->score+512;	
							}
							if(game->board[i][y]=='I'){
								game->board[i][y+1]='J';
								game->board[i][y]=' ';
								game->score=game->score+1024;	
							}
							if(game->board[i][y]=='J'){
								game->board[i][y+1]='K';
								game->board[i][y]=' ';
							game->score=game->score+2048;	
							}
						y--;
						}
		
				}
			}
			
				for(int i=0;i<SIZE;i++){
		for(int y=0;y<SIZE;y++){
			if(game->board[i][y] == ' ' && y<SIZE){
				for(int a=y+1;a<SIZE;a++){
					if(game->board[i][a]!=' '){
						game->board[i][y]= game->board[i][a];
						game->board[i][a]=' ';
						a=SIZE;
					}
				}
			
			}
		}
			}
	}
	
	if(dy == -1 && dx == 0){
	for(int i=0;i<SIZE;i++){
		for(int y=0;y<SIZE;y++){
			if(game->board[i][y] == ' ' && y<SIZE){
				for(int a=i+1;a<SIZE;a++){
					if(game->board[a][y]!=' '){
						game->board[i][y]= game->board[a][y];
						game->board[a][y]=' ';
						a=SIZE;
					}
				}
				result=true;		
			}
		}
			}
			for(int i=0;i<SIZE;i++){
		for(int y=0;y<SIZE;y++){
						if(game->board[i][y]==game->board[i+1][y] && game->board[i][y]!= ' ' && y<SIZE){
							if(game->board[i][y]=='A'){
								game->board[i+1][y]='B';
								game->board[i][y]=' ';
								game->score=game->score+4;
							
							}
							if(game->board[i][y]=='B'){
								game->board[i+1][y]='C';
								game->board[i][y]=' ';
								game->score=game->score+8;
							}
							if(game->board[i][y]=='C'){
								game->board[i+1][y]='D';
								game->board[i][y]=' ';
								game->score=game->score+16;	
							}
							if(game->board[i][y]=='D'){
								game->board[i+1][y]='E';
								game->board[i][y]=' ';
								game->score=game->score+32;	
							}
							if(game->board[i][y]=='E'){
								game->board[i+1][y]='F';
								game->board[i][y]=' ';
								game->score=game->score+64;	
							}
							if(game->board[i][y]=='F'){
								game->board[i+1][y]='G';
								game->board[i][y]=' ';
								game->score=game->score+128;	
							}
							if(game->board[i][y]=='G'){
								game->board[i+1][y]='H';
								game->board[i][y]=' ';
								game->score=game->score+256;	
							}
							if(game->board[i][y]=='H'){
								game->board[i+1][y]='I';
								game->board[i][y]=' ';
								game->score=game->score+512;	
							}
							if(game->board[i][y]=='I'){
								game->board[i+1][y]='J';
								game->board[i][y]=' ';
								game->score=game->score+1024;	
							}
							if(game->board[i][y]=='J'){
								game->board[i+1][y]='K';
								game->board[i][y]=' ';
								game->score=game->score+2048;	
							}
						y--;
					}
				}
			}
				for(int i=0;i<SIZE;i++){
		for(int y=0;y<SIZE;y++){
			if(game->board[i][y] == ' ' && y<SIZE){
				for(int a=i+1;a<SIZE;a++){
					if(game->board[a][y]!=' '){
						game->board[i][y]= game->board[a][y];
						game->board[a][y]=' ';
						a=SIZE;
					}
				}
					
			}
		}
			}		
	}
		if(dy ==1 && dx == 0){
	for(int i=SIZE-1;i>-1;i--){
		for(int y=SIZE-1;y>-1;y--){
			if(game->board[i][y] == ' ' && y>-1){
				for(int a=i-1;a>-1;a--){
					if(game->board[a][y]!=' '){
						game->board[i][y]= game->board[a][y];
						game->board[a][y]=' ';
						a=0;
					}
				}	
				result=true;
			}
		}
	}
			
				for(int i=SIZE-1;i>-1;i--){
		for(int y=SIZE-1;y>-1;y--){
						if(game->board[i][y]==game->board[i-1][y] && game->board[i][y]!= ' ' && y>0){
							if(game->board[i][y]=='A'){
								game->board[i-1][y]='B';
								game->board[i][y]=' ';
								game->score=game->score+4;
							}
							if(game->board[i][y]=='B'){
								game->board[i-1][y]='C';
								game->board[i][y]=' ';
								game->score=game->score+8;
							}
							if(game->board[i][y]=='C'){
								game->board[i-1][y]='D';
								game->board[i][y]=' ';	
								game->score=game->score+16;	
							}
							if(game->board[i][y]=='D'){
								game->board[i-1][y]='E';
								game->board[i][y]=' ';
								game->score=game->score+32;	
							}
							if(game->board[i][y]=='E'){
								game->board[i-1][y]='F';
								game->board[i][y]=' ';
								game->score=game->score+64;	
							}
							if(game->board[i][y]=='F'){
								game->board[i-1][y]='G';
								game->board[i][y]=' ';
								game->score=game->score+128;	
							}
							if(game->board[i][y]=='G'){
								game->board[i-1][y]='H';
								game->board[i][y]=' ';
								game->score=game->score+256;	
							}
							if(game->board[i][y]=='H'){
								game->board[i-1][y]='I';
								game->board[i][y]=' ';
								game->score=game->score+512;	
							}
							if(game->board[i][y]=='I'){
								game->board[i-1][y]='J';
								game->board[i][y]=' ';
								game->score=game->score+1024;	
							}
							if(game->board[i][y]=='J'){
								game->board[i-1][y]='K';
								game->board[i][y]=' ';
								game->score=game->score+2048;	
							}
						y--;
						}		
				}
			}
			
			for(int i=SIZE-1;i>-1;i--){
		for(int y=SIZE-1;y>-1;y--){
			if(game->board[i][y] == ' ' && y>-1){
				for(int a=i-1;a>-1;a--){
					if(game->board[a][y]!=' '){
						game->board[i][y]= game->board[a][y];
						game->board[a][y]=' ';
						a=0;
					}
				}
					
				}
		}
	}		
	}
	return result;	
}
	

void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % 4;
        col = rand() % 4;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}
