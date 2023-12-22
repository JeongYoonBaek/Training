#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 입,출력
#include <stdlib.h> // 스탠다드 라이브러리 srand()
#include <time.h> // time()

// console 시커먼 화면 : 리눅스 터미널 환경

int main_menu(int n);
void gugu1(int n);
void gugu2(int n);
void full_gugu(int n);

int main()
{
	// 아래의 메뉴를 출력하는 함수 만들기
	//--------------------------------
	//  구구단을 출력하는 함수 연습v1.0
	//--------------------------------
	// 1. 구구단 짝수단 출력 (2~8)
	// 2. 구구단 홀수단 출력 (3~9)
	// 3. 구구단 전체 출력(2~9)
	// 4. 종료
	//---------------------------------
	// 메뉴 선택:

	while (1) { // 무한 반복
		int menu = main_menu(1); //값만 넣으면 돼서 변수생성 가능
		switch (menu) {
		case 1:
			gugu1(menu); // 짝수단 기능 추가
			break;
		case 2:
			gugu2(menu); // 함수에 포함된 다른 기능을 포함하려면 매개변수 사용
			break;
		case 3:
			full_gugu(menu);
			break;
		case 4:
			printf("프로그램 종료\n");
			exit(0); // 프로그램을 강제로 종료하는 함수
		default:
			printf("잘못된 메뉴입력!!\n");
		}
	}
}

int main_menu(int n)
{
	printf("------------------------------------\n");
	printf("  구구단을 출력하는 함수 연습 v1.0\n");
	printf("------------------------------------\n");
	printf(" 1.구구단 짝수단 출력 (2~8)\n");
	printf(" 2.구구단 홀수단 출력 (3~9)\n");
	printf(" 3.구구단 전체 출력(2~9)\n");
	printf(" 4.종료 \n");
	printf(" ------------------------------------\n");
	printf(" 메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void gugu1(int n)
{
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			if (j % 2 == 0 && n == 1) {// (j % 2 == 0)짝수 단만 출력
				printf("%d * %d= %d\t", j, i, j * i);
			}
			printf("\n");
		}
	}
}
void gugu2(int n)
{
	for (int i = 1; i < 10; i++) {
		for (int j = 3; j < 10; j++) { //(j += 2) 2씩증가 0이 아닌건 짝수
			if (j % 2 != 0 && n == 2)
				printf("%d * %d = %d\t", j, i, j * i);
		}
		printf("\n");
	}
}

void full_gugu(int n) // 전체 구구단 출력 함수
{
	for (int i = 1; i < 10; i++) { // x1 ~ x9
		for (int j = 2; j < 10; j++) { // 2단부터 9단
			 printf("%d * %d= %d\t", j, i, j * i);
		}
		printf("\n");
	}
}
