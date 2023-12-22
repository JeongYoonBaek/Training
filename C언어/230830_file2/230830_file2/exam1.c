#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()
#include <time.h> // time()
// ������ϴ� ���� �� ���ϰ�!!!

typedef struct _PERSON {
	char name[20];
	int age;
	char tel[20];
	char addr[50];
} PERSON;

char* name[] = { "ȫ�浿", "����ġ", "������", "�̼���", "������"};
int age[] = { 20, 30, 40, 50, 60 };
char* tel[] = { "010-1234-1111", "010-1234-2222", "010-1234-3333",
	   010,1234 - 4444, "010-1234-5555"};
char* addr[] = { "����", "�λ�", "�뱸", "��õ", "����"};

int main_menu(menu);
void file_wb();
void file_rb();

int main()
{

	//----------------------------
	// ���� ���� ���α׷� v1.0
	//----------------------------
	// 1. 10���� ������ ������ ���� �Է�
	// 2. ���Ͽ��� �о����
	// 3. ����
	//----------------------------
	// �޴� ����:

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
	printf("������ �����Ͱ� ���Ͽ� ����Ǿ����ϴ�!\n");

	while (1)
		switch (main_menu()) {
		case 1:
			file_wb();
			break;
		case 2:
			file_rb();
			break;
		case 3:
			printf(" ���α׷� ����!");
			exit(0);
		default:
			printf("�߸��� �޴� �Է�!!!");
		}
}

int main_menu()
{
	printf("-------------------------\n");
	printf("���� ���� ���α׷� v1.0\n");
	printf("-------------------------\n");
	printf("1. 10���� ������ ������ ���� �Է�\n");
	printf("2. ���Ͽ��� �о����\n");
	printf("3. ����\n");
	printf("-------------------------\n");
	printf("�޴� ����:");

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
		printf("���� ���� ���� ����!!\n");
		return -1;
	}

	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		strcpy(myfren1_arr[i].name, name[rand() % 5]);
		myfren1_arr[i].age, age[rand() % 5];
		strcpy(myfren1_arr[i].tel, tel[rand() % 5]);
		strcpy(myfren1_arr[i].addr, addr[rand() % 5]);
		fwrite(&myfren1_arr[i], sizeof(myfren1_arr[i]), 1, fp);

		printf("�̸� �Է�: "); scanf(" %s", myfren1.name);
		printf("���� �Է�: "); scanf(" %d", myfren1.age);
		printf("����ó �Է�: "); scanf(" %s", myfren1.tel);
		printf("�ּ� �Է�: "); scanf(" %s", myfren1.addr);
		printf("���Ͽ� ���������� �ԷµǾ����ϴ�!\n");
		fclose(fp);
	}
}
void file_rb()
{
	FILE* fp;
	PERSON myfren1 = { 0 }; 
	if (fp == NULL) {
		printf("���� �б� ���� ����!!\n");
		return -1;
		fp = fopen("friend.bin", "rb");
		printf("�̸� %s, ���� %c, ����ó %s, �ּ� %s \n",
			myfren1.name, myfren1.age, myfren1.tel, myfren1.age);
		fread(&myfren1, sizeof(PERSON), 1, fp);
		fclose(fp);
	}
	return -1;
}
	
