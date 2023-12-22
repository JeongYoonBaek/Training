#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int n1, int n2); // 프로토타입 선언
int sub(int n1, int n2);

void main()
{
	// 리턴값의 데이터타입 함수명(매개변수, ...)
	int n1 = 200; // 지역변수
	int n2 = 50;
	int a = add(n1, n2);
	printf("리턴받은 add 함수값:%d\n", a);
	int s = sub(n1, n2);
	printf("리턴받은 sub 함수값:%d\n", s);
	printf("리턴받은 sub 함수값2:%d\n", sub(n1, n2));

	// add()함수 호출해서 리턴값을 main에서 출력
    // sub()함수 호출해서 리턴값을 main에서 출력
}

int add(int n1, int n2) // 함수 정의는 빈 껍데기 
                        // -> 호출했을때 값이 채워짐
{
	return n1 + n2;
}

int sub(int n1, int n2)
{
	int res = n1 - n2;
	return res;
}