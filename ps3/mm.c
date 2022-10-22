#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int spocitaj(unsigned long long int cislo);
int main()
{
        char c;
        unsigned long long int a=0;
        while((c = getchar()) != '\n'){
        a=a+(c-'0');
}
        printf("%d\n",spocitaj(a));

        return 0;
}
int spocitaj(unsigned long long int cislo){
        unsigned long long int num=0;
        unsigned long long int cislo1=0;
        while(cislo/10 >0){
        cislo1=cislo%10;
        cislo=cislo/10;
        num = num + cislo1;
        }
        num = num+cislo%10;
    
        return (num>9)?spocitaj(num):num;

}

