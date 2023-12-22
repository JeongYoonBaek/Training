#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 
#include <stdlib.h>
#include <time.h> // time()
struct car
{
	char car_model[20];
};

struct manager
{
	char name2[20];
};

struct customer
{
	char name[20];
	struct car ca;
	struct manager mg;
};


char* name[5] = { "홍길동", "전우치", "유관순", "이순신", "김유신" };
char* car_model[5] = { "그랜저", "제네시스", "산타페", "소나타", "K9" };
char* name2[5] = {"김길동", "이우치", "박관순", "백순신", "정유신"};

int main_menu();
void ins_customer(struct customer cu[]);
void random_customer(struct customer cu[]);
void show_customer(struct customer cu[]);

int main()
{   
	// 고객이름, 차량모델, 매니저명 (구조체 3개 필요, 변수 1개씩만 필요)
	//------------------------------
	// 고객 차량 관리 프로그램 v1.6
	//------------------------------
	// 1. 고객정보 직접 입력 scanf 입력
	// 2. 고객정보 랜덤 입력 랜덤하게 printf
	// 3. 고객정보 보기 scanf 입력값 보여주기 
	// 4. 종료
	//------------------------------
	// 메뉴선택:

	srand(time(NULL)); // 랜덤함수를 사용하기 위한 필수조건
	struct customer cu[10] = { 0 }; // 구조체 이름인 동시에 (데이터타입)

	while (1) {
		// 밑에와 동일함. int menu = main_menu();
		switch (main_menu()) {
		case 1:
			ins_customer(cu);
			break;
		case 2:
			random_customer(cu);
			break;
		case 3:
			show_customer(cu);
			// for (int i =0; i < 5; i++){
			// cu[i].name 의 값이 ""와 같다면
			// // 즉, 고객정보가 없으면 탈출
			// if (strcmp(cu[i].name, "")== 0) 고객이름 정보가 X { // strcmp : 같은 문자열끼리 비교함 
			// break; }
			break;
		case 4:
			printf("프로그램 종료!\n");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!!!\n");
		}
	}
}

int main_menu()
{
	printf("----------------------------\n");
	printf("고객차량 관리 프로그램 v1.6\n");
	printf("----------------------------\n");
	printf("1. 고객정보 직접 입력\n");
	printf("2. 고객정보 랜덤 입력\n");
	printf("3. 고객정보 보기\n");
	printf("----------------------------\n");
	printf("메뉴 선택 :");
	int menu;
	scanf("%d", &menu);
	return menu; // 함수 값을 리턴 (매개변수)
}

void ins_customer(struct customer cu[])
{      
		printf("고객명 입력:%s\n");
		scanf("%s", cu[0].name);
		printf("차량모델 입력:%s\n");
		scanf("%s", cu[0].ca.car_model);
		printf("매니저명 입력:%s\n");
		scanf("%s", cu[0].mg.name2);
		printf("정상적으로 데이터가 입력되었습니다\n");
		printf("=============================\n");
}

void random_customer(struct customer cu[])
{
	for (int i = 0; i < 10; i++) {
		strcpy(cu[i].name, name[rand() % 5]);
		strcpy(cu[i].ca.car_model, car_model[rand() % 5]);
		strcpy(cu[i].mg.name2, name2[rand() % 5]);
		printf("고객명:%s\n", cu[i].name);
		printf("차량모델:%s\n", cu[i].ca.car_model);
		printf("매니저명:%s\n", cu[i].mg.name2);
	}
	printf("정상적으로 데이터가 입력되었습니다\n");
}

void show_customer(struct customer cu[])
{  
	for(int i = 0; i < 10; i++) {
		printf("고객명:%s\n", cu[i].name);
		printf("차량모델:%s\n", cu[i].ca.car_model);
		printf("매니저명:%s\n", cu[i].mg.name2);
		printf("==============================\n");
	}
}