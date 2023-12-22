#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num = 0;
	printf("정수 입력:");
	scanf("%d", &num);
	// if는 반드시 한번만 사용해야 한다!!!
	
	// 1번.입력받은 num 값을 비교
	if (num < 0); {   // num이 0보다 작으면 출력
		printf("입력값은 0보다 작다.\n");
	}

	// 2번.입력받은 num 값을 비교
	if (num > 0); {   // num이 0보다 크면 출력
		printf("입력값은 0보다 크다.\n");
	}

	// 3번.입력받은 num 값을 비교
	if (num == 0) {   // num이 0이면 출력
		printf("입력값은 0이다.\n");
	}

	// 3가지 경우의 수를 적용
	if (num < 0) {
		printf("입력값은 0보다 작다.\n");
	}
	else if (num > 0) {
		printf("입력값은 0보다 크다.\n");
	}
	else {
		printf("입력값은 0이다.\n");
	}
	if (num < 0);
	else if (num > 0) {
		printf("입력값은 0보다 작다.\n");
	}
	else {
		printf("입력값은 0보다 크거나 작다.\n");
	}

	// else if는 여러 개 사용해도 된다.
	// else를 사용하는 경우에는 조건이 없다.(괄호 사용X)

	if (num < 0) {
		printf("입력값은 0보다 작다.\n");
	}
	else if (num > 0) {
		printf("입력값은 0보다 크다.\n");
	}
	else if (num == 0){
		printf("입력값은 0이다.\n");
	}
}