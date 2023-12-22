// main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <windows.h> // win32 api 사용 (윈도우 운영채제에서만 사용 가능)
#include <conio.h> // 시커먼 콘솔창 인풋&아웃풋
// 카카오톡 채팅 들어가기전 나오는 화면: splash (인트로 화면)
// #define NOCURSOR      0
// #define SOLID_CURSOR  1
// #define NORMAL_CURSOR 2 

typedef enum {
	NOCURSOR,      // 커서 없앰 (자동으로 0을 부여)
	SOLID_CURSOR,  // solid 형태 (커서가 깜빡깜빡 거림) (1을 부여)
	NORMAL_CURSOR  // 일반 형태  (커서가 깜빡거리지 않고 나타남) (2를 부여)
} CURSOR_TYPE;

typedef enum {
	BLACK, // 0
	BLUE,  // 1
	GREEN, // 2
	CYAN,  // 3
	RED,
	PRUPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_GRAY  // 15
} FONT_COLOR;

typedef struct _ADDR {
	int id;
	char name[20];
	char tel[20];
	char addr[30];
	char email[50];
} ADDR;

const int id[] = { 111, 222, 333, 444, 555 };
const char* name[] = { "홍길동", "전우치", "강감찬", "유관순", "이순신" };
const char* tel[] = { "010-1234-1234", "010-1234-1111", "010-1234-2222",
	"010-1234-3333", "010-1234-4444" };
const char* addr[] = { "대구 동구 신암4동", "서울 동구 신암4동" ,
	"광주 동구 신암4동", 	"대전 동구 신암4동", "부산 동구 신암4동" };
const char* email[] = { "hong@naver.com", "joen@kakao.com",
	"kang@gmail.com", "yu@msn.com", "lee@daum.net" };

int main_menu();
void title();
void gotoxy(int x, int x);

int main()
{
	char file[] = "address.bin";
	srand(time(NULL));
	title();
	_getch(); // 문자 하나 입력받기

	while (1) {
		switch (main_menu()) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printf("프로그램 종료!\n");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!!\n");
		}
	}
	
}

int main_menu()
{
	printf("=============================\n");
	printf("주소록 관리 프로그램 v1.0\n");
	printf("=============================\n");
	printf("1.주소록 자동 생성\n");
	printf("2.주소록 직접 입력\n");
	printf("3.주소록 전체 삭제\n");
	printf("4.주소록 보기\n");
	printf("5.종료\n");
	printf("=============================\n");
	printf("메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void title() // 인트로 화면 (1~3초 사이 연출하는 것이 좋음)
{
	int x = 5; // 사각형 박스 그릴거임
	int y = 3;
	gotoxy(x, y + 0); printf(" __________________________________");
	gotoxy(x, y + 1); printf("|                                  |");
	gotoxy(x, y + 2); printf("|                                  |");
	gotoxy(x, y + 3); printf("|                                  |");
	gotoxy(x, y + 4); printf("|                                  |");
	gotoxy(x, y + 5); printf("|__________________________________|");
	    
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle()
}

/*
// main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <windows.h>// win32 api 사용 (윈도우 환경에서만 사용 가능)
#include <conio.h>
// #define NOCURSOR			0
// #define SOLID_CURSOR		1
// #define NORMAL_CURSOR	2

#define RAND_SIZE	10

typedef enum {
	NOCURSOR,		// 커서 없앰		0
	SOLID_CURSOR,	// solid 형태	1
	NORMAL_CURSOR	// 일반 형태		2
} CURSOR_TYPE;

typedef enum {
	BLACK,	// 0
	BLUE,	// 1
	GREEN,	// 2
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_GRAY	// 15
} FONT_COLOR;

typedef struct _ADDR {
	int id;
	char name[20];
	char tel[20];
	char addr[30];
	char email[50];
} ADDR;

const int id[] = { 111, 222, 333, 444, 555 };
const char* name[] = { "홍길동", "전우치", "강감찬", "유관순", "이순신" };
const char* tel[] = { "010-1234-1234", "010-1234-1111", "010-1234-2222",
	"010-1234-3333", "010-1234-4444" };
const char* addr[] = { "대구 동구 신암4동", "서울 동구 신암4동" ,
	"광주 동구 신암4동", 	"대전 동구 신암4동", "부산 동구 신암4동" };
const char* email[] = { "hong@naver.com", "joen@kakao.com",
	"kang@gmail.com", "yu@msn.com", "lee@daum.net" };

// 함수 정의 프로토타입
int main_menu();
void title();
void gotoxy(int x, int y);
void set_cursor_type(CURSOR_TYPE type);
void font_color(FONT_COLOR color);
void file_write_rand(ADDR ad[], char filename[], int len);
void file_write(ADDR ad, char filename[]);
void file_read(char filename[]);
void file_del_all(char filename[]);
void file_search(char filename[], char name[]);

int main()
{
	char file[] = "address.bin";
	srand(time(NULL));
	set_cursor_type(NOCURSOR);
	font_color(LIGHT_GREEN);
	title();
	_getch();

	system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	while (1) {
		switch (main_menu()) {
		case 1:
		{
			ADDR ad[RAND_SIZE] = { 0 };
			int len = sizeof(ad) / sizeof(ADDR);
			for (int i = 0; i < len; i++) {
				ad[i].id = id[rand() % 5];
				strcpy(ad[i].name, name[rand() % 5]);
				strcpy(ad[i].addr, addr[rand() % 5]);
				strcpy(ad[i].tel, tel[rand() % 5]);
				strcpy(ad[i].email, email[rand() % 5]);
			}
			file_write_rand(ad, file, len);
			printf("랜덤 데이터를 생성중입니다......\n");
			Sleep(2000); // sec - ms - us - ns
			system("pause");
			break;
		}
		case 2:
		{
			ADDR ad = { 0 };
			printf("ID:");
			scanf("%d", &ad.id);

			printf("이름:");
			scanf("%s", ad.name);

			printf("전화:");
			scanf("%s", ad.tel);

			printf("주소:");
			getchar();
			gets(ad.addr);

			printf("Email:");
			scanf("%s", ad.email);
			file_write(ad, file);
			printf("데이터가 입력중입니다......\n");
			Sleep(1000);
			system("pause");
			break;
		}
		case 3:
			file_del_all(file);
			printf("전체 데이터를 삭제중입니다......\n");
			Sleep(1000);
			system("pause");
			break;
		case 4:
			file_read(file);
			system("pause");
			break;
		case 5:
		{
			char name[20] = { 0 };
			printf("검색할 이름을 입력하세요:");
			scanf("%s", name);
			file_search(file, name);
			system("pause");
			break;
		}
		case 6:
			// 삭제
			break;
		case 7:
			// 수정
			break;
		case 8:
			printf("프로그램 종료!\n");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!!\n");
		}
		system("cls");
	}

}

int main_menu()
{
	printf("=============================\n");
	printf("주소록 관리 프로그램 v1.0\n");
	printf("=============================\n");
	printf("1.주소록 자동 생성\n");
	printf("2.주소록 직접 입력\n");
	printf("3.주소록 전체 삭제\n");
	printf("4.주소록 보기\n");
	printf("5.주소록 검색\n");
	printf("6.주소록 삭제\n");
	printf("7.주소록 수정\n");
	printf("8.종료\n");
	printf("=============================\n");
	printf("메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void title()
{
	int x = 5;
	int y = 3;
	gotoxy(x, y + 0); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y + 1); printf("■							     ■");
	gotoxy(x, y + 2); printf("■							     ■");
	gotoxy(x, y + 3); printf("■							     ■");
	gotoxy(x, y + 4); printf("■							     ■");
	gotoxy(x, y + 5); printf("■							     ■");
	gotoxy(x, y + 6); printf("■							     ■");
	gotoxy(x, y + 7); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x + 12, y + 2); printf("주소록 관리 프로그램 v1.5");
	gotoxy(x + 33, y + 4); printf("개발날짜	: 2023.09.01");
	gotoxy(x + 33, y + 5); printf("개발자	: 박상신");
	gotoxy(x, y + 12); printf("메인화면 이동은 아무키나 누르세요!!!");
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// 윈도우 콘솔에서 커서 위치 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void set_cursor_type(CURSOR_TYPE type)
{
	CONSOLE_CURSOR_INFO info = { 0 };
	switch (type) {
	case NOCURSOR:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case SOLID_CURSOR:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	}
	// 커서 타입을 설정
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void font_color(FONT_COLOR color)
{
	// 폰트에 색생 적용
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void file_write_rand(ADDR ad[], char filename[], int len)
{
	FILE* fp = fopen(filename, "ab");
	if (fp == NULL) {
		printf("파일 오픈 실패!\n");
		return;
	}

	for (int i = 0; i < len; i++) {
		fwrite(&ad[i], sizeof(ADDR), 1, fp);
	}
	fclose(fp);
}

void file_write(ADDR ad, char filename[])
{
	FILE* fp = fopen(filename, "ab");
	if (fp == NULL) {
		printf("파일 오픈 실패!\n");
		return;
	}
	fwrite(&ad, sizeof(ADDR), 1, fp);
	fclose(fp);
}

void file_read(char filename[])
{
	// 데이터가 없으면 "데이터가 존재하지 않습니다" 에러 메시지를 출력!
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("파일 읽기 오류!\n");
		exit(0);
	}
	ADDR ad = { 0 };
	int count = 1;
	int check = 0;
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		printf("번호:%d\n", count++);
		printf("ID:%d\n", ad.id);
		printf("이름:%s\n", ad.name);
		printf("전화:%s\n", ad.tel);
		printf("주소:%s\n", ad.addr);
		printf("이메일:%s\n", ad.email);
		printf("==========================\n");
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf("데이터가 존재하지 않습니다.\n");
	}
}

void file_del_all(char filename[])
{
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("파일 읽기 오류!\n");
		exit(0);
	}
	fclose(fp);
}

void file_search(char filename[], char name[])
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("파일 검색 오류!\n");
		exit(0);
	}
	ADDR ad = { 0 };
	int count = 1;
	int check = 0;
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, name) == 0) {
			printf("번호:%d\n", count++);
			printf("ID:%d\n", ad.id);
			printf("이름:%s\n", ad.name);
			printf("전화:%s\n", ad.tel);
			printf("주소:%s\n", ad.addr);
			printf("이메일:%s\n", ad.email);
			printf("==========================\n");
			check = 1;
		}
	}
	fclose(fp);
	if (check == 0) {
		printf("검색할 데이터가 존재하지 않습니다.\n");
	}
}

void file_del()
{
	// 1. 삭제할 이름 입력
	// 2. 파일에서 읽은 이름과 삭제할 이름이 같은지 비교 (검색 함수 비교문과 동일)
	// 3. 이름이 같으면 삭제할 대상이므로 빼고 이름이 같으면 배열에 정보를 복사. 배열 크기 [100]
	// 4. 파일 오픈, 쓰기(읽기), 닫기
}
*/