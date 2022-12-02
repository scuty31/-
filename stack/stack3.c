#include <stdio.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}Stacktype;

void init_stack(Stacktype* s) {
	s->top = -1;
}

int is_empty(Stacktype* s) {
	return (s->top == -1);
}

int is_full(Stacktype* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(Stacktype* s, element item) {
	if (is_full) {
		fprintf(stderr, "Stack is full");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

element pop(Stacktype*s) {
	if (is_empty) {
		fprintf(stderr, "Stack is empty");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int main(void) {
	Stacktype s;
	init_stack(&s);
	char arr[100];
	
	printf("ют╥б : ");
	scanf("%s", &arr);

	char ch, cho;
	int i, n = strlen(arr);
	
	for (i = 0; i < n; i++) {
		ch = arr[i];
		switch (ch) {
		case '(':  case '{':  case '[':
			push(&s, ch);
			break;
		case ')': case '}': case ']':
			cho = pop(&s);
			if (cho == '(' && ch == ')') {

			}
		}
	}

	for ()

	return 0;
}