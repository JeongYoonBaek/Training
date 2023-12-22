#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void change_num(int n);

int main()
{
	// 2개의 변수(a,b)를 선언한다.
	// a와 b의 값을 출력해본다.
	// a와 b의 값을 서로 바꿔 본 뒤 출력해본다. // 포인터 
	// a와 b의 값을 바꿔주는 함수를 만든다.
	// 함수를 통하여 값을 바꾼 뒤 그 결과를 출력한다.

	int a = 100;
	int b = 200;
	
	printf("a= %d \n", a);
	printf("b= %d \n", b);

	int temp = a;
	a = b;
	b = temp;

	printf("a= %d \n", a);
	printf("b= %d \n", b);

		return 0;
}

void change_num(int n)
{


}