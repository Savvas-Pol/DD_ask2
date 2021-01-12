/*Savvas Polychronakis - 1115201200150*/

#ifndef __MENU__
#define __MENU__

#include "TyposStoixeiouMenu.h"

typedef struct InfoMenu *InfoMenuPtr;		//o tupos deikti se pliroforiako komvo menu


void menu_create(InfoMenuPtr *info, int *error, char *restaurant_name);
int menu_empty_category(InfoMenuPtr *info);
void menu_insert_node(InfoMenuPtr *info, TStoixeiouMenu data, int *error);
void menu_print(InfoMenuPtr *info, int *error);
void menu_change_content(InfoMenuPtr *info, TStoixeiouMenu data, int *error);
void menu_next(InfoMenuPtr *info);
void menu_prev(InfoMenuPtr *info);
void menu_swap_next(InfoMenuPtr *info, int *error);
void menu_swap_prev(InfoMenuPtr *info, int *error);
void menu_insert_category(InfoMenuPtr *info, int *error);
void menu_up(InfoMenuPtr *info);
void menu_down(InfoMenuPtr *info);
//void menu_print_category(InfoMenuPtr *info);
void menu_delete(InfoMenuPtr *info);
//void menu_delete_down(InfoMenuPtr *info);
void menu_cut(InfoMenuPtr *info);
void menu_paste(InfoMenuPtr *info);
//void menu_destroy(InfoMenuPtr *info);

#endif
