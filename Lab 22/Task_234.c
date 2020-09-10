#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int num;
	struct Node *previous;
	struct Node *next;
} node_t;

void delete_last(node_t **, node_t **);
void add_in_middle(int, node_t **, node_t **);
void print_list(node_t *);

int main(void) {
	node_t *head = NULL;
	node_t *tail = NULL;
	
	int new_num;
	while (scanf("%d", &new_num) && new_num != 0) {
		add_in_middle(new_num, &head, &tail);
		print_list(head);
	}
	
	while(tail != NULL) {
		delete_last(&head, &tail);
	}

	return 0;
}

void delete_last(node_t **head, node_t **tail) {
	if ((*tail) == (*head)) {
		*head = NULL;
	}
	
	if ((*tail)->previous != NULL) {
		*tail = (*tail)->previous;
		free((*tail)->next);
		(*tail)->next = NULL;
	} else {
		free(*tail);
		*tail = NULL;
	}
}

void add_in_middle(int new_data, node_t **head, node_t **tail) {
	node_t *new_ptr = (node_t *) malloc(sizeof(node_t));
	new_ptr->num = new_data;
	new_ptr->previous = NULL;
	new_ptr->next = NULL;
	
	if ((*head) == NULL || (*tail) == NULL) {
		*head = new_ptr;
		*tail = new_ptr;
	} else if ((*head) == (*tail)) {
		*tail = new_ptr;
		(*head)->next = *tail;
		(*tail)->previous = *head;
	} else {
		node_t *tmp_fwrd_ptr = *head;
		node_t *tmp_back_ptr = *tail;
		
		while (1) { //Made while loop infinite and simply used break statements to end loop
			if (tmp_fwrd_ptr == tmp_back_ptr) {
				new_ptr->previous = tmp_back_ptr;
				new_ptr->next = tmp_back_ptr->next;
				tmp_back_ptr->next->previous = new_ptr;
				tmp_back_ptr->next = new_ptr;
				break;
			} else if (tmp_fwrd_ptr->next == tmp_back_ptr) {
				new_ptr->previous = tmp_fwrd_ptr;
				new_ptr->next = tmp_back_ptr;
				tmp_fwrd_ptr->next = new_ptr;
				tmp_back_ptr->previous = new_ptr;
				break;
			}
			
			tmp_fwrd_ptr = tmp_fwrd_ptr->next;
			tmp_back_ptr = tmp_back_ptr->previous;
		}
	}
}

void print_list(node_t *head) {
	for (node_t *tmp_ptr = head; tmp_ptr != NULL; tmp_ptr = tmp_ptr->next) {
		printf("%d ", tmp_ptr->num);
	}
	printf("\n");
}