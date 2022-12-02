#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* Llist;
	struct DlistNode* Rlist;
}DlistNode;

void init(DlistNode* phead) {
	phead->Llist = phead;
	phead->Rlist = phead;
}

void dinsert(DlistNode* before, element data) {
	DlistNode* node = (DlistNode*)malloc(sizeof(DlistNode));
	node->data = data;

	node->Rlist = before->Rlist;
	before->Rlist->Llist = node;
	node->Llist = before;
	before->Rlist = node;
}

void ddelete(DlistNode* head, DlistNode* removed) {
	if (head == NULL) return;
	removed->Rlist->Llist = removed->Llist;
	removed->Llist->Rlist = removed->Rlist;

	free(removed);
}

void print_dlist(DlistNode* phead) {
	DlistNode* p;
	for (p = phead->Rlist; p->Rlist != phead; p = p->Rlist) {
		printf("|%d| <-> ", p->data);
	}
	printf("|%d|", p->data);
	printf("\n");
}

int main(void) {
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		dinsert(head, i*10);
		print_dlist(head);
	}
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->Rlist);
	}
	free(head);
	return 0;
}