#include <stdio.h>
#include <stdlib.h>

//Struct for the storage of nodes for the linked list
struct node_t {
	char c;
	struct node_t* next;
};

void print_list();
void add_node(char);

//Global variable for the head of the linked list
struct node_t* head = NULL;

int main(void) {
	printf("Please enter characters for the list: \n");
	
	char new_item;
	scanf(" %c", &new_item);
	
	//Continually accepts user input until a '*' character is entered
	while(new_item != '*') {
		add_node(new_item);
		print_list();
		scanf(" %c", &new_item);
	}

	return 0;
}

//Prints all values in the list by traversing through the list from the head
void print_list() {
	struct node_t* temp_node = head;
	while(temp_node != NULL) {
		printf("%c ", temp_node->c);
		temp_node = temp_node->next;
	}
	printf("\n");
}

//Adds a node to the end of the list be traversing through the list until the end
void add_node(char new_item) {
	//Generates a new node called new_node
	struct node_t* new_node = (struct node_t*) malloc(sizeof(struct node_t));
	new_node->c = new_item;
	new_node->next = NULL;
	
	//Sets the head to a new variable, temp_node
	struct node_t* temp_node = head;
	
	//Finds the last node in the list and adds new_node to it
	if(temp_node == NULL) {
		head = new_node;
	}else{
		while(temp_node->next != NULL) {
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
	}
}