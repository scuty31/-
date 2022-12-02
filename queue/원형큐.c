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
	return;
}

void init_queue(DequeType* q) {
	q->front = 0;
	q->rear = 0;
}

void queue_print(DequeType* q) {
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
	if ((q->front % MAX_QUEUE_SIZE) == (q->rear+1) % MAX_QUEUE_SIZE) {
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

void enqueue(DequeType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

int dequeue(DequeType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	int item = q->data[q->front];
	return item;
}

int main(void) {
	int item = 0;
	int choise = 0;
	int loop = 1;
	DequeType q;

	init_queue(&q);

	while (loop == 1) {
		
		printf("1. 큐에 데이터 저장\n");
		printf("2. 큐의 데이터 삭제\n");
		printf("3. 현재 큐 출력\n");
		printf("4. 종료\n");
		scanf("%d", &choise);
		printf("\n");

		switch (choise) {
		case 1:
			printf("큐에 집어넣을 수 : ");
			scanf("%d", &item);
			enqueue(&q, item);
			printf("현재 큐 : ");
			queue_print(&q);
			printf("\n");
			break;

		case 2:
			dequeue(&q);
			printf("현재 큐 : ");
			queue_print(&q);
			printf("\n");
			break;

		case 3:
			printf("현재 큐 : ");
			queue_print(&q);
			printf("\n");
			break;

		default:
			printf("종료합니다.");
			exit(1);
		}
	}

	return 0;
}