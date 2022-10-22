#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float max(double a, double b);
int main(){
	int pocet=0;
	int cas=0;
	double minimum = -1000.00, maximum = 1001000.00;
	scanf(" %d",&pocet);
	scanf(" %d",&cas);
	
	float draha[pocet];
	float rychlost[pocet];

	for(int i=0; i<pocet;i++){
		scanf(" %f",&draha[i]);
		scanf(" %f",&rychlost[i]);
		minimum=max(minimum, -rychlost[i]);
	}
	double c,t;
	while (maximum-minimum > 0.000000001) {
	c = (maximum+minimum)/2;
	t=0;
    for (int i = 0; i < pocet; i++){
      	t = t+draha[i] / (rychlost[i] + c);
	  }
	  
      if (t > cas) {
	  minimum = c;
	  }
	else{
	 maximum = c;
}

    }

    printf("%.9lf\n",c);
  
	return 0;
}
float max(double a, double b){
	return (a>b)?a:b;
}