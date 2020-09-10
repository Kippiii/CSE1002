#include <stdio.h>
#include <stdlib.h>


/*
 * Struct for the storage of nodes for the linked list
 */
typedef struct Node {
	char c;
	struct Node *next;
} node_t;


void add_node(node_t **, char);
void search_node(node_t *, char);
void print_range(node_t *, int, int);
void free_list(node_t **);


int main(void) {
	node_t *head_ptr = NULL;		/* Creates an empty linked list */
	
	add_node(&head_ptr, 'A');		/* Adds A-H to linked list */
	add_node(&head_ptr, 'B');
	add_node(&head_ptr, 'C');
	add_node(&head_ptr, 'D');
	add_node(&head_ptr, 'E');
	add_node(&head_ptr, 'F');
	add_node(&head_ptr, 'G');
	add_node(&head_ptr, 'H');
	
	search_node(head_ptr, 'D');		/*Searches linked list for D and Q */
	search_node(head_ptr, 'Q');
	
	print_range(head_ptr, 1, 4);	/* Prints two ranges from the linked list */
	print_range(head_ptr, 5, 9);
	
	free_list(&head_ptr);			/* Frees all elements in the linked list and sets their pointers to NULL */

	return 0;
}


/*
 * Adds a node to the end of the list be traversing through the list until the end
 */
void add_node(node_t **head, char new_item) {
	node_t *new_node = (node_t *) malloc(sizeof(node_t));	/* Generates a new node called new_node */
	new_node->c = new_item;
	new_node->next = NULL;
	
	node_t *temp_node = *head;								/* Sets the head to a new variable, temp_node */
	
	if (temp_node == NULL) {								/* Sets the node to the head if the list is empty */
		*head = new_node;
	} else {
		while (temp_node->next != NULL) {					/* Finds the last node in the list and adds new_node to it */
			temp_node = temp_node->next;
		}
		temp_node->next = new_node;
	}
}


/*
 * Prints contents of node containing data
 * Prints 'not found' if that node is not in the linked list
 */
void search_node(node_t *head_ptr, char data) {
	for (node_t *tmp_node = head_ptr; tmp_node != NULL; tmp_node = tmp_node->next) {	/* Loops through every element in the linked list */
		if (tmp_node->c == data) {														/* Prints tmp_node->c if it is equal to data and ends the function */	
			printf("%c\n", tmp_node->c);
			return;
		}
	}
	printf("not found\n");																/* Prints if node is not found */	
}


/*
 * Prints all values in nodes in the range [start, end]
 */
void print_range(node_t *head_ptr, int start, int end) {
	node_t *tmp_node;
	int i;
	for (tmp_node = head_ptr, i = 0; tmp_node != NULL && i < start; tmp_node = tmp_node->next, i++) {}	/* Finds the start of the linked list */		
	
	if (i < start || start > end) {																		/* Prints error when preconditions are not meet */
		printf("<Error>\n");
	}
	
	for (; i <= end; tmp_node = tmp_node->next, i++) {
		if (tmp_node == NULL) {																			/* Prints an error if end of linked list is reached before end value is reached */	
			printf("<Error>");
			break;
		}
		printf("%c ", tmp_node->c);																		/* Prints each value in the linked list */	
	}
	printf("\n");
}


/*
 * Frees the memory of the linked list
 */
void free_list(node_t **head_ptr) {
	if (*head_ptr == NULL) {				/* Does nothing if linked list is already empty */
		return;
	}
	if ((*head_ptr)->next != NULL) {
		free_list(&((*head_ptr)->next));	/* Calls function recursively until at end of list */
	}
	free(*head_ptr);						/* Frees spot in memory and sets its pointer to NULL */
	*head_ptr = NULL;
}