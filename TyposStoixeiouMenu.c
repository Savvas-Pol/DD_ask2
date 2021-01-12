/*Savvas Polychronakis - 1115201200150*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "TyposStoixeiouMenu.h"

void TSSetValue(TStoixeiouMenu *Lhs, TStoixeiouMenu Rhs){
	
	Lhs->name = malloc(20*sizeof(char));
	
	strcpy(Lhs->name,Rhs.name);
	Lhs->Category = Rhs.Category;
	Lhs->Price = Rhs.Price;
	
}

int TSPrintValue( TStoixeiouMenu V){
	
	printf("%s ", V.name);
	if(V.Category == 0){
		printf("%.2f ", V.Price);
	}
	printf("\n");
	
}

int TSReadValue( TStoixeiouMenu * V){
	
	V->name = malloc(20*sizeof(char));
	
	printf("Give name and category (0 = Plate, 1 = Category)\n");
	scanf("%s %d",V->name, &(V->Category)); 
		
	if((V->Category) == 0){
		printf("Give the price of the plate\n");
		scanf("%f", &(V->Price));
	}
	
}
