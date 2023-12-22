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
			printf("�̸� �Է�:");
			scanf("%s", myfren1.name);
			//getchar();
			printf("����(M/F) �Է�:");
			scanf(" %c", &myfren1.sex);
			printf("���� �Է�:");
			scanf("%d", &myfren1.age);
			friend_write(myfren1);
			break;
		}
		case 2:
		{
			Friend myfren2 = friend_read();
			printf("�̸�:%s\n", myfren2.name);
			printf("����:%c\n", myfren2.sex);
			printf("����:%d\n", myfren2.age);
			break;
		}
		case 3:
			printf("���α׷� ����!\n");
			exit(0);
		default:
			printf("�߸��� �޴� ����!\n");
		}
	}
}

int main_menu()
{
	printf("---------------------------\n");
	printf("���� ���� ���α׷� v1.0\n");
	printf("---------------------------\n");
	printf("1. ģ�� ���� ����\n");
	printf("2. ģ�� ���� �б�\n");
	printf("3. ����\n");
	printf("---------------------------\n");
	printf("�޴� ����:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void friend_write(Friend myfren1)
{
	// ���� ����	
	FILE* fp = fopen("friend.bin", "wb");
	fwrite(&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);
}

Friend friend_read()
{
	// ���� �б�
	Friend myfren2 = { 0 };
	FILE* fp = fopen("friend.bin", "rb");
	fread(&myfren2, sizeof(myfren2), 1, fp);
	fclose(fp);
	return myfren2;
}