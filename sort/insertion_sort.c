#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10


void insertion_sort(int list[], int n);	// 삽입정렬 함수
void print_list(int list[], int n);	// list 출력 함수

int main(void) {
	int i;
	int n = MAX_SIZE;
	int list[MAX_SIZE];

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		list[i] = rand() % 100; // 0 ~ 99 난수 저장
	}

	printf("정렬하기 전의 리스트\n");
	print_list(list, n); // 정렬하기 전 리스트 출력

	insertion_sort(list, n);	//삽입정렬 호출

	printf("정렬한 이후의 리스트\n");
	print_list(list, n);

	return 0;
}

void insertion_sort(int list[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = list[i]; // 노드 선택

		for (j = i-1; j >= 0 && list[j] > key; j--) {	//노드보가 list의 값이 크면
			list[j + 1] = list[j];	//노드의 오른쪽으로 이동
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
