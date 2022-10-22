#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include <math.h>
#include "bmp.h"


unsigned char * bmp_encrypt(const char* key, const char* text){
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
	unsigned char* encrypt;
	char* en;
	char* enn;
	en = reverse(text);
	enn = vigenere_encrypt(key,en);
	encrypt = bit_encrypt(enn);
	free(en);
	free(enn);
	return encrypt;

}
char* bmp_decrypt(const char* key, const unsigned char* text){
    
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
	char* decrypt;
	char* de;
	char* dee;
	de = bit_decrypt(text);
	dee = vigenere_decrypt(key,de);
	decrypt = reverse(dee);
	free(de);
	free(dee);
	return decrypt;
}

char* reverse(const char* text){
    if(text == NULL){
        return NULL;
    }
	char *reversed = (char*)calloc(strlen(text)+1,sizeof(char));
	int i=0;
 	int l=strlen(text)-1;
	
	do{
        reversed[i] = text[l];
        reversed[i] = toupper(reversed[i]);
        i++;
        l--;
    }while(text[i] != '\0');
   

    return reversed;
    
}

char* vigenere_encrypt(const char* key, const char* text){
	if( key == NULL || text == NULL){
		return NULL;
	}
	int g=0;
	while(key[g] != '\0'){
		if(!isalpha(key[g])){
			return NULL;
		}
		g++;
	}
	char *key1 = (char*)calloc(strlen(text)+1,sizeof(char));
	for(int i=0,y=0;i<strlen(text);i++){
		if(!isalpha(text[i])){
			key1[i] = text[i];
			
		}
		else{
		
		key1[i] = key[y];	
		key1[i] = toupper(key1[i]);
		y++;
	}
		if(y==strlen(key)){
			y=0;
		}
		key1[i+1]='\0';
	}
	printf("%s    ",key1);
		char *text1 = (char*)calloc(strlen(text)+1,sizeof(char));
	for(int i=0;i<strlen(text);i++){
		text1[i] = toupper(text[i]);
	}
	char *encrypt = (char*)calloc(strlen(text)+1,sizeof(char));
	int i=0;

	
	
	do{
		if(!isalpha(text[i])){
			encrypt[i] = text[i];
		}
		
		else{
        encrypt[i] = (text1[i]+key1[i])%26 +'A';
    }
		i++;
    }while(text[i] != '\0');
	
	free(key1);
	free(text1);
	return encrypt;
}

char* vigenere_decrypt(const char* key, const char* text){
		if( key == NULL || text == NULL){
		return NULL;
	}
	int g=0;
	while(key[g] != '\0'){
		if(!isalpha(key[g])){
			return NULL;
		}
		g++;
	}
	char *key1 = (char*)calloc(strlen(text)+1,sizeof(char));
	for(int i=0,y=0;i<strlen(text);i++){
		if(!isalpha(text[i])){
			key1[i] = text[i];
			
		}
		else{
		
		key1[i] = key[y];	
		key1[i] = toupper(key1[i]);
		y++;
	}
		if(y==strlen(key)){
			y=0;
		}
		key1[i+1]='\0';
	}
	printf("%s    ",key1);
		char *text1 = (char*)calloc(strlen(text)+1,sizeof(char));
	for(int i=0;i<strlen(text);i++){
		text1[i] = toupper(text[i]);
	}
	char *decrypt = (char*)calloc(strlen(text)+1,sizeof(char));
	int i=0;

	
	do{
		if(!isalpha(text[i])){
			decrypt[i] = text[i];
		}
		
		else{
        decrypt[i] = (((text1[i]-key1[i])+ 26) % 26) + 'A';
    }
		i++;
    }while(text[i] != '\0');
	
	free(key1);
	free(text1);
	return decrypt;
	
	
}

char* bit_decrypt(const unsigned char* text){
	if(text == NULL){
		return NULL;
	}
	int a=0,l=0;
	while(text[a] != '\0'){
		l++;
		a++;
	}
	char* result = (char*)calloc(l+1,sizeof(char));
	unsigned char* word = (unsigned char*)calloc(9,sizeof(char));
	for(size_t i=0; text[i] != '\0'; i++){
	int c, d, count;

	   count = 0;

	   for (c = 7 ; c>=0 ; c--)
	   {
	      d = text[i] >> c;

	      if (d & 1)
	         *(word+count) = 1 + '0';
     	 else
       		  *(word+count) = 0 + '0';

	      count++;
	   }
//	   *(word+count) = '\0';

//		word = decimal_to_binary(text[i]) ;
	for(size_t a=0,b=4;a<4;a++,b++){
			if(word[a] == word[b]){
				word[b] = '0';
			}
			else{
				word[b] = '1';
			}
		}
			 a = word[0];
			word[0] = word[1];
			word[1] = a;
			 a = word[2];
			word[2] = word[3];
			word[3] = a;
	
	//printf("%s\t",word);

		int x,y=0;
        int decimal=0;
        int a;
        for(x=0,y=7;word[x] != '\0';x++,y--){
                a=word[y]-'0';
                decimal=decimal+a*pow(2,x);
        }

		
		*(result+i) = decimal;
	//	printf("%d\t%d\n",decimal, result[i]);
	}	
	free(word);
	return result;
		
			
	}
	


unsigned char* bit_encrypt(const char* text){
	if(text == NULL){
		return NULL;
	}
	int a;
	unsigned char* result = (unsigned char*)calloc(strlen(text)+1,sizeof(char));
	char* word = (char*)calloc(9,sizeof(char));
	for(size_t i=0; text[i] != '\0'; i++){
	int c, d, count;

	   count = 0;

	   for (c = 7 ; c>=0 ; c--)
	   {
	      d = text[i] >> c;

	      if (d & 1)
	         *(word+count) = 1 + '0';
     	 else
       		  *(word+count) = 0 + '0';

	      count++;
	   }
//	   *(word+count) = '\0';

//		word = decimal_to_binary(text[i]) ;
			 a = word[0];
			word[0] = word[1];
			word[1] = a;
			 a = word[2];
			word[2] = word[3];
			word[3] = a;
		for(size_t a=0,b=4;a<4;a++,b++){
			if(word[a] == word[b]){
				word[b] = '0';
			}
			else{
				word[b] = '1';
			}
		}
	//printf("%s\t",word);

		int x,y=0;
        int decimal=0;
        int a;
        for(x=0,y=7;word[x] != '\0';x++,y--){
                a=word[y]-'0';
                decimal=decimal+a*pow(2,x);
        }

		
		*(result+i) = decimal;
	//	printf("%d\t%d\n",decimal, result[i]);
	}	
	free(word);
	return result;
}