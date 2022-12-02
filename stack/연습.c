#include <stdio.h>

typedef int element;

typedef struct {
	element data[10];
	int top;
}stack;

void init_stack(stack *s) {
	s->top = -1;
}

int is_empty(stack *s) {
	if (s->top == -1)
		return 1;
	else
		return 0;
}

int is_full(stack* s) {
	if (s->top == (10 - 1))	return 1;
	else return 0;
}

void push(stack* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택이 차있음");
	}
	s->data[++(s->top)] = item;
}

element pop(stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음");
	}
	return s->data[(s->top)--];
}

element peck(stack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음");
	}
	return s->data[s->top];
}

int main(void) {
	stack s;

	init_stack(&s);

	push(&s, 10);
	push(&s, 20);
	push(&s, 30);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}