#include<stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct Listtype {
	int size;
	ListNode* head;
	ListNode* tail;
}Listtype;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

Listtype* create() {
	Listtype* plist = (Listtype*)malloc(sizeof(Listtype));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(Listtype* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist-> tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(Listtype* plist1, Listtype* plist2, Listtype* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

void poly_mul(Listtype* plist1, Listtype* plist2, Listtype* plist3, Listtype* plist4) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int mul_co, mul_ex;
	while (b != NULL){
		a = plist1->head;
		while (a!=NULL) {
			mul_co = a->coef * b->coef;
			if (mul_co == 0) continue;
			mul_ex = a->expon + b->coef;
			
			insert_last(plist4, mul_co, mul_ex);
			a = a->link;
		}
		poly_add(plist3, plist4, plist3);
		b = b->link;
	}
}

void poly_print(Listtype* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link)
		printf("%d^%d + ", p->coef, p->expon);
	printf("\n");
}

int main(void) {
	Listtype* list1, * list2, * list3, * list4, list5;

	list1 = create();
	list2 = create();
	list3 = create();	//결과 리스트
	list4 = create();	//중간 계산 리스트
	list5 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	poly_mul(list1, list2, list3, list4);
	poly_print(list3);

	free(list1);
	free(list2);
	free(list3);
	free(list4);

	return 0;
}