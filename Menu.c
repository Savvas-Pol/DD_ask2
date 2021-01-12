/*Savvas Polychronakis - 1115201200150*/

#include <stdlib.h>
#include <assert.h>
#include "Menu.h"

typedef struct MenuNode *MenuNodePtr;	//o tupos deikti se komvo

typedef struct InfoMenu {	//o pliroforiakos komvos
	char* 	  Name;				//to onoma tou estiatoriou	
	MenuNodePtr Start;			//deiktis ston prwto komvo tis anwteris katigorias
	MenuNodePtr Current;		//deiktis ston trexonta komvo
	MenuNodePtr CutToPaste;		//deiktis ston komvo pros metafora
}InfoMenu;

typedef struct MenuNode {			//o komvos gia katigoria i piato
	MenuNodePtr Prev, Next, Up, Down;	//oi deiktes gia ti dipla sindedemeni lista
	TStoixeiouMenu Data;				//oi deiktes gia katigoria-upokatigoria
}MenuNode;


void menu_create(InfoMenuPtr *info, int *error, char *restaurant_name){
	
	MenuNodePtr menu_head;
	
	if((*info)){
		*error = 1;
	}else{
		*error = 0;
		
		(*info) = malloc(sizeof(InfoMenu));
		menu_head = malloc(sizeof(MenuNode));
		menu_head->Prev = NULL;
		menu_head->Next = NULL;
		menu_head->Up = NULL;
		menu_head->Down = NULL;
		
		(*info)->Name = restaurant_name;
		(*info)->Start = menu_head;
		(*info)->Current = menu_head;
		(*info)->CutToPaste = NULL;
	}
	
}

int menu_empty_category(InfoMenuPtr *info){
	
	assert((*info));
	return((*info)->Current->Prev == NULL && (*info)->Current->Next == NULL);
	
}

void menu_insert_node(InfoMenuPtr *info, TStoixeiouMenu data, int *error){
	
	MenuNodePtr new_node;
	
	new_node = malloc(sizeof(MenuNode));
	if(new_node == NULL){
		*error = 1;
		return;
	}
	
	TSSetValue(&(new_node->Data), data);
	
	new_node->Prev = (*info)->Current;
	new_node->Next = (*info)->Current->Next;
	new_node->Up = (*info)->Current->Up;
	new_node->Down = NULL;
	
	(*info)->Current->Next = new_node;
	(*info)->Current = new_node;
}

void menu_print(InfoMenuPtr *info, int *error){
	if((*info)->Current->Prev == NULL){		
		*error = 1;
	}else{
		*error = 0;
		
		if((*info)->Current->Data.Category == 0){					//piato-ektipwse onoma kai timi
			printf("\nCurrent plate: ");
			TSPrintValue((*info)->Current->Data);
			printf("\n");
		}else{														//katigoria-ektipwse mono onoma
			printf("\nCurrent category is: ");
			TSPrintValue( (*info)->Current->Data);
			printf("\n");
		}
	}	
}

void menu_change_content(InfoMenuPtr *info, TStoixeiouMenu data, int *error){
	
	if((*info)->Current->Prev == NULL){
		*error = 1;
	}else{
		*error = 0;
		
		TSSetValue(&((*info)->Current->Data), data);
	}
	
}

void menu_next(InfoMenuPtr *info){
	
	if((*info)->Current->Next != NULL){
		(*info)->Current = (*info)->Current->Next;
	}
	
}

void menu_prev(InfoMenuPtr *info){
	
	if((*info)->Current->Prev != NULL){
		(*info)->Current = (*info)->Current->Prev;
	}
	
}

void menu_swap_next(InfoMenuPtr *info, int *error){
	
	MenuNodePtr temp;
	
	temp = malloc(sizeof(MenuNode));
	if((*info)->Current->Prev != NULL){					//if current node is head		
		if((*info)->Current->Next == NULL){
			*error = 1;
		}else{
			*error = 0;
			
			temp = (*info)->Current->Next;
			
			(*info)->Current->Prev->Next = (*info)->Current->Next;
			if(temp->Next != NULL){
				temp->Next->Prev = (*info)->Current;
			}
			
			(*info)->Current->Next = temp->Next;
			temp->Next = (*info)->Current;
			temp->Prev = (*info)->Current->Prev;
			(*info)->Current->Prev = temp;		
			
		}
	}	
}

void menu_swap_prev(InfoMenuPtr *info, int *error){
	
	MenuNodePtr temp;
	
	temp = malloc(sizeof(MenuNode));
	if((*info)->Current->Prev != NULL){				//if current node is head
		if((*info)->Current->Prev->Prev == NULL){
			*error = 1;
		}else{
			*error = 0;
			
			temp = (*info)->Current->Prev;
			
			temp->Prev->Next = (*info)->Current;
			if((*info)->Current->Next != NULL){
				(*info)->Current->Next->Prev = temp;
			}
			
			(*info)->Current->Prev = temp->Prev;
			temp->Prev = (*info)->Current;
			temp->Next = (*info)->Current->Next;
			(*info)->Current->Next = temp;
			
		}
	}	
}

void menu_insert_category(InfoMenuPtr *info, int *error){
	
	MenuNodePtr new_node;
	
	if((*info)->Current->Prev == NULL){
		*error = 1;
	}else{
		*error = 0;
	
		new_node = malloc(sizeof(MenuNode));
		if(new_node == NULL){
			*error = 1;
			return;
		}
		
		new_node->Up = (*info)->Current;
		new_node->Down = NULL;
		new_node->Prev = NULL;
		new_node->Next = NULL;
		
		(*info)->Current->Down = new_node;
				
	}
	
}

void menu_up(InfoMenuPtr *info){
	
	if((*info)->Current->Up != NULL){
		(*info)->Current = (*info)->Current->Up;
	}
	
}

void menu_down(InfoMenuPtr *info){
	
	if((*info)->Current->Down != NULL){
		(*info)->Current = (*info)->Current->Down;
	}
	
}

/*void menu_print_category(InfoMenuPtr *info){
	
		
	
	
	
	
}*/

void menu_delete(InfoMenuPtr *info){
	
	MenuNodePtr temp;
	
	if((*info)->Current->Next != NULL){
		if((*info)->Current->Next->Down == NULL){
			
			temp = (*info)->Current->Next;
			(*info)->Current->Next = (*info)->Current->Next->Next;
			free(temp);
			
		}
	}	
}

/*void menu_delete_down(InfoMenuPtr *info){
	
		
	
	
	
}*/

void menu_cut(InfoMenuPtr *info){
	
	
	if((*info)->Current->Next != NULL){
		(*info)->Current->Next->Prev = (*info)->Current->Prev;		
	}
	(*info)->Current->Prev->Next = (*info)->Current->Next;
	
	(*info)->CutToPaste = (*info)->Current;
	(*info)->Current = (*info)->Current->Prev;	
	
}

void menu_paste(InfoMenuPtr *info){
	
	if((*info)->Current->Next != NULL){
		(*info)->CutToPaste->Next = (*info)->Current->Next;
	}else{
		(*info)->CutToPaste->Next = NULL;
	}
	(*info)->CutToPaste->Prev = (*info)->Current;
	
	if((*info)->Current->Next != NULL){
		(*info)->Current->Next->Prev = (*info)->CutToPaste;
	}
	(*info)->Current->Next = (*info)->CutToPaste;
	
	(*info)->Current = (*info)->CutToPaste;	
	
}

/*void menu_destroy(InfoMenuPtr *info){
	
	
	

		
	
}*/



