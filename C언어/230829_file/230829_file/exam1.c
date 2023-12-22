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
	// ���� ���� ���α׷� v1.0 
	//-----------------------------
	// 1. ģ�� ���� ���� 
	// 2. ģ�� ���� �б� 
	// 3. ����
	//-----------------------------
	// �޴� ����:

	int main_menu(menu);
	void info_wb();
	void info_rb();
	
	while (1) {
		switch (main_menu()) {
		case 1: // ���̽� �ȿ� �߰�ȣ�� ��� ����ϸ� ���� ���� ����
			info_wb();
			break;
		case 2:
			info_rb();
			break;
		case 3:
			printf(" ���α׷� ����!");
			exit(0);
		default:
			printf("�߸��� �޴� ����!\n");
		}
	}
}

int main_menu()
{
	printf("-----------------------------\n");
	printf(" ���� ���� ���α׷� v1.0\n");
	printf("-----------------------------\n");
	printf(" 1. ģ�� ���� ���� \n");
	printf(" 2. ģ�� ���� �б� \n");
	printf(" 3. ���� \n");
	printf("-----------------------------\n");
	printf(" �޴� ����: ");

	int menu;
	scanf("%d", &menu);
	return menu;
}
 
void info_wb()
{
	FILE* fp;
	Friend myfren1; // Friend myfren1 = { 0 }; �ʱⰪ �����ص� ��
	
	fp = fopen("friend.bin", "wb");
	printf("�̸� �Է�: ");
	scanf(" %s", myfren1.name);
	// ���� �ٿ� ������ ���� �Է��� ��µ� �� %s�� ��ĭ ���ų� 
	// getchar();�� ����ϸ� ��. 
	printf("���� (M/F)�Է�: ");
	scanf(" %c", &myfren1.sex);
	printf("���� �Է�: ");
	scanf(" %d", &myfren1.age);
	fwrite(&myfren1, sizeof(myfren1), 1, fp);
	fclose(fp);
}

void info_rb()
{
	FILE* fp;
	Friend myfren2; // Friend myfren2 = { 0 }; �ʱⰪ �����ص� ��
	fp = fopen("friend.bin", "rb");
	fread(&myfren2, sizeof(myfren2), 1, fp);
	printf("�̸� %s \n", myfren2.name);
	printf("���� %c \n ", myfren2.sex);
	printf("���� %d \n", myfren2.age);
	fclose(fp);
}
