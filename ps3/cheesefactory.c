#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592653

int main()
{
	int diery=0;
	int platky=0;
	
	scanf(" %d",&diery);
	scanf(" %d",&platky);
	
	float polomer[diery];
	float x[diery];
	float y[diery];
	float z[diery];
	for(int i=0;i<diery;i++){
		scanf(" %f",&polomer[i]);
		polomer[i]=polomer[i]/(1000);
		scanf(" %f",&x[i]);
		x[i] = x[i]/(1000);
	
		scanf(" %f",&y[i]);
		y[i] = y[i]/(1000);
	
		scanf(" %f",&z[i]);
		z[i] = z[i]/(1000);
	
	}
	
	double objem = pow(100,3);
	for(int i=0;i<diery;i++){
		objem = objem - ((4.00/3.00)*PI*pow(polomer[i],3));
	}

	double objem_spravny=0.00,sirka=0.00,minimum=0.00,maximum = 100.00,objem_casti = 0.0, vyska = 0.0;
	
	for(int y=0,poradie = 1;y < platky; y++,poradie++){
		objem_spravny = (objem/platky)*poradie;
			minimum = sirka;
			maximum = 100.0;
			
		while(maximum-minimum > 0.0000000001){
			vyska = (maximum+minimum)/2;
			objem_casti = vyska*pow(100,2);
			
			for(int i=0; i<diery; i++){
				
	double vyska_v;
	double objem_gule;
	if(2*polomer[i]<vyska-(z[i]-polomer[i]) && 2*polomer[i]>0.0){
		vyska_v = 2*polomer[i];
	}

	if(2*polomer[i]>vyska-(z[i]-polomer[i]) && vyska-(z[i]-polomer[i])>0.0){
		vyska_v = vyska-(z[i]-polomer[i]);
	}
	if(2*polomer[i]>vyska-(z[i]-polomer[i]) && vyska-(z[i]-polomer[i])<0.0){
		vyska_v = 0;
	}
	objem_gule = PI*pow(vyska_v,2)*(polomer[i]-vyska_v/3);	
				

			objem_casti = objem_casti - objem_gule;
			}
			
			if(objem_casti>objem_spravny){
					maximum = vyska;
				}
			else{
					minimum = vyska;
				}
		}
		
		printf("%.9f\n",(((maximum+minimum)/2)-sirka));
		sirka = (maximum+minimum)/2;
	}

	return 0;
}
