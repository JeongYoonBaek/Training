#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_num(int n1, int n2, char a);
int main()
{
	// 1) 정수 2개와 사칙 연산자(+,-,x,/)를 main()에서 입력받음.
	// 2) 사칙연산자는 문자로 입력받음. (+,-,x,/) // 100이하 숫자입력
	// 3) 3개의 정보를 매개변수로 한꺼번에 전달
	// 4) 계산 결과값을 리턴하여 main()에서 출력하기 (void 사용x)

	// scanf에서 숫자입력 후 문자 입력시에는 " %c" 사용

	int n1, n2 = 0;
	char a;
	printf("첫번째 숫자를 입력하세요:");
	scanf("%d", &n1);
	printf("두번째 숫자를 입력하세요:");
	scanf("%d", &n2);
	printf("사칙연산자를 입력하세요:");
	scanf(" %c", &a);
	int result = my_num(n1, n2, a);
	printf("결과값: %d\n", result);
}

int my_num(int n1, int n2, char a)
{
	int result= 0;
	if (a == '+') {
		return n1 + n2; // a+b 값을 리턴하면서 calc 함수는 종료
	}
	if (a == '-') {
		result = n1 - n2;
	}
	if (a == 'x') {
		result = n1 * n2;
	}
	if (a == '/') {
		result = n1 / n2;
	}
	return result;
}