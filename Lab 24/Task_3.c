#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
	struct Node *previous;
} node_t;

int dequeue(node_t **, node_t **);
void enqueue(node_t **, node_t **, int);
int is_empty(node_t *);

int main(void) {
	node_t *head = NULL;
	node_t *tail = NULL;
	
	printf("Please enter numbers to add to queue (-1 to stop):\n");
	
	int new_val;
	while (scanf("%d", &new_val) && new_val != -1) {
		enqueue(&head, &tail, new_val);
	}
	
	printf("\nValues in queue as dequeued:\n");
	while (!is_empty(head)) {
		printf("%d ", dequeue(&head, &tail));
	}
	printf("\n");

	return 0;
}

int dequeue(node_t **head, node_t **tail) {
	if (is_empty(*head)) {
		return -1;
	}
	
	if (*head == *tail) {
		int value = (*head)->value;
		*head = NULL;
		*tail = NULL;
		return value;
	}
	
	int value = (*head)->value;
	*head = (*head)->next;
	free((*head)->previous);
	(*head)->previous = NULL;
	return value;
}

void enqueue(node_t **head, node_t **tail, int value) {
	node_t *new_node = (node_t *) malloc(sizeof(node_t));
	new_node->value = value;
	new_node->next = NULL;
	new_node->previous = *tail;
	
	if (*head == NULL) {
		*head = new_node;
		*tail = new_node;
	} else {
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

int is_empty(node_t *head) {
	return head == NULL;
}