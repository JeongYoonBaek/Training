#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//int opt;

	//float보다 double의 크기가 2배 더 크다. 
	//double을 쓸때는 %f가 아닌 %lf를 사용.
	/*
	
	double num1, num2;
	double result;

	printf("1.덧셈 2.뺄셈 3.곱하기 4.나눗셈 \n");
	printf("선택하세요");
	scanf("%d", &opt);
	printf("두 개의 실수 입력: ");
	scanf("%lf %lf", &num1, &num2);

	if (opt==1);
		 result = num1 + num2;

	if (opt==2);
		 result = num1 - num2;

	if (opt==3);
		 result = num1 * num2;

	if (opt==4);
		 result = num1 / num2;

	printf("결과: %f \n", result);
}*/

	int num;
	printf("정수 입력: ");
	scanf("%d", &num);
	if (num < 5) {
		printf("입력값은 5보다 작다.\n");
	}
	else if (num > 5) {
		printf("입력 값은 5보다 작지 않다.\n");
	}
	else if (num = 5) {
		printf("입력 값은 5와 같다.\n");
	}
}
