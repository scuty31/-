#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX_SIZE 10


void selection_sort(int list[], int n);	// �������� �Լ�
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

	selection_sort(list, n);	//�������� ȣ��

	printf("������ ������ ����Ʈ\n");
	print_list(list, n);

	return 0;
}

void selection_sort(int list[], int n) {
	int i, j, least, temp;

	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {	//�ּڰ� Ž��
			if (list[j] < list[least])
				least = j;
		}
		SWAP(list[i], list[least], temp);
	}
}

void print_list(int list[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		printf("%d -> ", list[i]);
	}
	printf("%d\n", list[i]);
}
