#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* list;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->list = head;
	}
	else {
		node->list = head->list;
		head->list = node;
	}

	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		node->list = head;
	}
	else {
		node->list = head->list;
		head->list = node;
		head = node;
	}

	return head;
}

void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	
	p = head->list;
	
	do {
		printf("%d->", p->data);
		p = p->list;
	} while (p != head);
	printf("%d", p->data);
}

int main(void) {
	ListNode* head = NULL;

	//list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}