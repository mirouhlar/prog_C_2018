#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"hof.h"
int cmp(const void* p1, const void* p2){
	struct player* player1 = (struct player*)p1;
	struct player* player2 = (struct player*)p2;
	return (player1->score > player2->score) ? -1 : (player1->score == player2->score)? 0 : 1 ;
}

int load(struct player list[]){
	FILE *fp = fopen(HOF_FILE, "r");
		if(fp == NULL){
		return -1;
	}
	char c=getc(fp);
	int size=0;
	 while (c != EOF)
    {
    if (c == ' ')
        {
        size++;
        }
        c = getc(fp);
    }
	fclose(fp);
	int i=0;
	if(size>0){
	
    fp = fopen(HOF_FILE, "r");
		if(fp == NULL){
		return -1;
	}
 
	struct player pl[size];
	
	
	for(i=0;i<size;i++){
	fscanf(fp,"%s",pl[i].name);
	fscanf(fp,"%d",&pl[i].score);

}

	fclose(fp);
	int a=0;
	if(size>=10){
		a=10;
	}
	else{
		a=size;
	}
	size_t size1=(int)size;
	qsort(pl,size1,sizeof(struct player),cmp);
	for( i=0;i<a;i++){
	sprintf(list[i].name, "%s",pl[i].name);
	list[i].score=pl[i].score;
}
}
printf("%d",i);
	return i;
}
bool save(const struct player list[], const int size){
	
	FILE* fp = fopen(HOF_FILE, "w");
	if(fp == NULL){
		return false;
	}
	if(size==0){
	    if(fclose(fp) == EOF){
		return false;
	}
	return true;
			
	}
/*	else if (size<10){
	
	for(int i=0;i<size+1;i++){
		
		fprintf(fp, "%s%s%d\n",list[i].name,DELIMITER,list[i].score);
	}
		}*/
	else{
		for(int i=0;i<size;i++){
		
		fprintf(fp, "%s%s%d\n",list[i].name,DELIMITER,list[i].score);
	}
		
	}
		
		
	if(fclose(fp) == EOF){
		return false;
	}
	return true;
	
}
bool add_player(struct player list[], int* size, const struct player player){
	size_t size1=*size;
	if(size1 == 0){
		sprintf(list[size1].name, "%s",player.name);
			list[size1].score = player.score;
			size1++;
			*size=size1;
			return true;	
	}
	if(size1==10){
		if(list[size1-1].score <= player.score){
		sprintf(list[size1-1].name, "%s",player.name);
		list[size1-1].score = player.score;
		
		for(int i=0;i<10;i++){
			if(list[size1-1].score == list[i].score && size1>1){
				char a[30];
				sprintf(a, "%s",list[i].name);
				sprintf(list[i].name, "%s",list[size1-1].name);
				sprintf(list[size1-1].name, "%s",a);
				a[0]='\0';
				break;
			}
		}
		
		qsort(list,size1,sizeof(struct player),cmp);
		
		return true;
			
		}
		else{
			return false;
		}
	}
	else{
		sprintf(list[size1].name, "%s",player.name);
		list[size1].score = player.score;
				for(int i=0;i<size1-1;i++){
			if(list[size1].score == list[i].score){
				char a[30];
				sprintf(a, "%s",list[i].name);
				sprintf(list[i].name, "%s",list[size1].name);
				sprintf(list[size1].name, "%s",a);
				a[0]='\0';
				break;
			}
			
		}
		size1++;
		qsort(list,size1+1,sizeof(struct player),cmp);
	
	*size=size1;
		
			return true;
		
	}
	
return false;
}
