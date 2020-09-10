#include <stdio.h>

void add_node(int, int *);
void in_order_print(int *, int, int);
void pre_order_print(int *, int, int);
void post_order_print(int *, int, int);
int is_binary_search_tree(int *, int);

int main(void) {
	int count;
	printf("How many values would you like to add to the tree? ");
	scanf("%d", &count);
	int n = 1 << count;
	
	int tree[n];
	for (int i = 0; i < n; i++) {
		tree[i] = -1;
	}
	printf("What elements do you wish to add to the tree? \n");
	for (int i = 0; i < count; i++) {
		int tmp;
		scanf("%d", &tmp);
		add_node(tmp, tree);
	}
	
	printf("\nIn order: ");
	in_order_print(tree, n, 0);
	printf("\nPre order: ");
	pre_order_print(tree, n, 0);
	printf("\nPost order: ");
	post_order_print(tree, n, 0);
	
	printf("\n\nThis tree is%s a binary search tree.\n", is_binary_search_tree(tree, n) ? "" : " not");
	int tmp_arr[] = {0, 1, 2, 3, -1, -1, 8, -1};
	printf("The array {0, 1, 2, 3, -1, -1, 8, -1} is%s a binary search tree.\n", is_binary_search_tree(tmp_arr, 8) ? "" : " not");

	return 0;
}

void add_node(int value, int *tree) {
	int i;
	for (i = 0; tree[i] != -1;) {
		if (value < tree[i]) {
			i = 2*i + 1;
		} else if (value > tree[i]) {
			i = 2*i + 2;
		}
	}
	tree[i] = value;
}

void in_order_print(int *tree, int n, int start) {
	if (start >= n || tree[start] == -1) {
		return;
	}
	
	in_order_print(tree, n, start*2 + 1);
	printf("%d ", tree[start]);
	in_order_print(tree, n, start*2 + 2);
}

void pre_order_print(int *tree, int n, int start) {
	if (start >= n || tree[start] == -1) {
		return;
	}
	
	printf("%d ", tree[start]);
	pre_order_print(tree, n, start*2 + 1);
	pre_order_print(tree, n, start*2 + 2);
}

void post_order_print(int *tree, int n, int start) {
	if (start >= n || tree[start] == -1) {
		return;
	}
	
	post_order_print(tree, n, start*2 + 1);
	post_order_print(tree, n, start*2 + 2);
	printf("%d ", tree[start]);
}

int is_binary_search_tree(int *tree, int n) {
	int queue[n];
	int top = -1;
	
	queue[++top] = 0;
	while (top > -1) {
		int index = queue[top--];
		if (2*index + 1 > n || 2*index + 2 > n) {
			continue;
		}
		
		if (tree[2*index + 1] != -1 && tree[index] <= tree[2*index + 1]) {
			return 0;
		}
		
		if (tree[2*index + 2] != -1 && tree[index] >= tree[2*index + 2]) {
			return 0;
		}
	}
	
	return 1;
}