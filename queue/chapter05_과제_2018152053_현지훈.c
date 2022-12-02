#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct songtype {
	int num;
	int time;
}element;


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
			printf("%d (%d) | ", q->data[i].num, q->data[i].time);
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
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->rear];
}

void add_front(DequeType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(DequeType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		return;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	element item = q->data[q->front];
	return item;
}

element get_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void) {

	DequeType queue;
	element e;
	init_deque(&queue);
	int times, select, del;
	

	printf("--������ �߰� �ܰ�--\n");
	printf("���ϴ� �뷡 �ð��� �Է����ּ��� : ");
	scanf("%d", &times);
	while (1) {
		printf("�����ð� : %d��> ����(1) �뷡�θ���(2) �켱����(3) : ", times);
		scanf("%d", &select);

		switch (select) {
		case 1:
			printf("�뷡 ��ȣ : ");
			scanf("%d", &e.num);
			printf("�뷡 �ð� : ");
			scanf("%d", &e.time);
			add_rear(&queue, e);
			deque_print(&queue);
			break;
			
		case 2:
			e = get_front(&queue);
			printf("==== %d�� �뷡 �θ�\n", e.num);
			times = times - e.time;
			delete_front(&queue);
			deque_print(&queue);
			if (times <= 0) {
				printf("�뷡�� �ð��� ����Ǿ����ϴ�.");
				exit(1);
			}
			break;

		case 3:
			printf("�뷡 ��ȣ : ");
			scanf("%d", &e.num);
			printf("�뷡 �ð� : ");
			scanf("%d", &e.time);
			add_front(&queue, e);
			deque_print(&queue);
			break;
		}
	}
	
	return 0;
}