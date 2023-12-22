#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void show_num(int num);
int main()
{
	// 1~5까지 연속적으로 매개변수 전달하여 
	// 출력하는 함수 작성
	// 함수명 show_num()
	show_num(1); // show_num 함수 호출(실행)
	show_num(2); // function 
	show_num(3);
	show_num(4);
	show_num(5);

	int num = 0;
	for (int i = 1; i <= 5; i++) { //!!! 앞에처럼 반복문 사용해서
		show_num(i);  // 1~10000까지 연속으로 출력 가능!!!
	}

void show_num(int num); // int n = 10; (X)
	{
		printf("출력하는 함수: %d \n", num);
	}
}