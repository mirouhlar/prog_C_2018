#include "playfair.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

char* res(const char* text);
char* array(const char* key, const char* text);



char* playfair_encrypt(const char* key, const char* text){
if(key == NULL || text == NULL){
		return NULL;
	}
	int g=0;
	while(key[g] != '\0'){
		if(!isalpha(key[g])){
			return NULL;
		}
		g++;
	}
	
	char* word = res(text);
	char* alpha = array(key,text);
	int x1=0,x2=0,y1=0,y2=0;
	char* result = (char*)calloc(strlen(word)+1,sizeof(char));
	
	int a=0,i,y;
	for(a=0;a<strlen(word);){
	
	for(i=0;i<5;i++){
		for(y=0;y<5;y++){
			if(alpha[i*5+y]==word[a]){
				x1=i;
				y1=y;
		
				break;
			}
		}
	}
		for(i=0;i<5;i++){
		for(y=0;y<5;y++){
			if(alpha[i*5+y]==word[a+1]){
				x2=i;
				y2=y;
				
				break;
			}
		}
	}
	if((x1== x2)&&(y1==y2)){
		if(x1>3){
			result[a]=alpha[0*5+y1];
		}
		else{
			result[a]=alpha[(x1+1)*5+y1];
		}
		if(x2>3){
			result[a+1]=alpha[0*5+y2];
		}
		else{
			result[a+1]=alpha[(x2+1)*5+y2];
		}
	}
	
	 if((x1 != x2)&&(y1 != y2)){
		result[a]=alpha[x1*5+y2];
		
		result[a+1]=alpha[x2*5+y1];
		
	}
	 if(x1 == x2){
		if(y1>3){
			result[a]=alpha[x1*5+0];

		}
		else{
			result[a]=alpha[x1*5+y1+1];

		}
		if(y2>3){
			result[a+1]=alpha[x2*5+0];

		}
		else{
			result[a+1]=alpha[x2*5+y2+1];
			
		}
		
	}
	 if(y1 == y2){
		if(x1>3){
			result[a]=alpha[0*5+y1];
		}
		else{
			result[a]=alpha[(x1+1)*5+y1];
		}
		if(x2>3){
			result[a+1]=alpha[0*5+y2];
		}
		else{
			result[a+1]=alpha[(x2+1)*5+y2];
		}
		
	}
	a=a+2;

}

char* retazec=(char*)calloc(strlen(result)+(strlen(result)/2),sizeof(char));
for(int a=0,i=0,c=2;a<strlen(result);){
	if(a==c){
		retazec[i]=' ';
		i++;
		c=c+2;
	}
	else{
	retazec[i]=result[a];
	i++;
	a++;
}
}

	free(alpha);
	free(result);
	free(word);	
	return retazec;
}



char* playfair_decrypt(const char* key, const char* text){
	if(key == NULL || text == NULL){
		return NULL;
	}
	int g=0;
	while(key[g] != '\0'){
		if(!isalpha(key[g])){
			return NULL;
		}
		g++;
	}
	g=0;
	while(text[g] != '\0'){
		if((text[g]== 'w')||(text[g] == 'W')){
			return NULL;
		}
		g++;
	}
	
	char* alpha = array(key,text);
	
	char* retazec=(char*)calloc(strlen(text),sizeof(char));
	for(int a=0,i=0;a<strlen(text);){
		if(text[a]==' '){
			a++;
		}
		else{
			retazec[i]=toupper(text[a]);
			a++;
			i++;
		}
	}
	printf("%s\n",retazec);
	int x1=0,x2=0,y1=0,y2=0;
	char* result = (char*)calloc(strlen(retazec)+2,sizeof(char));
	
	int a=0,i,y;
	for(a=0;a<strlen(retazec);){
	for(i=0;i<5;i++){
		for(y=0;y<5;y++){
			if(alpha[i*5+y]==retazec[a]){
				x1=i;
				y1=y;
		
				break;
			}
		}
	}
		for(i=0;i<5;i++){
		for(y=0;y<5;y++){
			if(alpha[i*5+y]==retazec[a+1]){
				x2=i;
				y2=y;
				
				break;
			}
		}
	}
	
	if((x1 == x2)&&(y1==y2)){
		if(x1==0){
			result[a]=alpha[4*5+y1];
		}
		else{
			result[a]=alpha[(x1-1)*5+y1];
		}
		if(x2==0){
			result[a+1]=alpha[4*5+y2];
		}
		else{
			result[a+1]=alpha[(x2-1)*5+y2];
		}
		
	}
		
	

 if((x1 != x2)&&(y1 != y2)){
		result[a]=alpha[x1*5+y2];
		
		result[a+1]=alpha[x2*5+y1];
		
	}
 if(y1 == y2){
		if(x1==0){
			result[a]=alpha[4*5+y1];

		}
		else{
			result[a]=alpha[(x1-1)*5+y1];

		}
		if(x2==0){
			result[a+1]=alpha[4*5+y2];

		}
		else{
			result[a+1]=alpha[(x2-1)*5+y2];
			
		}
		
	}
 if(x1 == x2){
		if(y1==0){
			result[a]=alpha[x1*5+4];
		}
		else{
			result[a]=alpha[x1*5+y1-1];
		}
		if(y2==0){
			result[a+1]=alpha[x2*5+4];
		}
		else{
			result[a+1]=alpha[x2*5+y2-1];
		}
		
	}
	a=a+2;
	x1=0;x2=0;y1=0;y2=0;
}
	result[a]='\0';


	free(retazec);
	free(alpha);
	return result;


}




char* array(const char* key,const char* text){
	if(key == NULL || text == NULL){
		return NULL;
	}
	
	char* kluc = (char*)calloc(strlen(key)+1,sizeof(char));
	char* kluc1 = (char*)calloc(strlen(key)+1,sizeof(char));
		for(int i=0,y=0;i<strlen(key);){
		if(key[i]==' '){
			i++;
		}
		else{
			if((key[i]== 'W')||(key[i] == 'w')){
				kluc[y]='V';
			}
			else{
			kluc[y]=toupper(key[i]);
		}
		y++;
		i++;
	}
	}
	

	for(int i=0;i<strlen(kluc);i++){
		for(int y=i+1;y<strlen(kluc);y++){
			if(kluc[i]==kluc[y]){
				kluc[y]=' ';
			}	
		}
	}
		for(int i=0,y=0;i<strlen(kluc);){
		if(kluc[i]==' '){
			i++;
		}
		else{
		kluc1[y]=toupper(kluc[i]);
		y++;
		i++;
	}
	}
	free(kluc);
	char abc[28]="ABCDEFGHIJKLMNOPQRSTUVXYZ";
	char* pole = (char*)calloc(26,sizeof(char));
	char matica[26];
	int n=0,x,i,b=0;

	for( i=0;i<strlen(abc);i++){
		for(x=0;x<strlen(kluc1);x++){
			if(abc[i]==kluc1[x]){
				b++;
			
			}
		
	}
		if(b==0){
			matica[n]=abc[i];
			n++;
		}
	
	matica[n]='\0';
	
		b=0;
	}
	char array[26];
	int a=0,p=0;
	for(a=0;a<strlen(kluc1);a++){
	
		array[a] = kluc1[a];
	
	}
		for(a=a,p=p;p<strlen(matica);a++,p++){
		array[a] = matica[p];
	}
	int z=0;
	for (int i=0;i<5;i++){
		for (int y=0;y<5;y++,z++){
		array[z]=toupper(array[z]);
			pole[i*5+y] = array[z];	
		}
	}
			pole[25] ='\0';
	
	free(kluc1);
	return pole;
}
char* res(const char* text){
	
	
	char* novy=(char*)calloc(strlen(text)*2,sizeof(char));
	char* novy1 =(char*)calloc(strlen(text)*2,sizeof(char));
	char znak=' ';
	int i,b;
	for(i=0,b=0;i<strlen(text);){
		if(text[i]== ' '){
			i++;
		}
		else{
			novy[b]=toupper(text[i]);
			b++;
			i++;
		}
}
for(i=0,b=0;i<strlen(novy);){
		if((novy[i]==znak)&&(znak != 'x' && znak != 'X')&&((b+1)%2 == 0) && (i>0)){
		novy1[b]='X';
		znak='X';
		b++;
	
	}
	else{
	novy1[b]=toupper(novy[i]);
	znak=novy[i];
	i++;
	b++;
	}
}

if((strlen(novy1)+1)%2 == 0){
	novy1[b]='X';
	novy1[b+1]='\0';
}
else{
	novy1[b]='\0';
}


for(int i=0;i<strlen(novy1);i++){
if(novy1[i] == 'W'){
	novy1[i] = 'V';
}
}
//	printf("%s \n %d \n",novy1,strlen(novy1));
	free(novy);
return novy1;

}
