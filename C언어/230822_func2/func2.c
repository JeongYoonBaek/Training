#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void call_by_val(int a, int b);
int main()
{
	// Call by Value (값에 의한 전달)

	int a = 10;
	int b = 20;
	call_by_val(a, b);
	printf("main()=>a:%d, b:%d\n", a, b);
}

void call_by_val(int a, int b) // line11 값 전달 a=10, b=20
{
	// !!!! a와 b의 값을 서로 바꿔치기 !!!!
	int temp = a; // a의 값을 임시변수(temp)에 백업 //지역 변수
	a = b;
	b = temp;
	printf("call_by_val()=>a:%d, b:%d\n", a, b);
} // 출력하고 중괄호 닫으면서 소멸 (지역변수들도 같이 소멸)
