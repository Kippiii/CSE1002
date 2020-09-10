#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int value;
	struct Node *next;
	struct Node *previous;
} node_t;


void swap(node_t **, node_t **, node_t *, node_t *);
void sort(node_t **, node_t **);
void delete(int, node_t **, node_t **);
void print_list(node_t *);


int main(void) {
	node_t *head = NULL;
	node_t *tail = NULL;
	
	printf("Please enter values for the list (ends with -1):\n");
	
	int new_value;
	while (scanf("%d", &new_value) && new_value != -1) {
		node_t *new_node = (node_t *) malloc(sizeof(node_t));
		new_node->value = new_value;
		new_node->previous = tail;
		new_node->next = NULL;
		
		if (tail != NULL) {
			tail->next = new_node;
		}
		
		tail = new_node;
		
		if (head == NULL) {
			head = new_node;
		}
	}
	
	printf("List: ");
	print_list(head);
	
	swap(&head, &tail, head, (head->next));
	printf("List after swapping head and head->next: ");
	print_list(head);
	
	swap(&head, &tail, (head->next), (tail->previous));
	printf("List after swapping head->next and tail->prev: ");
	print_list(head);
	
	sort(&head, &tail);
	printf("\nList after sorting: ");
	print_list(head);
	
	printf("\nList after calling delete(5, &head, &tail): ");
	delete(5, &head, &tail);
	print_list(head);
	
	printf("List after calling delete(6, &head, &tail): ");
	delete(6, &head, &tail);
	print_list(head);

	return 0;
}


void swap(node_t **head, node_t **tail, node_t *first, node_t *second) {
	//Deals with case where the nodes are the same
	if (first == second) {
		return;
	}
	
	node_t *tmp_next = first->next;
	first->next = second->next;
	second->next = tmp_next;
	
	node_t *tmp_previous = first->previous;
	first->previous = second->previous;
	second->previous = tmp_previous;
	
	//Deals with case of consecutive nodes
	if (first->previous == first) {
		first->previous = second;
		second->next = first;
	} else if (first->next == first) {
		first->next = second;
		second->previous = first;
	}
	
	//Sets values of surrounding nodes
	if (first->next != NULL) {
		first->next->previous = first;
	}
	if (second->next != NULL) {
		second->next->previous = second;
	}
	
	if (first->previous != NULL) {
		first->previous->next = first;
	}
	if (second->previous != NULL) {
		second->previous->next = second;
	}
	
	//Deals with case where one of the nodes is the head
	if (*head == first) {
		*head = second;
	} else if (*head == second) {
		*head = first;
	}
	
	//Deals with case where one of the nodes is the tail
	if (*tail == first) {
		*tail = second;
	} else if (*tail == second) {
		*tail = first;
	}
}


void sort(node_t **head, node_t **tail) {
	for (node_t *tmp_node1 = *head; tmp_node1->next != NULL; tmp_node1 = tmp_node1->next) {
		node_t *lowest = tmp_node1;
		
		for (node_t *tmp_node2 = tmp_node1->next; tmp_node2 != NULL; tmp_node2 = tmp_node2->next) {
			if (tmp_node2->value < lowest->value) {
				lowest = tmp_node2;
			}
		}
		
		swap(head, tail, tmp_node1, lowest);
		tmp_node1 = lowest;
	}
}


void delete(int data, node_t **head, node_t **tail) {
	//Deals with case where value is at the beginning of the list
	if ((*head)->value == data) {
		*head = (*head)->next;
		free((*head)->previous);
		(*head)->previous = NULL;
		return;
	}
	
	//Deals with case where value is in the middle of list
	for (node_t *tmp_node = (*head)->next; tmp_node->next != NULL; tmp_node = tmp_node ->next) {
		if (tmp_node->value == data) {
			tmp_node->next->previous = tmp_node->previous;
			tmp_node->previous->next = tmp_node->next;
			free(tmp_node);
			return;
		}
	}
	
	//Deals with case where value is at the end of list
	if ((*tail)->value == data) {
		*tail = (*tail)->previous;
		free((*tail)->next);
		(*tail)->next = NULL;
		return;
	}
	
	//Deals with case where value is not in list
	printf("ERROR: %d not found in list!\n", data);
}

//Function that prints all values in the list
void print_list(node_t *head) {
	printf("%d", head->value);
	for (node_t *tmp_node = head->next; tmp_node != NULL; tmp_node = tmp_node->next) {
		printf("->%d", tmp_node->value);
	}
	printf("\n");
}