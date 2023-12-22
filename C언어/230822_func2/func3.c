#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void call_by_addr(int a[]);
int main()
{
	// Call by Address (주소값에 의한 전달)
	// 재고 관리 프로그램에 사용
	int arr[2] = { 10, 20 };
	printf("1.main()=>arr[0]:%d, arr[1]:%d\n", arr[0], arr[1]);
	call_by_addr(arr); // 주소값을 밑에 int a[] 함수에 던짐
	printf("2.main()=>arr[0]:%d, arr[1]:%d\n", arr[0], arr[1]);
}

void call_by_addr(int a[]) // a 주소도 시작값임
                           // 2차원 배열은 대괄호 2개
{
	// a와 b의 값을 서로 바꿔치기
	// 주소값 자체가 값이 많아 무거워서 날라가기 힘듦 

	int temp = a[0]; // a의 값을 임시변수에 백업(안하면 값이 뭉개져버림)  // 지역 변수
	a[0] = a[1];  // 함수가 소멸되어도 공간은 소멸 안됨.
	a[1] = temp;  // 그래서 main 값에서 이 값이 그대로 출력이 됨
	printf("call_by_addr()=>arr[0]:%d, arr[1]:%d\n", a[0], a[1]);
}