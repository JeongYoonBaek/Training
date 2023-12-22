#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 
#include <stdlib.h>
#include <time.h> // time()

// 프로젝트 개발 순서 : 주제회의 => 요구사항 => 설계 => 구현 => 테스트 => 유지보수
// 요구사항 : B2B(기업과 기업) B2C(기업과 고객) B2G(기업과 정부) 
// 설계 : UI(이미지 쓰면 깔끔함), DB, 프로그램(앱)
// 구현 : 알고리즘이 정말 중요함
// 유지보수 : 오류 수정 및 업그레이드 
// 회사관련 프로그램 : ERP) 회계관리, 사원관리, 영업관리, 업무에 관련된 모든 것들을 관리하는 프로그램
// 플랫폼 서비스 : 카카오 택시, 배민, 당근마켓 

// C언어 구조적 프로그래밍 - 데이터 우선시
// 객체지향 프로그래밍 - 객체를 우선시

struct member // 고객 정보 구조체
{
	char name[20];
	char tel[20];
	char addr[20];
	char job[20];
	char birth[20];
};

struct car // 차량 정보 구조체
{
	char car_model[20];
	int price;
	int year;
	char color[20];
	char store[20];
};

int main_menu();
void ins_customer(struct customer cu[]);
void show_customer(struct customer cu[]);

int main()
{
	//----------------------------------
	// 고객차량 관리 프로그램 v1.5
	//----------------------------------
	// 1. 고객및 구매차량 입력 // 직접 입력 x 1번 선택하면 값을 랜덤하게 뽑아오는 것
	// 2. 고객및 구매차량 보기 : 랜덤으로 저장된 100명 정보 들고오기 printf 출력 
	// 3. 종료 exit(0);
	//----------------------------------
	// 메뉴 선택: 
	main_menu();
	ins_customer;
	show_customer;
}

int_main_menu(cu)
{   
		srand(time(NULL));
		while (1) {
			switch (main_menu(cu)) {
			case 1:
				ins_customer(cu);
				break;
			case 2:
				show_customer(cu);
				break;
			case 3:
				printf("프로그램 종료 \n");
				exit(0);
			Default: 
				printf("잘못된 메뉴 선택! \n");
			}
		}
}

void ins_customer(struct customer cu[])
{
	printf("----------------------------------\n");
	printf("고객 차량 관리 프로그램 v1.5\n");
	printf("----------------------------------\n");
	printf("1.고객및 구매차량 입력\n");
	printf("2.고객및 구매차량 보기\n");
	printf("3.종료\n");
	printf("----------------------------------\n");
	int menu;
	printf("메뉴 선택:");
	scanf("%d", &menu);
	printf("----------------------------------\n");
	return menu;
};

void show_customer(menu)
{
	struct member cu[100] = { 0 };
	char* name[5] = { "홍길동", "전우치", "김유신", "이순신", "유관순" };
	char* tel[5] = { "010 - 1234 - 1111" , "010 - 1234 - 2222", "010 - 1234 - 3333",
		"010 - 1234 - 4444", "010 - 1234 - 5555" };
	char* addr[5] = { "서울", "부산", "인천", "광주", "대구" };
	char* job[5] = { "회사원", "공무원", "교사", "주부", "자영업자" };
	char* birth[5] = { "1월 6일", "3월 6일", "6월 6일", "9월 6일", "12월 6일" };

	struct car cu2[100] = { 0 };
	char* car_model[5] = { "아반떼", "E클래스", "레인지로버", "K5", "토레스" };
	int price[5] = { "20000000", "30000000", "40000000", "60000000", "80000000" };
	int year[5] = { "2016", "2018", "2020", "2022", "2024" };
	char* color[5] = { "블랙", "화이트", "블루", "레드와인", "브라운" };
	char* store[5] = { "현대", "벤츠", "기아", "랜드로버", "쌍용" };

	for (int i = 0; i < 100; i++) {
		strcpy(cu[i].name, name[rand() % 5]);
		strcpy(cu[i].tel, tel[rand() % 5]);
		strcpy(cu[i].addr, addr[rand() % 5]);
		strcpy(cu[i].job, job[rand() % 5]);
		strcpy(cu[i].birth, birth[rand() % 5]);

		strcpy(cu2[i].car_model, car_model[rand() % 5]);
		cu2[i].price = price[rand() % 5];
		cu2[i].year = year[rand() % 5];
		strcpy(cu2[i].color, color[rand() % 5]);
		strcpy(cu2[i].store, store[rand() % 5]);
};
