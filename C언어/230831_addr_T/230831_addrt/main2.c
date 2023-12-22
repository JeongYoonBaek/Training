// 소스관리 도구: 형상관리 툴(도구) github, Perforce, SVN, NAS (공유 폴더 개념)
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
void file_delete(char filename[], char delname[]);
void file_update(char filename, char delname[]);
void file_update(char filename, char dname[], char sname[]);


int main()
{
	char file[] = "address.bin"; // char* file = "address.bin";
	srand(time(NULL)); // 랜덤함수 사용을 위한 시드 설정
	set_cursor_type(NOCURSOR);
	font_color(LIGHT_BLUE);
	title();
	_getch();

	system("cls");
	font_color(LIGHT_BLUE);
	set_cursor_type(NORMAL_CURSOR);
	while (1) {
		switch (main_menu()) {
		case 1:
		{
			ADDR ad[RAND_SIZE] = { 0 }; // ADDR 구조체지만 데이터타입으로 간주
			int len = sizeof(ad) / sizeof(ADDR); // 배열 크기 (구조체 크기 X 10) = 오리지널 크기 
			for (int i = 0; i < len; i++) {
				ad[i].id = id[rand() % 5];
				strcpy(ad[i].name, name[rand() % 5]);
				strcpy(ad[i].addr, addr[rand() % 5]);
				strcpy(ad[i].tel, tel[rand() % 5]);
				strcpy(ad[i].email, email[rand() % 5]);
			}
			file_write_rand(ad, file, len); // ad, file : 주소에 의한 전달 방식 (len : 값에 의한 전달)
			printf("랜덤 데이터를 생성중입니다......\n");
			Sleep(2000); // sec - ms - us - ns
			system("pause"); // 멈춤 상태에서 입력을 하면 화면이 지워짐 
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
			file_write(ad, file); // ad : 값에 의한 전달(구조체 일반변수), file : 주소에 의한 전달 방식 (배열)
			printf("데이터가 입력중입니다......\n");
			Sleep(1000);
			system("pause");
			break;
		}
		case 3:
		{
			file_del_all(file);
			printf("전체 데이터를 삭제중입니다......\n");
			Sleep(1000);
			system("pause");
			break;
		}
		case 4:
		{
			file_read(file);
			system("pause");
			break;
		}
		case 5:
		{
			char name[20] = { 0 };
			printf("검색할 이름을 입력하세요:"); 
			// 1.검색할 이름을 입력 2.입력받은 검색할 이름과 파일에서 읽어온 이름과 같은지 비교 
			scanf("%s", name);
			file_search(file, name);
			system("pause");
			break;
		}
		case 6:
		{
			char name[20] = { 0 };
			printf("삭제할 이름을 입력하세요:");
			scanf("%s", name);
			file_delete(file, name);
			printf("%s 데이터를 삭제중입니다...\n", name);
			Sleep(1000);
			system("pause");
			break;
		}
		case 7:
		{
			char name[20] = { 0 };
			printf("검색할 이름을 입력하세요:");
			scanf("%s", name);
			printf("검색할 이름을 입력하세요:");
			scanf("%s", name);
			file_update(file, name, name);
			Sleep(1000);
			system("pause");
			break;
		}
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
	gotoxy(x, y + 0); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); // x,y 좌표에 가서 해당 내용을 화면에 뿌리기
	gotoxy(x, y + 1); printf("■							     ■");
	gotoxy(x, y + 2); printf("■							     ■");
	gotoxy(x, y + 3); printf("■							     ■");
	gotoxy(x, y + 4); printf("■							     ■");
	gotoxy(x, y + 5); printf("■							     ■");
	gotoxy(x, y + 6); printf("■							     ■");
	gotoxy(x, y + 7); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x + 12, y + 2); printf("주소록 관리 프로그램 v1.5");
	gotoxy(x + 33, y + 4); printf("개발날짜	: 2023.09.01");
	gotoxy(x + 33, y + 5); printf("개발자	: 백정윤");
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
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info); // 커서 타입 설정 (win32 API)
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
		fwrite(&ad[i], sizeof(ADDR), 1, fp); // fwrite(포인터) ad앞에 주소값 & 붙임. 배열일땐 [i]가 일반변수 역할
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
	fwrite(&ad, sizeof(ADDR), 1, fp); // 주소값이기 때문에 ad앞에 &붙이기
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
	int check = 0; // check 변수를 사용해 while값이 동작을 하면 1로 바뀌는 것을 확인함
	while (fread(&ad, sizeof(ad), 1, fp) == 1) { // 정상적으로 읽으면 1이 리턴이 됨. (값이 채워짐)
		printf("번호:%d\n", count++);
		printf("ID:%d\n", ad.id);
		printf("이름:%s\n", ad.name);
		printf("전화:%s\n", ad.tel);
		printf("주소:%s\n", ad.addr);
		printf("이메일:%s\n", ad.email);
		printf("==========================\n");
		check = 1; // check 변수를 사용해 while값이 동작을 하면 1로 바뀌는 것을 확인함
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
	int check = 0; // check 변수를 사용해 while값이 동작을 하면 1로 바뀌는 것을 확인함
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, name) == 0) { // ★★★ strcmp : 두 개의 문자열을 비교하는 함수 ★★★
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

void file_delete(char filename, char delname[])
{
	// 1. 삭제할 이름 입력받음
	// 2. 파일에서 읽은 이름과 삭제할 이름이 같은지 비교 (검색 함수 비교문과 동일)
	// 3. 이름이 같으면 삭제할 대상이므로 빼고 이름이 같으면 배열에 정보를 복사. 배열 크기 [100]
	// 4. 기존 파일에 w 모드로 열어서 파일에 쓰기 
	// 5. 파일 오픈, 쓰기(읽기), 닫기

	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("파일 검색 오류");
		exit(0);
	}
	ADDR ad = { 0 };
	ADDR del_arr[200] = { 0 };
	int count = 1;
	int check = 0;
	int i = 0;
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, delname) != 0) { // 삭제할 이름이 아니라면(배열에 복사할 내용)
			del_arr[i].id = ad.id; // 복사되는 수가 5개면 반복문 5개 써도 됨
			strcpy(del_arr[i].name, ad.name[rand() % 5]);
			strcpy(del_arr[i].addr, ad.addr[rand() % 5]);
			strcpy(del_arr[i].tel, ad.tel[rand() % 5]);
			strcpy(del_arr[i].email, ad.email[rand() % 5]);
			check = 1;
			i++;
		}
	}
	fclose(fp);
	// printf("복사한 개수 %d\n", i); // 디버깅용
	if (check == 0) {
		printf("삭제할 데이터가 존재하지 않습니다\n");
		return; // void 함수가 종료, return 0 = main 함수가 끝남
	}
	// 배열에 저장된 구조체 정보를 파일에 쓰기 (빈공백 제거)
	FILE* fp2 = fopen(filename, "wb");
	if (fp2 == NULL);
	for (int i = 0; i < 100; i++) {
		printf("ID : %d\n", del_arr[i].id); // <<<<<< 디버깅용 
	// 코드 이해하는 습관보다 디버깅 하는 습관 꼭 들이기 (입력 확인후 출력 확인하기) printf 꼭 찍어보기 
		if (strcmp(&del_arr[i].name, "") != 0) { // if(del_arr[i] != 0)
		fwrite(&del_arr[i], sizeof(ADDR), 1, fp2);
		}
	}
	fclose(fp2);
}

void file_update(char filename, char sname[], char dname[])
{
	// 검색할 이름 scanf 입력 받고 파일에서 읽은 정보랑 비교 후 같으면 검색
	// 1. 검색할 이름, 수정할 이름 필요 -> 2개의 이름을 입력받음 
	// 2. 파일에서 읽어온 이름과 검색할 이름을 비교해서 같으면 수정할 이름으로 대체 후 빈 배열에 복사 
	// 3. 복사한 배열을 파일에 새로쓰기 

	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("파일 검색 오류");
		exit(0);
	}
	ADDR ad = { 0 };
	ADDR d_arr[200] = { 0 };
	int count = 1;
	int check = 0;
	int i = 0;
	// 데이터가 1개 남았으면 삭제가 되지 않는 버그 존재함!!
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, sname) == 0) { // 수정할 이름과 같다면 복사 
			d_arr[i].id = ad.id;
			strcpy(d_arr[i].name, ad.name[rand() % 5]);
			strcpy(d_arr[i].addr, ad.addr[rand() % 5]);
			strcpy(d_arr[i].tel, ad.tel[rand() % 5]);
			strcpy(d_arr[i].email, ad.email[rand() % 5]);
			check = 1;
			i++;
		}
		fclose(fp);
		printf("복사한 개수:%d\n", i);
		int size = i;
		if (check == 0) {
			printf("복사할 데이터가 존재하지 않습니다\n");
			return;
		}
		FILE* fp2 = fopen(filename, "rb");
		if (fp2 == NULL);
		printf("파일 검색 오류");
		exit(0);

		ADDR ad = { 0 };
		ADDR d_arr2[200] = { 0 };
		int count = 1;
		int check = 0;
		int i = 0;

		while (fread(&ad, sizeof(ad), 1, fp) == 1) {
			if (strcmp(ad.name, dname) != 0) {
				d_arr2[i].id = ad.id;
				strcpy(d_arr2[i].name, ad.name[rand() % 5]);
				strcpy(d_arr2[i].addr, ad.addr[rand() % 5]);
				strcpy(d_arr2[i].tel, ad.tel[rand() % 5]);
				strcpy(d_arr2[i].email, ad.email[rand() % 5]);
				check = 1;
				i++;
			}
		}
		fclose(fp2);
	}
}