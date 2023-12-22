#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main(void)
{
	int result;
	int num1, num2;
	printf("정수 one: ");
	scanf("%d", &num1); // 뒤에 \n 사용x
	printf("정수 two: ");
	scanf("%d", &num2);
    result = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, result);
	// 최신 비주얼스튜디오에서는 scanf를 사용불가.
	// scanf_s라는 함수로 대체되었음.
	// 하지만 C언어 표준함수는 scanf가 맞음.
}