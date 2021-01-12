/*Savvas Polychronakis - 1115201200150*/

#include <stdio.h>
#include <stdlib.h>

#include "Menu.h"
#include "TyposStoixeiouMenu.h"

#define MAX_OPTIONS 19

void print_options()
{
	printf("\n");
	printf("0.  Exit\n");
	printf("1.  Create menu\n");
	printf("2.  Check if current category is empty\n");
	printf("3.  Read and Insert new item in current node\n");
	printf("4.  Print current content\n");
	printf("5.  Change content of current node\n");
	printf("6.  Go to the next node\n");
	printf("7.  Go to the previous node\n");
	printf("8.  Swap current node with the next one\n");
	printf("9.  Swap current node with the previous one\n");
	printf("10. Insert new category\n");
	printf("11. Move up one category\n");
	printf("12. Move down one category\n");
	printf("13. Print content of current category and its sub-categories\n");
	printf("14. Delete the next node of the current one\n");
	printf("15. Delete all sub-categories of current node\n");
	printf("16. Cut current node\n");
	printf("17. Paste the cut node\n");
	printf("18. Destroy menu\n");
	printf("19. Switch Menu\n");
	printf("Enter your input (0-%d): ", MAX_OPTIONS);
}

int get_option()
{
	char buf[100];
	int option;

	option = -1;
	while (option < 0 || option > MAX_OPTIONS) {
		print_options();
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%d", &option);
	}
	return option;
}

int main(int argc, char *argv[]) {
	InfoMenuPtr 	FoodMenu=NULL,			//menu estiatoriou
					CafeMenu=NULL;			//menu cafeterias
					
	TStoixeiouMenu V;
	
	int option, error, menu_option = 0;
	char *restaurant_name = argv[1];
	
	
	do{
		option = get_option();
		switch(option){
		case 1:
			if(menu_option == 0){
				menu_create(&FoodMenu,&error,restaurant_name);
			}else{
				menu_create(&CafeMenu,&error,restaurant_name);
			}
			if (error) {
				printf("\nMenu already exists!\n");
			}else{
				printf("\nMenu Created!\n");
			}
			break;
		case 2:
			if(menu_empty_category(&FoodMenu)){
				printf("\nCurrent category is empty!\n");
			}else{
				printf("\nCurrent category is not empty!\n");
			}
			break;
		case 3:
			TSReadValue(&V);
			if(menu_option == 0){
				menu_insert_node(&FoodMenu, V, &error);
			}else{
				menu_insert_node(&CafeMenu, V, &error);
			}
			if(error){
				printf("\nCould not insert new item!\n");
			}else{
				printf("\nItem inserted successfully!\n");
			}
			break;
		case 4:
			if(menu_option == 0){
				menu_print(&FoodMenu, &error);
			}else{
				menu_print(&CafeMenu, &error);
			}
			if(error){
				printf("\nError! No content!\n");
			}
			break;
		case 5:
			TSReadValue(&V);
			if(menu_option == 0){
				menu_change_content(&FoodMenu, V, &error);
			}else{
				menu_change_content(&CafeMenu, V, &error);
			}
			if(error){
				printf("\nError! No content!\n");
			}else{
				printf("\nItem changed successfully!\n");
			}
			break;			
		case 6:
			if(menu_option == 0){
				menu_next(&FoodMenu);
			}else{
				menu_next(&CafeMenu);
			}
			break;
		case 7:
			if(menu_option == 0){
				menu_prev(&FoodMenu);
			}else{
				menu_prev(&CafeMenu);
			}
			break;
		case 8:
			if(menu_option == 0){
				menu_swap_next(&FoodMenu, &error);
			}else{
				menu_swap_next(&CafeMenu, &error);
			}
			if(error){
				printf("\nError! There is no next node!\n");
			}else{
				printf("\nSwapped successfully!\n");
			}
			break;
		case 9:
			if(menu_option == 0){
				menu_swap_prev(&FoodMenu, &error);
			}else{
				menu_swap_prev(&CafeMenu, &error);
			}
			if(error){
				printf("\nError! There is no previous node!\n");
			}else{
				printf("\nSwapped successfully!\n");
			}
			break;
		case 10:
			if(menu_option == 0){
				menu_insert_category(&FoodMenu, &error);
			}else{
				menu_insert_category(&CafeMenu, &error);
			}
			if(error){
				printf("\nError! Current node is head!\n");
			}else{
				printf("\nCategory inserted successfully!\n");
			}
			break;
		case 11:
			if(menu_option == 0){
				menu_up(&FoodMenu);
			}else{
				menu_up(&CafeMenu);
			}
			break;
		case 12:
			if(menu_option == 0){
				menu_down(&FoodMenu);
			}else{
				menu_down(&CafeMenu);
			}
			break;
		/*case 13:
			menu_print_category(&FoodMenu);
			break;*/
		case 14:
			if(menu_option == 0){
				menu_delete(&FoodMenu);
			}else{
				menu_delete(&CafeMenu);
			}
			break;
		/*case 15:
			menu_delete_down(&FoodMenu);
			break;*/
		case 16:
			if(menu_option == 0){
				menu_cut(&FoodMenu);
			}else{
				menu_cut(&CafeMenu);
			}
			break;
		case 17:
			if(menu_option == 0){
				menu_paste(&FoodMenu);
			}else{
				menu_paste(&CafeMenu);
			}
			break;
		/*case 18:
			menu_destroy(&FoodMenu);
			break;*/
		case 19:
			if(menu_option == 0){
				menu_option = 1;								//1 = CafeMenu
				printf("\nCurrent menu is for cafeteria!\n");
			}else{
				menu_option = 0;								//0 = FoodMenu
				printf("\nCurrent menu is for restaurant!\n");
			}
			
			break;
		}
	}while(option);
	
	
	

	
	return 0;
}
