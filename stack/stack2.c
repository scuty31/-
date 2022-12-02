#include <stdio.h>

#define Max_Stack_Size 100
typedef int element;

typedef struct {
	element data[Max_Stack_Size];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == Max_Stack_Size - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러");
		return;
	}
	else {

		s->data[++(s->top)] = item;
	}
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int main(void) {
	StackType s;

	init_stack(&s);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;

}