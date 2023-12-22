#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // 입,출력
#include <stdlib.h> // 스탠다드 라이브러리 srand()

// 전역변수 : 함수 밖에서 선언되는 변수
// 지역변수 : 함수 안에서만 선언되는 변수
const char CHECK_FULL = 'f'; // 전역변수 - 모든 함수에 값을 전달가능!
// #define CHECK_FULL 'f'로도 선언 가능
const char CHECK_EVEN = 'e'; // const - 상수 변수를 선언할 때 사용
const char CHECK_ODD = 'o';  // 상수 - 값을 변경할 수 없는 변수

int main_menu();
void gugu(char n);

int main()
{
	
	while (1) { // 무한 반복
		int menu = main_menu(1); //값만 넣으면 돼서 변수생성 가능
		switch (menu) {
		case 1: // 짝수
			gugu(CHECK_EVEN); // 매개변수를 사용 (짝수단 기능 추가)
			break;
		case 2: // 홀수
			gugu(CHECK_ODD); // 함수에 포함된 다른 기능을 포함하려면 매개변수 사용
			break;
		case 3: // 전체
			gugu(CHECK_FULL);
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
	scanf("%d", &menu); // 메뉴를 입력받음
	return menu; // 값을 받고 스위치문으로 돌아가서 출력
}

void gugu(char n)
{
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			if (j % 2 == 0 && n == CHECK_EVEN) {// (j % 2 == 0)짝수 단만 출력
				printf("%d * %d = %d\t", j, i, j * i);
			}
			else if (j % 2 != 0 && n == CHECK_ODD) { // 조건을 거는 제어문
				printf("%d * %d = %d\t", j, i, j * i);
			}
			else if (n == CHECK_FULL) { // 전체
				printf("%d * %d = %d\t", j, i, j * i);
			} // hard coding : 개발코드 짤 땐 사용 x
		}
		printf("\n");
	}
}
