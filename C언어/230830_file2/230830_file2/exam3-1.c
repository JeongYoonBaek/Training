// exam3.c
// 선생님 답안
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()

typedef struct _CAR {
	char model[20];
	char price[20];
	int year;
} CAR;

typedef struct _CUST {
	char name[20];
	char tel[20];
	char addr[50];
	CAR car;
} CUST;

const char* name[] = { "홍길동", "전우치", "강감찬", "유관순", "이순신" };
const char* tel[] = { "010-1234-1234", "010-1234-1111", "010-1234-2222",
	"010-1234-3333", "010-1234-4444" };
const char* addr[] = { "대구 동구 신암4동", "서울 동구 신암4동" ,
	"광주 동구 신암4동", 	"대전 동구 신암4동", "부산 동구 신암4동" };
const char* model[] = { "그랜저", "제네시스", "K7", "K9", "소나타" };
const char* price[] = { "4천만원", "5천만원", "6천만원", "7천만원", "8천만원" };
const int year[] = { 2020, 2021, 2022, 2023, 2024 };

int main_menu();
void write_cust_dir(char fileName[]); // 매개변수 사용해서 함수 호출해보기 
void write_cust_rand(char fileName[]);
void read_cust(char fileName[]);
void del_all_cust(char fileName[]);

int main()
{
	// 주의: 파일에 저장할때 기존 데이터가 계속 존재해야됨!!!
	char fileName[] = "customer.bin";
	// 파일의 이름을 매개변수로 전달
	while (1) {
		switch (main_menu()) {
		case 1:
			write_cust_dir(fileName);
			break;
		case 2:
			write_cust_rand(fileName);
			break;
		case 3:
			read_cust(fileName);
			break;
		case 4:
			del_all_cust(fileName);
			break;
		case 5:
			printf("프로그램 종료\n");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!!\n");
		}
	}
}

int main_menu()
{
	printf("=============================\n");
	printf("고객 차량 관리 프로그램 v2.0\n");
	printf("=============================\n");
	printf("1.고객 정보 직접 입력\n");
	printf("2.고객 정보 랜덤 입력\n");
	printf("3.고객 정보 보기\n");
	printf("4.고객 정보 전체 삭제\n");
	printf("5.종료\n");
	printf("=============================\n");
	printf("메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

// 파일에 고객정보 직접 입력
void write_cust_dir(char fileName[])
{
	CUST cust = { 0 };
	printf("고객명:");
	scanf("%s", cust.name);
	printf("전화:");
	scanf("%s", cust.tel);
	printf("주소:");
	getchar();
	gets(cust.addr); // 공백을 입력받기위해 사용			
	printf("차량모델:");
	scanf("%s", cust.car.model);
	printf("가격:");
	scanf("%s", cust.car.price);
	printf("연식:");
	scanf("%d", &cust.car.year);

	FILE* fp = fopen(fileName, "ab");
	if (fp == NULL) {
		printf("파일 쓰기(D) 오픈 실패!!\n");
		return -1;
	}
	fwrite(&cust, sizeof(cust), 1, fp);
	fclose(fp);
	printf("고객정보가 파일에 저장되었습니다!\n");
}

// 파일에 고객정보 랜덤 입력
void write_cust_rand(char fileName[])
{
	CUST cust_arr[5] = { 0 };
	FILE* fp = fopen(fileName, "ab");
	if (fp == NULL) {
		printf("파일 쓰기(R) 오픈 실패!!\n");
		return -1;
	}
	for (int i = 0; i < 5; i++) {
		strcpy(cust_arr[i].name, name[rand() % 5]);
		strcpy(cust_arr[i].tel, tel[rand() % 5]);
		strcpy(cust_arr[i].addr, addr[rand() % 5]);

		strcpy(cust_arr[i].car.model, model[rand() % 5]);
		strcpy(cust_arr[i].car.price, price[rand() % 5]);
		cust_arr[i].car.year = year[rand() % 5];
		fwrite(&cust_arr[i], sizeof(cust_arr[i]), 1, fp);
	}
	fclose(fp);
	printf("랜덤한 데이터가 파일에 저장되었습니다!\n");
}

// 파일에 고객정보 보기
void read_cust(char fileName[])
{
	CUST temp = { 0 };
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf("파일 읽기 오픈 실패!!\n");
		return -1;
	}
	int cnt = 1;
	while (fread(&temp, sizeof(temp), 1, fp) == 1) {
		printf("번호:%d 고객:%s 전화:%d 주소:%s\n", cnt++,
			temp.name, temp.tel, temp.addr);
		printf("모델:%s 가격:%s 연식:%d\n",
			temp.car.model, temp.car.price, temp.car.year);
		printf("=================================\n");
	}
	fclose(fp);
}

// 고객정보 전체 삭제
void del_all_cust(char fileName[])
{
	FILE* fp = fopen(fileName, "wb");
	printf("파일 전체 삭제!\n");
	fclose(fp);
}