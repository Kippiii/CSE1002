#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	char value;
	struct Node *previous;
	struct Node *next;
} node_t;

int is_empty();
void push(char);
char pop();

node_t *top = NULL;

int main(void) {
	printf("Please add characters to the stack and end with '*': \n");
	
	char curr;
	while (scanf(" %c", &curr) && curr != '*') {
		push(curr);
	}
	
	printf("\nHere is the stack: ");
	while (!is_empty()) {
		printf("%c ", pop());
	}
	printf("\n");

	return 0;
}

int is_empty() {
	return top == NULL;
}

void push(char item) {
	node_t *new_ptr = (node_t *) malloc(sizeof(node_t));
	new_ptr->value = item;
	new_ptr->previous = NULL;
	new_ptr->next = NULL;
	
	new_ptr->next = top;
	
	if (!is_empty()) {
		new_ptr->previous = top->previous;
	}
	
	top = new_ptr;
}

char pop() {
	char value = top->value;
	
	if (is_empty()) {
		return '\0';
	}
	
	if (top->next == NULL) {
		top = NULL;
	} else {
		top = top->next;
		free(top->previous);
		top->previous = NULL;
	}
	
	return value;
}