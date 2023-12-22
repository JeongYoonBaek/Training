#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 스탠다드 라이브러리 srand()
#include <time.h> // time()
// 디버깅하는 습관 꼭 들일것!!!

typedef struct _PERSON {
	char name[20];
	int age;
	char tel[20];
	char addr[50];
} PERSON;

char* name[] = { "홍길동", "전우치", "유관순", "이순신", "강감찬"};
int age[] = { 20, 30, 40, 50, 60 };
char* tel[] = { "010-1234-1111", "010-1234-2222", "010-1234-3333",
	   010,1234 - 4444, "010-1234-5555"};
char* addr[] = { "서울", "부산", "대구", "인천", "광주"};

int main_menu(menu);
void file_wb();
void file_rb();

int main()
{

	//----------------------------
	// 파일 제어 프로그램 v1.0
	//----------------------------
	// 1. 10개의 랜덤한 데이터 파일 입력
	// 2. 파일에서 읽어오기
	// 3. 종료
	//----------------------------
	// 메뉴 선택:

	FILE* fp;
	PERSON myfren1_arr[100] = {0};

	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		strcpy(myfren1_arr[i].name, name[rand() % 5]);
		myfren1_arr[i].age, age[rand() % 5];
		strcpy(myfren1_arr[i].tel, tel[rand() % 5]);
		strcpy(myfren1_arr[i].addr, addr[rand() % 5]);
		fwrite(&myfren1_arr[i], sizeof(PERSON), 1, fp);
	}
	fclose(fp);
	printf("랜덤한 데이터가 파일에 저장되었습니다!\n");

	while (1)
		switch (main_menu()) {
		case 1:
			file_wb();
			break;
		case 2:
			file_rb();
			break;
		case 3:
			printf(" 프로그램 종료!");
			exit(0);
		default:
			printf("잘못된 메뉴 입력!!!");
		}
}

int main_menu()
{
	printf("-------------------------\n");
	printf("파일 제어 프로그램 v1.0\n");
	printf("-------------------------\n");
	printf("1. 10개의 랜덤한 데이터 파일 입력\n");
	printf("2. 파일에서 읽어오기\n");
	printf("3. 종료\n");
	printf("-------------------------\n");
	printf("메뉴 선택:");

	int menu;
	scanf("%d", &menu);
	return menu;
}

void file_wb()
{
	PERSON myfren1;
	PERSON myfren1_arr[10] = { 0 };
	FILE* fp = fopen("file_arr.bin", "wb");
	if (fp == NULL) {
		printf("파일 쓰기 오픈 에러!!\n");
		return -1;
	}

	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		strcpy(myfren1_arr[i].name, name[rand() % 5]);
		myfren1_arr[i].age, age[rand() % 5];
		strcpy(myfren1_arr[i].tel, tel[rand() % 5]);
		strcpy(myfren1_arr[i].addr, addr[rand() % 5]);
		fwrite(&myfren1_arr[i], sizeof(myfren1_arr[i]), 1, fp);

		printf("이름 입력: "); scanf(" %s", myfren1.name);
		printf("나이 입력: "); scanf(" %d", myfren1.age);
		printf("연락처 입력: "); scanf(" %s", myfren1.tel);
		printf("주소 입력: "); scanf(" %s", myfren1.addr);
		printf("파일에 정상적으로 입력되었습니다!\n");
		fclose(fp);
	}
}
void file_rb()
{
	FILE* fp;
	PERSON myfren1 = { 0 }; 
	if (fp == NULL) {
		printf("파일 읽기 오픈 에러!!\n");
		return -1;
		fp = fopen("friend.bin", "rb");
		printf("이름 %s, 나이 %c, 연락처 %s, 주소 %s \n",
			myfren1.name, myfren1.age, myfren1.tel, myfren1.age);
		fread(&myfren1, sizeof(PERSON), 1, fp);
		fclose(fp);
	}
	return -1;
}
	
