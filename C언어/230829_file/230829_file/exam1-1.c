// exam1.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct fren {
	char name[10];
	char sex;
	int age;
} Friend;

void friend_write(Friend myfren1);
Friend friend_read();

int main()
{
	while (1) {
		switch (main_menu()) {
		case 1:
		{
			Friend myfren1 = { 0 };
			printf("이름 입력:");
			scanf("%s", myfren1.name);
			//getchar();
			printf("성별(M/F) 입력:");
			scanf(" %c", &myfren1.sex);
			printf("나이 입력:");
			scanf("%d", &myfren1.age);
			friend_write(myfren1);
			break;
		}
		case 2:
		{
			Friend myfren2 = friend_read();
			printf("이름:%s\n", myfren2.name);
			printf("성별:%c\n", myfren2.sex);
			printf("나이:%d\n", myfren2.age);
			break;
		}
		case 3:
			printf("프로그램 종료!\n");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!\n");
		}
	}
}

int main_menu()
{
	printf("---------------------------\n");
	printf("파일 제어 프로그램 v1.0\n");
	printf("---------------------------\n");
	printf("1. 친구 정보 쓰기\n");
	printf("2. 친구 정보 읽기\n");
	printf("3. 종료\n");
	printf("---------------------------\n");
	printf("메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void friend_write(Friend myfren1)
{
	// 파일 쓰기	
	FILE* fp = fopen("friend.bin", "wb");
	fwrite(&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);
}

Friend friend_read()
{
	// 파일 읽기
	Friend myfren2 = { 0 };
	FILE* fp = fopen("friend.bin", "rb");
	fread(&myfren2, sizeof(myfren2), 1, fp);
	fclose(fp);
	return myfren2;
}