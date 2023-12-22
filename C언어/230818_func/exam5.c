#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void gugudan(int n);

int main()
{
	// 1. 구구단을 출력하는 숫자를 main에서 입력 받음.
	// 2. 예) 3을 입력받아 매개변수로 전달하면 3단 출력
	// 3. 입력받은 숫자를 매개변수로 전달하여 구구단 출력

	int n;
	printf("숫자 입력:");
	scanf("%d", &n);
	gugudan(n);
}

void gugudan(int n)
{
	for (int n2 = 1; n2 < 10; n2++) {
		printf("%d* %d =%d\n", n, n2, n*n2);
	}
}
