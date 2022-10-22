#include<stdio.h>
#include<stdlib.h>
#include "hof.c"
#include "hof.h"
#include"k.h"
#include"k.c"
#include"ui.h"
#include"ui.c"


void clrscr()
{
    system("@cls||clear");
}

int main(){
	struct player list[10];
	struct game game = {
    .board = {
         {'C', 'B', ' ', ' '},
        {'C', 'B', ' ', ' '},
        {'B', 'B', ' ', 'A'},
        {'B', ' ', ' ', ' '}
    },
    .score = 0
};
struct player player={
	.name=' ',
	.score=0
};

/*update(&game,-1,0);
render(game);*/
	
	char smer;
	printf("Welcome to game K!\nEnter your name: ");
	scanf("%s",player.name);
	while( getchar() != '\n')
    ;
     while(is_move_possible(game) != 0){
 	clrscr();
    printf("Hi %s! This is your game array\nFor move use letters 'w' 'a' 's' 'd'\n",player.name);
	render(game);
	 
	scanf("%c",&smer);
	while( getchar() != '\n')
    ;
   
    if(smer == 'w'){
    	if(update(&game,1,0) == 0){
    		break;
		}
	}
	if(smer == 's'){
    	if(update(&game,-1,0) == 0){
		
    		break;
		}
	}
	if(smer == 'a'){
    	if(update(&game,0,-1)==0){
    			break;
		}
	}
	if(smer == 'd'){
    	if(update(&game,0,1) == 0){
    	
			break;
		}
	}
}
	add_random_tile(&game);
	player.score=game.score;
	int size=load(list);
	add_player(list,&size,player);
	save(list,size);




	return 0;
}
