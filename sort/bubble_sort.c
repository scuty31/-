#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t) )

void bubble_sort(int list[], int n);	// 버블정렬 함수
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

	bubble_sort(list, n);	//버블정렬 호출

	printf("정렬한 이후의 리스트\n");
	print_list(list, n);

	return 0;
}

void bubble_sort(int list[], int n) {
	int i, j, tmp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {	//앞뒤의 노드를 비교한 후 교체
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
