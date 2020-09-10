#include <stdio.h>
#include <stdlib.h>

/*
 * Struct for the storage of nodes for the linked list
 */
typedef struct Node {
	char c;
	struct Node *next;
} node_t;

void add_first(node_t **, node_t *);
int insert_node(node_t **, char, int);
void print_list(node_t *);

int main(void) {
	node_t *head = (node_t *) malloc(sizeof(node_t));
	
	char input;
	scanf(" %c", &input);
	do {
		node_t *new_item = (node_t *) malloc(sizeof(node_t));
		new_item->c = input;
		new_item->next = NULL;
		
		add_first(&head, new_item);
		
		scanf(" %c", &input);
	} while (input != '*');
	
	print_list(head);
	
	insert_node(&head, 'X', 100);
	
	print_list(head);

	return 0;
}

/*
 * Adds a new node to the front of the linked list
 */
void add_first(node_t **head, node_t *new_item) {
	if (*head != NULL) {
		new_item->next = *head;
	}
	*head = new_item;
}

/*
 * Adds a new node to index-th element in the linked list
 */
int insert_node(node_t **head, char new_item, int index) {
	node_t *new_node = (node_t *) malloc(sizeof(node_t));			
	new_node->c = new_item;	
	new_node->next = NULL;
	
	if (*head == NULL && index != 0) {								
		printf("ERROR: Function is not long enought!\n");
	}
	
	int i = 0;
	if (index == 0) {												
		add_first(head, new_node);
	} else {
		node_t *tmp_node = *head;
		for (i = 1; i < index - 1; i++) {								
			if (tmp_node->next == NULL) {							
				printf("ERROR: Function is not long enough!\n");
				return i;
			}
			tmp_node = tmp_node->next;
		}
		
		new_node->next = tmp_node->next;
		tmp_node->next = new_node;
	}
	
	node_t *tmp_node = new_node;
	while (tmp_node != NULL) {
		tmp_node = tmp_node->next;
		i++;
	}
	
	return i + 1;
}

/*
 *Prints all values in the list by traversing through the list from the head
 */
void print_list(node_t *head) {
	node_t* temp_node = head;
	while(temp_node != NULL) {
		printf("%c ", temp_node->c);
		temp_node = temp_node->next;
	}
	printf("\n");
}