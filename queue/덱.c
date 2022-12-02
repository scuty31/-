#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

void init_deque(DequeType* q) {
	q->front = 0;
	q->rear = 0;
}

void deque_print(DequeType* q) {
	printf("DEQUE(front = %d, rear = %d) = ", q->front, q->rear);

	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d, ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

int is_full(DequeType* q) {
	if ((q->front % MAX_QUEUE_SIZE) == (q->rear + 1) % MAX_QUEUE_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

int is_empty(DequeType* q) {
	if (q->front % MAX_QUEUE_SIZE == q->rear % MAX_QUEUE_SIZE) {
		return 1;
	}
	else {
		return 0;
	}
}

void add_rear(DequeType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if(is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

void add_front(DequeType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

int delete_front(DequeType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	int item = q->data[q->front];
	return item;
}

element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {
	
	DequeType queue;
	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}