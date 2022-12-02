#include <stdio.h>
#define Max_Stack_Size 100

typedef char element;

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
		return;
	}
	else {
		return s->data[(s->top)--];
	}
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러");
	}
	else {
		return s->data[s->top];
	}
}

int prec(char op) {
	switch (op){
	case'(': case')': return 0;
	case'+': case'-': return 1;
	case'*': case'/': return 2;
		}
	return -1;
}

void infix_to_postfix(char arr[], char exp[]) {
	int j = 0;
	char ch, top_op;
	int len = strlen(arr);
	StackType* s;

	init_stack(&s);

	for (int i = 0; i < len ; i++) {
		ch = arr[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				exp[j++] = pop(&s);
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') {
				exp[j++] = top_op;
				top_op = pop(&s);
			}
			break;
		default:
			exp[j++] = ch;
			break;
		}
	}

	while (!is_empty(&s)){
		exp[j++] = pop(&s);
	}

}

int eval(char arr[]) {
	int op1, op2, value;
	char ch;
	StackType* s;

	init_stack(&s);

	for (int i = 0; arr[i] != '\0'; i++) {
		ch = arr[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+':
				push(&s, op1 + op2);
				break;
			case '-':
				push(&s, op1 - op2);
				break;
			case '*':
				push(&s, op1 * op2);
				break;
			case '/':
				push(&s, op1 / op2);
				break;
			}
		}
	}
	return pop(&s);
}

int main(void) {
	StackType s;

	init_stack(&s);
	
	char arr[100] = {'\0'};
	char exp[100] = { '\0' };
	int result;

	printf("수식입력 : ");
	scanf("%s", arr);

	printf("중위표시수식 %s\n", arr);
	printf("후위표시수식 ");
	infix_to_postfix(arr, exp);

	printf("%s", exp);

	result = eval(exp);
	printf("\n계산 결과 : %d\n", result);

	return 0;

}