#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int num;
	struct Node *next;
} node_t;

void print_list(node_t *);

int main(void) {
	int new_num;
	node_t *head_ptr = NULL;
	
	while (scanf("%d", &new_num) && new_num != 0) {
		node_t *new_ptr = (node_t *) malloc(sizeof(node_t));
		new_ptr->num = new_num;
		new_ptr->next = NULL;
		
		if (head_ptr == NULL) {
			head_ptr = new_ptr;
		} else if (head_ptr->num > new_num) {
			new_ptr->next = head_ptr;
			head_ptr = new_ptr;
		} else {
			node_t *tmp_ptr;
			for (tmp_ptr = head_ptr; tmp_ptr->next != NULL; tmp_ptr = tmp_ptr->next) {
				if (tmp_ptr->next->num > new_num) {
					break;
				}
			}
			
			new_ptr->next = tmp_ptr->next;
			tmp_ptr->next = new_ptr;
		}
		
		print_list(head_ptr);
	}

	return 0;
}

void print_list(node_t *head) {
	for (node_t *tmp_ptr = head; tmp_ptr != NULL; tmp_ptr = tmp_ptr->next) {
		printf("%d ", tmp_ptr->num);
	}
	printf("\n");
}