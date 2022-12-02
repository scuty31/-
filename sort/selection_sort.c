#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX_SIZE 10


void selection_sort(int list[], int n);	// 선택정렬 함수
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

	selection_sort(list, n);	//선택정렬 호출

	printf("정렬한 이후의 리스트\n");
	print_list(list, n);

	return 0;
}

void selection_sort(int list[], int n) {
	int i, j, least, temp;

	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {	//최솟값 탐색
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
