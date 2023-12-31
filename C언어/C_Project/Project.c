#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct time { // 구조체를 이용하여 시간 변수 저장한다. 
	int hour, min;
};

int main_menu();
int main() {

	//입출차시간 구하는 과정 함수로
	struct time ent; // 입차 시간 구조체
	struct time exit; // 출차 시간 구조체
	int hour, min; // 시간, 분 변수 

	srand(time(NULL));

	while (1) {

		int menu = main_menu();	// Y/N 호출 
		system("cls");
		if (menu == 1) {
			int ent_hour[2] = { 0 };
			int ent_min[2] = { 0 };
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < 1; j++) {
					ent_hour[i] = (rand() % 15) + 06; // 시간 단위 랜덤 난수 입력 받기 (06시~21시까지 이용가능)
					ent_min[j] = (rand() % 59); // 분 단위 랜덤 난수 입력 받기 
					printf("입차 시간: %d : %d \t", ent_hour[i], ent_min[j]);
					printf("\n");
				}
			}
			//수정필요. hour범위 6~21 , min범위:00~59 
			//잘못 입력하면 다시 입력받기?
			printf("출차 시간을 입력하세요 =>  ");
			scanf("%d : %d", &exit.hour, &exit.min);
			hour = exit.hour - (ent_hour[0]);
			min = exit.min - (ent_min[0]);
			if (exit.min < ent_min[0]) {
				hour = (exit.hour - (ent_hour[0])) - 1;
				min = ((exit.min - ent_min[0])) + 60;
			}
			printf("이용 시간 : %d시간 : %d분 \n", hour, min);

			break; //-수정필요. 다음으로 진행되야 하는데 break 걸면서 시스템 종료됨
		}
		else if (menu == 2) {
			//수정필요. 2번을 누르면 다시 메인메뉴로 돌아가야 함
		}
		else
		{
			//수정필요. 다른거 누른거 고려..?
		}
		system("cls");

	}
}

int main_menu() {
	int num;

	//수정필요
	//차량번호 네자리 임의로 적어놓음
	printf("차량번호 네자리를 입력하세요\n");
	printf("차량번호: ");
	scanf("%d", &num);
	printf("\n");
	printf("=================================\n");
	printf("        차량 번호 선택\n");
	printf("=================================\n");
	printf("\n");
	printf("고객님의 차량번호가 맞습니까? \n");
	printf("\n");
	printf("%d\n", num);
	printf("\n");
	printf("1. 예			2. 아니오\n");
	printf("\n");
	printf("\n");

	int menu;
	scanf("%d", &menu);
	printf("\n");
	return menu;
}