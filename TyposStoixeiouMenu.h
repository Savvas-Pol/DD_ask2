/*Savvas Polychronakis - 1115201200150*/

#ifndef __TSMENU__
#define __TSMENU__
#include <stdio.h>

typedef struct Komvos {
	char * name; 	// Name of Category or Plate
	int Category;	// 0 if Plate, 1 if Category
	float Price;	// Valid only if Plate
} TStoixeiouMenu;

void TSSetValue(TStoixeiouMenu *Lhs, TStoixeiouMenu Rhs); // Lhs = Rhs
int TSPrintValue(TStoixeiouMenu V);
int TSReadValue(TStoixeiouMenu * V);
#endif
