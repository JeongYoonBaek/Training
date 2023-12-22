#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void show_day(int n);

int main()
{
	// main 함수에서 1~7 사이의 숫자를 입력받아서
	// 매개변수로 전달하여 매개변수의 값이 
	// 1이면, 월요일 출력
	// 2이면, 화요일 출력
	// 3=수 4=목 5=금 6=토 7=일 출력하는 함수 작성
	// show_day()

    printf("요일 입력:(1:월요일 2:화요일 3:수요일 4:목요일 5:금요일 6:토요일 7:일요일)=>");
	int day;
	scanf("%d", &day); // 1부터 7까지 입력
	//// 함수 호출할때 반드시 괄호 안에 int와 void 붙이지 말기 ////
	show_day(day); // show_day 함수 호출(실행)
	}

void show_day(int n)
{

	switch (n) {
	case 1:
		printf("월요일"); break;
	case 2:
		printf("화요일"); break;
	case 3:
		printf("수요일"); break;
	case 4:
		printf("목요일"); break;
	case 5:
		printf("금요일"); break;
	case 6:
		printf("토요일"); break;
	case 7:
		printf("일요일"); break;
	default:
		printf("잘못된 정보"); break;
	}
}
