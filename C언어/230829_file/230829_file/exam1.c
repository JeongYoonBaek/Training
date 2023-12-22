#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct fren
{
	char name[10];
	char sex;
	int age;
} Friend;

int main_menu();
void info_wb();
void info_rb();

int main()
{
	//-----------------------------
	// 파일 제어 프로그램 v1.0 
	//-----------------------------
	// 1. 친구 정보 쓰기 
	// 2. 친구 정보 읽기 
	// 3. 종료
	//-----------------------------
	// 메뉴 선택:

	int main_menu(menu);
	void info_wb();
	void info_rb();
	
	while (1) {
		switch (main_menu()) {
		case 1: // 케이스 안에 중괄호를 묶어서 사용하면 변수 선언 가능
			info_wb();
			break;
		case 2:
			info_rb();
			break;
		case 3:
			printf(" 프로그램 종료!");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!\n");
		}
	}
}

int main_menu()
{
	printf("-----------------------------\n");
	printf(" 파일 제어 프로그램 v1.0\n");
	printf("-----------------------------\n");
	printf(" 1. 친구 정보 쓰기 \n");
	printf(" 2. 친구 정보 읽기 \n");
	printf(" 3. 종료 \n");
	printf("-----------------------------\n");
	printf(" 메뉴 선택: ");

	int menu;
	scanf("%d", &menu);
	return menu;
}
 
void info_wb()
{
	FILE* fp;
	Friend myfren1; // Friend myfren1 = { 0 }; 초기값 선언해도 됨
	
	fp = fopen("friend.bin", "wb");
	printf("이름 입력: ");
	scanf(" %s", myfren1.name);
	// 같은 줄에 성별과 나이 입력이 출력될 때 %s를 한칸 띄우거나 
	// getchar();을 사용하면 됨. 
	printf("성별 (M/F)입력: ");
	scanf(" %c", &myfren1.sex);
	printf("나이 입력: ");
	scanf(" %d", &myfren1.age);
	fwrite(&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);
}

void info_rb()
{
	FILE* fp;
	Friend myfren2; // Friend myfren2 = { 0 }; 초기값 선언해도 됨
	fp = fopen("friend.bin", "rb");
	fread(&myfren2, sizeof(myfren2), 1, fp);
	printf("이름 %s \n", myfren2.name);
	printf("성별 %c \n ", myfren2.sex);
	printf("나이 %d \n", myfren2.age);
	fclose(fp);
}
