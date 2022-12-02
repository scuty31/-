#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


void insertion_sort(int list[], int n);	// �������� �Լ�
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

	insertion_sort(list, n);	//�������� ȣ��

	printf("������ ������ ����Ʈ\n");
	print_list(list, n);

	return 0;
}

void insertion_sort(int list[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = list[i]; // ��� ����

		for (j = i-1; j >= 0 && list[j] > key; j--) {	//��庸�� list�� ���� ũ��
			list[j + 1] = list[j];	//����� ���������� �̵�
		}

		list[j + 1] = key;
	}
}

void print_list(int list[], int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		printf("%d -> ", list[i]);
	}
	printf("%d\n", list[i]);
}
