#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL)error("메모리 할당 에러");
	
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void insert(ListType* plist, ListNode* pre, int coef, int expon){
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = pre->link;
	pre->link = temp;
	
	plist->size++;
	}

void insert_head(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = plist->head;
	plist->head = temp;

	plist->size++;

}

void poly_multi(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;

	int sum;
	int exposum;


	while (a) {
		while (b) {
			sum = a->coef * b->coef;
			exposum = a->expon + b->expon;
			
			if (plist3->head == NULL) {
				insert_last(plist3, sum, exposum);
			}
			else {
				if (plist3->head->expon < exposum) {
					insert_head(plist3, plist3->head, sum, exposum);
				}
				else {
					ListNode* c = plist3->head;
					while (c != plist3->tail) {
						ListNode* next = c->link;
						if (c->expon == exposum) {
							c->coef += sum;
							break;
						}
						else if(next->expon < exposum && c->expon > exposum) {
							insert(plist3, c, sum, exposum);
							break;
						}
						else {
							c = c->link;
							next = next->link;
						}
					}
					if (exposum == plist3->tail->expon) {
						plist3->tail->coef += sum;
					}
					else if (exposum < plist3->tail->expon) {
						insert_last(plist3, sum, exposum);
					}
				}
			}
			
			b = b->link;
		}

		a = a->link;
		b = plist2->head;
	}
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d", p->coef, p->expon);
		if (p->link != NULL) printf(" +");
	}
	printf("\n");
}

int main(void) {
	ListType* list1, * list2, * list3;

	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 2);
	insert_last(list1, 2, 1);
	insert_last(list1, 1, 0);

	insert_last(list2, 2, 1);
	insert_last(list2, 3, 0);

	poly_print(list1);
	poly_print(list2);
	
	poly_multi(list1, list2, list3);
	poly_print(list3);

	free(list1);
	free(list2);
	free(list3);
	return 0;
}