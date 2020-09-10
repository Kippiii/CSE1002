#include <stdio.h>
#include <stdlib.h>

struct adjacency_list_node_t {
	int dest;
	struct adjacency_list_node_t *next;
};

struct adjacency_list_t {
	struct adjacency_list_node_t *head;
};

struct Graph {
	int V;
	struct adjacency_list_t **adj_list;
};

int main(void) {
	struct Graph *figure1 = malloc(sizeof(struct Graph));
	figure1->V = 6;
	figure1->adj_list = malloc(figure1->V * sizeof(struct adjacency_list_t *));
	
	figure1->adj_list[0] = (struct adjacency_list_t *) malloc(sizeof(struct adjacency_list_t));
	figure1->adj_list[0]->head = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[0]->head->dest = 5;
	figure1->adj_list[0]->head->next = NULL;
	
	figure1->adj_list[1] = (struct adjacency_list_t *) malloc(sizeof(struct adjacency_list_t));
	figure1->adj_list[1]->head = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[1]->head->dest = 3;
	figure1->adj_list[1]->head->next = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[1]->head->next->dest = 5;
	figure1->adj_list[1]->head->next->next = NULL;
	
	figure1->adj_list[2] = (struct adjacency_list_t *) malloc(sizeof(struct adjacency_list_t));
	figure1->adj_list[2]->head = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[2]->head->dest = 2;
	figure1->adj_list[2]->head->next = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[2]->head->next->dest = 4;
	figure1->adj_list[2]->head->next->next = NULL;
	
	figure1->adj_list[3] = (struct adjacency_list_t *) malloc(sizeof(struct adjacency_list_t));
	figure1->adj_list[3]->head = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[3]->head->dest = 3;
	figure1->adj_list[3]->head->next = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[3]->head->next->dest = 5;
	figure1->adj_list[3]->head->next->next = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[3]->head->next->next->dest = 6;
	figure1->adj_list[3]->head->next->next->next = NULL;
	
	figure1->adj_list[4] = (struct adjacency_list_t *) malloc(sizeof(struct adjacency_list_t));
	figure1->adj_list[4]->head = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[4]->head->dest = 1;
	figure1->adj_list[4]->head->next = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[4]->head->next->dest = 2;
	figure1->adj_list[4]->head->next->next = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[4]->head->next->next->dest = 4;
	figure1->adj_list[4]->head->next->next->next = NULL;
	
	figure1->adj_list[5] = (struct adjacency_list_t *) malloc(sizeof(struct adjacency_list_t));
	figure1->adj_list[5]->head = (struct adjacency_list_node_t *) malloc(sizeof(struct adjacency_list_node_t));
	figure1->adj_list[5]->head->dest = 4;
	figure1->adj_list[5]->head->next = NULL;
	
	for (int i = 0; i < figure1->V; i++) {
		printf("Adjacent to %d: ", i + 1);
		for (struct adjacency_list_node_t *tmp = figure1->adj_list[i]->head; tmp != NULL; tmp = tmp->next) {
			printf("%d ", tmp->dest);
		}
		printf("\n");
	}

	return 0;
}