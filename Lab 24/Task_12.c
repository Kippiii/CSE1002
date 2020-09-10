#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *arr;
	int head;
	int tail;
	int counter;
	int n;
} queue_t;

int dequeue(queue_t *);
void enqueue(queue_t *, int);
int is_empty(queue_t *);

int main(void) {
	queue_t *my_queue = (queue_t *) malloc(sizeof(queue_t));
	my_queue->arr = (int *) malloc(sizeof(int) * 10);
	my_queue->head = 0;
	my_queue->tail = 0;
	my_queue->counter = 0;
	my_queue->n = 10;
	
	for (int i = 1; i <= 10; i++) {
		enqueue(my_queue, i);
	}
	
	int stack[10];
	int top = 0;
	printf("Before reversing: ");
	for (int i = 0; i < 10; i++) {
		int value = dequeue(my_queue);
		printf("%d ", value);
		stack[top++] = value;
	}
	printf("\n");
	
	printf("\nAfter reversing: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", stack[--top]);
	}
	printf("\n");
	
	return 0;
}

int dequeue(queue_t *queue) {
	if (is_empty(queue)) {
		return -1;
	}
	int tmp = queue->arr[queue->head];
	queue->head = (queue->head + 1) % queue->n;
	queue->counter--;
	return tmp;
}

void enqueue(queue_t *queue, int value) {
	queue->arr[queue->tail] = value;
	queue->tail = (queue->tail + 1) % queue->n;
	queue->counter++;
}

int is_empty(queue_t *queue) {
	return queue->counter == 0;
}