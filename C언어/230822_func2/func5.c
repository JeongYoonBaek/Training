#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void test_func();
// !!!! 주의) 전역변수는 무조건 함수 밖에 선언해야함. !!!!
// 1. 파일 내의 모든 함수의 값을 전달 가능함
// 2. 하지만 함수간의 값 전달은 매개변수 사용을 우선

int b = 100; // 전역변수 b

int main()
{   // 중괄호(함수) 안에 있는 변수는 지역변수
	int a = 10; // main() 지역변수 a
	printf("main()=>a:%d b:%d\n", a, b); // 가까운 변수를 찾음
	b = 200;  // 특정 다른 함수에 값을 바꾸면 영향을 미침
// 우선적으로 매개변수를 써야함.왜냐,디버깅이 편함.전역변수는 불편.
	test_func();
}

void test_func()
{
	int a = 20; // test_func() 지역변수 a
	printf("test_func()=>a:%d b:%d\n", a, b);
}