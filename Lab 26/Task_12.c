#include <stdio.h>
#include <stdlib.h>

int count_outgoing(int size, int [][size], int);
int does_path_exist(int size, int [][size], int, int);

int main(void) {
	int figure1[6][6] = {
		{0, 0, 0, 0, 1, 0},
		{0, 0, 1, 0, 1, 0},
		{0, 1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1, 1},
		{1, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 0}
	};
	
	int figure2[5][5] = {
		{0, 0, 0, 0, 0},
		{1, 0, 0, 1, 0},
		{0, 0, 0, 1, 1},
		{0, 1, 0, 0, 1},
		{0, 0, 0, 0, 0}
	};
	
	int figure3[8][8] = {
		{1, 1, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0},
		{0, 0, 1, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 1, 1, 0}
	};
	
	printf("There are %d edges going from vertex 1 in Figure 1.\n", count_outgoing(6, figure1, 1));
	printf("There are %d edges going from vertex 3 in Figure 2.\n", count_outgoing(5, figure2, 3));
	
	printf("In figure 1, a path does %sexist between nodes 1 and 6.\n", does_path_exist(6, figure1, 1, 6) ? "" : "not ");
	printf("In figure 3, a path does %sexist between nodes 8 and 2.\n", does_path_exist(8, figure3, 8, 2) ? "" : "not ");

	return 0;
}

int count_outgoing(int size, int figure[][size], int vertex) {
	int edges = 0;
	for (int i = 0; i < size; i++) {
		edges += figure[vertex - 1][i];
	}
	return edges;
}

int does_path_exist(int size, int figure[][size], int vertex1, int vertex2) {
	//Array to keep track of what's been visited
	int *visited = calloc(size, sizeof(int));
	
	//Stack for keeping track of nodes to go to
	int *next_nodes = malloc(size * sizeof(int));
	int next_nodes_top = -1;
	
	next_nodes[++next_nodes_top] = vertex1;
	while (next_nodes_top >=0) {
		int current = next_nodes[next_nodes_top--];
		
		if (current == vertex2) {
			return 1;
		}
		
		if (!visited[current - 1]) {
			for (int i = 0; i < size; i++) {
				if (figure[current - 1][i]) {
					next_nodes[++next_nodes_top] = i + 1;
					visited[i + 1] = 1;
				}
			}
		}
	}
	
	return 0;
}