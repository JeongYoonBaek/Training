#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 
#include <stdlib.h>
#include <time.h> // time()


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

int main()
{
	// 차량고객관리 프로그램 1.0
	// 고객 정보, 차량 정보 구조체 -> (클래스로 확장)
	// 고객 : 이름, 전화번호, 주소, 직업, 생일 
	// 차량 : 모델명, 가격, 연식, 색상, 영업소
	// 10명의 고객과 차량정보를 배열에서 랜덤하게 추출하여 입력 및 출력 

	struct member st[10] = { 0 }; 
	char* name[5] = { "홍길동", "전우치", "김유신", "이순신", "유관순" };
	char* tel[5] = { "010 - 1234 - 1111" , "010 - 1234 - 2222", "010 - 1234 - 3333",
	    "010 - 1234 - 4444", "010 - 1234 - 5555" };
	char* addr[5] = { "서울", "부산", "인천", "광주", "대구" };
	char* job[5] = { "회사원", "공무원", "교사", "주부", "자영업자" };
	char* birth[5] = { "1월 6일", "3월 6일", "6월 6일", "9월 6일", "12월 6일" };

	struct car st1[10] = { 0 };
	char* car_model[5] = { "아반떼", "E클래스", "레인지로버", "K5", "토레스" };
	int price[5] = { "20000000", "30000000", "40000000", "60000000", "80000000" };
	int year[5] = { "2016", "2018", "2020", "2022", "2024" };
	char* color[5] = { "블랙", "화이트", "블루", "레드와인", "브라운" };
	char* store[5] = { "현대", "벤츠", "기아", "랜드로버", "쌍용" };

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		strcpy(st[i].name, name[rand() % 5]);
		strcpy(st[i].tel, tel[rand() % 5]);
		strcpy(st[i].addr, addr[rand() % 5]);
		strcpy(st[i].job, job[rand() % 5]);
		strcpy(st[i].birth, birth[rand() % 5]);

		strcpy(st1[i].car_model, car_model[rand() % 5]);
		st1[i].price = price[rand() % 5];
		st1[i].year = year[rand() % 5];
		strcpy(st1[i].color, color[rand() % 5]);
		strcpy(st1[i].store, store[rand() % 5]);
	}

	for (int i = 0; i < 10; i++) {
		printf(">>> %d번째 고객 차량 정보 <<<\n", i + 1);
		printf("이름:%s\n", st[i].name);
		printf("번호:%s\n", st[i].tel);
		printf("주소:%s\n", st[i].addr);
		printf("직업:%s\n", st[i].job);
		printf("생일:%s\n", st[i].birth);

		printf("모델명:%s\n", st1[i].car_model);
		printf("가격:%d\n", st1[i].price);
		printf("연식:%d\n", st1[i].year);
		printf("색상:%s\n", st1[i].color);
		printf("영업점:%s\n", st1[i].store);
		printf("==========================\n");
	}
}
