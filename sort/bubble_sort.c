#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

void bubble_sort(int list[], int n);	// �������� �Լ�
void print_list(int list[], int n);	// list ��� �Լ�

int main(void) {
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE];

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		list[i] = rand() % 100; // 0 ~ 99 ���� ����
	}

	printf("�����ϱ� ���� ����Ʈ\n");
	print_list(list, n); // �����ϱ� �� ����Ʈ ���

	bubble_sort(list, n);	//�������� ȣ��

	printf("������ ������ ����Ʈ\n");
	print_list(list, n);

	return 0;
}

void bubble_sort(int list[], int n) {
	int i, j, tmp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {	//�յ��� ��带 ���� �� ��ü
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], tmp);
			}
		}
	}
}

void print_list(int list[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		printf("%d -> ", list[i]);
	}
	printf("%d\n", list[i]);
}
