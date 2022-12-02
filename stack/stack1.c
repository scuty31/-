#include <stdio.h>

#define Max_Stack_Size 100
typedef int element;

element stack[Max_Stack_Size];

int top = -1;

int is_emty() {
	return (top == -1);
}

int is_full() {
	return (top == Max_Stack_Size - 1);
}

void push(element data) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러");
		return;
	}
	else {
		stack[++top] = data;
	}
}

element pop() {
	if (is_emty()) {
		fprintf(stderr, "스택 공백 에러");
		return;
	}
	else {
		return stack[top--];
	}
}

int main(void) {
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}