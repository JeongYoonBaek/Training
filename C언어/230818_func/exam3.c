#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void my_sort(int n1, int n2, int n3);

int main()
{
	// 1) 3개의 정수를 main()에서 입력받아서 한꺼번에 매개변수에 전달.
	// 2) 함수에서 3개의 숫자를 크기 순서대로 출력
	// 3) 함수 이름: my_sort()
	// 4) if (n1 > n2 > n3) : 잘못된 문법 
	// if(n1 > n2 && n2> n3)
	// n1이 n2보다 크고 그리고 n2가 n3보다 크다.

	// 5) 출력 결과: 
	// n1이 제일 크고 n2가 두번째 크고 n3가 제일 작음
	// n1 > n2 > n3 << 최종 출력 형태
	// n3가 제일 크고 n1이 두번째 크고 n2가 제일 작음
	// ===> n3 > n1 > n2

	int n1, n2, n3;
	printf("3개의 정수를 입력:\n");
	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &n3);
	my_sort(n1, n2, n3);
}

void my_sort(int n1, int n2, int n3)
{
	// n1 > n2 > n3 n1이 n2보다 크고 그리고 n2가 n3보다 크다.
	// n1 > n3 > n2
	// n2 > n1 > n3
	// n2 > n3 > n1
	// n3 > n1 > n2 
	// n3 > n2 > n1 
	if (n1 > n2 && n2 > n3) {
		printf("%d > %d> %d\n", n1, n2, n3);
	}
	else if (n1 > n3 && n3 > n2) {
		printf("%d > %d > %d\n", n1, n3, n2);
	}
	else if (n2 > n1 && n1 > n3) {
		printf("%d > %d > %d\n", n2, n1, n3);
	}
	else if (n2 > n3 && n3 > n1) {
		printf("%d > %d > %d\n", n2, n3, n1);
	}
	else if (n3 > n1 && n1 > n2) {
		printf("%d > %d > %d\n", n3, n1, n2);
	}
	else if (n3 > n2 && n2 > n1) {
		printf("%d > %d > %d\n", n3, n2, n1);
	}
	else  {
		printf("잘못된 정보\n");
	}
}







