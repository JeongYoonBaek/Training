// �ҽ����� ����: ������� ��(����) github, Perforce, SVN, NAS (���� ���� ����)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <windows.h>// win32 api ��� (������ ȯ�濡���� ��� ����)
#include <conio.h>
// #define NOCURSOR			0
// #define SOLID_CURSOR		1
// #define NORMAL_CURSOR	2

#define RAND_SIZE	10

typedef enum {
	NOCURSOR,		// Ŀ�� ����		0
	SOLID_CURSOR,	// solid ����	1
	NORMAL_CURSOR	// �Ϲ� ����		2
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
const char* name[] = { "ȫ�浿", "����ġ", "������", "������", "�̼���" };
const char* tel[] = { "010-1234-1234", "010-1234-1111", "010-1234-2222",
	"010-1234-3333", "010-1234-4444" };
const char* addr[] = { "�뱸 ���� �ž�4��", "���� ���� �ž�4��" ,
	"���� ���� �ž�4��", 	"���� ���� �ž�4��", "�λ� ���� �ž�4��" };
const char* email[] = { "hong@naver.com", "joen@kakao.com",
	"kang@gmail.com", "yu@msn.com", "lee@daum.net" };

// �Լ� ���� ������Ÿ��
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
	srand(time(NULL)); // �����Լ� ����� ���� �õ� ����
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
			ADDR ad[RAND_SIZE] = { 0 }; // ADDR ����ü���� ������Ÿ������ ����
			int len = sizeof(ad) / sizeof(ADDR); // �迭 ũ�� (����ü ũ�� X 10) = �������� ũ�� 
			for (int i = 0; i < len; i++) {
				ad[i].id = id[rand() % 5];
				strcpy(ad[i].name, name[rand() % 5]);
				strcpy(ad[i].addr, addr[rand() % 5]);
				strcpy(ad[i].tel, tel[rand() % 5]);
				strcpy(ad[i].email, email[rand() % 5]);
			}
			file_write_rand(ad, file, len); // ad, file : �ּҿ� ���� ���� ��� (len : ���� ���� ����)
			printf("���� �����͸� �������Դϴ�......\n");
			Sleep(2000); // sec - ms - us - ns
			system("pause"); // ���� ���¿��� �Է��� �ϸ� ȭ���� ������ 
			break;
		}
		case 2:
		{
			ADDR ad = { 0 };
			printf("ID:");
			scanf("%d", &ad.id);

			printf("�̸�:");
			scanf("%s", ad.name);

			printf("��ȭ:");
			scanf("%s", ad.tel);

			printf("�ּ�:");
			getchar();
			gets(ad.addr);

			printf("Email:");
			scanf("%s", ad.email);
			file_write(ad, file); // ad : ���� ���� ����(����ü �Ϲݺ���), file : �ּҿ� ���� ���� ��� (�迭)
			printf("�����Ͱ� �Է����Դϴ�......\n");
			Sleep(1000);
			system("pause");
			break;
		}
		case 3:
		{
			file_del_all(file);
			printf("��ü �����͸� �������Դϴ�......\n");
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
			printf("�˻��� �̸��� �Է��ϼ���:"); 
			// 1.�˻��� �̸��� �Է� 2.�Է¹��� �˻��� �̸��� ���Ͽ��� �о�� �̸��� ������ �� 
			scanf("%s", name);
			file_search(file, name);
			system("pause");
			break;
		}
		case 6:
		{
			char name[20] = { 0 };
			printf("������ �̸��� �Է��ϼ���:");
			scanf("%s", name);
			file_delete(file, name);
			printf("%s �����͸� �������Դϴ�...\n", name);
			Sleep(1000);
			system("pause");
			break;
		}
		case 7:
		{
			char name[20] = { 0 };
			printf("�˻��� �̸��� �Է��ϼ���:");
			scanf("%s", name);
			printf("�˻��� �̸��� �Է��ϼ���:");
			scanf("%s", name);
			file_update(file, name, name);
			Sleep(1000);
			system("pause");
			break;
		}
		case 8:
			printf("���α׷� ����!\n");
			exit(0);
		default:
			printf("�߸��� �޴� ����!!\n");
		}
		system("cls");
	}
}

int main_menu()
{
	printf("=============================\n");
	printf("�ּҷ� ���� ���α׷� v1.0\n");
	printf("=============================\n");
	printf("1.�ּҷ� �ڵ� ����\n");
	printf("2.�ּҷ� ���� �Է�\n");
	printf("3.�ּҷ� ��ü ����\n");
	printf("4.�ּҷ� ����\n");
	printf("5.�ּҷ� �˻�\n");
	printf("6.�ּҷ� ����\n");
	printf("7.�ּҷ� ����\n");
	printf("8.����\n");
	printf("=============================\n");
	printf("�޴� ����:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void title()
{
	int x = 5;
	int y = 3;
	gotoxy(x, y + 0); printf("������������������������������"); // x,y ��ǥ�� ���� �ش� ������ ȭ�鿡 �Ѹ���
	gotoxy(x, y + 1); printf("��							     ��");
	gotoxy(x, y + 2); printf("��							     ��");
	gotoxy(x, y + 3); printf("��							     ��");
	gotoxy(x, y + 4); printf("��							     ��");
	gotoxy(x, y + 5); printf("��							     ��");
	gotoxy(x, y + 6); printf("��							     ��");
	gotoxy(x, y + 7); printf("������������������������������");
	gotoxy(x + 12, y + 2); printf("�ּҷ� ���� ���α׷� v1.5");
	gotoxy(x + 33, y + 4); printf("���߳�¥	: 2023.09.01");
	gotoxy(x + 33, y + 5); printf("������	: ������");
	gotoxy(x, y + 12); printf("����ȭ�� �̵��� �ƹ�Ű�� ��������!!!");
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// ������ �ֿܼ��� Ŀ�� ��ġ �̵�
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
	// Ŀ�� Ÿ���� ����
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info); // Ŀ�� Ÿ�� ���� (win32 API)
}

void font_color(FONT_COLOR color)
{
	// ��Ʈ�� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void file_write_rand(ADDR ad[], char filename[], int len)
{
	FILE* fp = fopen(filename, "ab");
	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}

	for (int i = 0; i < len; i++) {
		fwrite(&ad[i], sizeof(ADDR), 1, fp); // fwrite(������) ad�տ� �ּҰ� & ����. �迭�϶� [i]�� �Ϲݺ��� ����
	}
	fclose(fp);
}

void file_write(ADDR ad, char filename[])
{
	FILE* fp = fopen(filename, "ab");
	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}
	fwrite(&ad, sizeof(ADDR), 1, fp); // �ּҰ��̱� ������ ad�տ� &���̱�
	fclose(fp);
}

void file_read(char filename[])
{
	// �����Ͱ� ������ "�����Ͱ� �������� �ʽ��ϴ�" ���� �޽����� ���!
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �б� ����!\n");
		exit(0);
	}
	ADDR ad = { 0 };
	int count = 1;
	int check = 0; // check ������ ����� while���� ������ �ϸ� 1�� �ٲ�� ���� Ȯ����
	while (fread(&ad, sizeof(ad), 1, fp) == 1) { // ���������� ������ 1�� ������ ��. (���� ä����)
		printf("��ȣ:%d\n", count++);
		printf("ID:%d\n", ad.id);
		printf("�̸�:%s\n", ad.name);
		printf("��ȭ:%s\n", ad.tel);
		printf("�ּ�:%s\n", ad.addr);
		printf("�̸���:%s\n", ad.email);
		printf("==========================\n");
		check = 1; // check ������ ����� while���� ������ �ϸ� 1�� �ٲ�� ���� Ȯ����
	}
	fclose(fp);
	if (check == 0) {
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	}
}

void file_del_all(char filename[])
{
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("���� �б� ����!\n");
		exit(0);
	}
	fclose(fp);
}

void file_search(char filename[], char name[])
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �˻� ����!\n");
		exit(0);
	}
	ADDR ad = { 0 };
	int count = 1;
	int check = 0; // check ������ ����� while���� ������ �ϸ� 1�� �ٲ�� ���� Ȯ����
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, name) == 0) { // �ڡڡ� strcmp : �� ���� ���ڿ��� ���ϴ� �Լ� �ڡڡ�
			printf("��ȣ:%d\n", count++);
			printf("ID:%d\n", ad.id);
			printf("�̸�:%s\n", ad.name);
			printf("��ȭ:%s\n", ad.tel);
			printf("�ּ�:%s\n", ad.addr);
			printf("�̸���:%s\n", ad.email);
			printf("==========================\n");
			check = 1;
		}
	}
	fclose(fp);
	if (check == 0) {
		printf("�˻��� �����Ͱ� �������� �ʽ��ϴ�.\n");
	}
}

void file_delete(char filename, char delname[])
{
	// 1. ������ �̸� �Է¹���
	// 2. ���Ͽ��� ���� �̸��� ������ �̸��� ������ �� (�˻� �Լ� �񱳹��� ����)
	// 3. �̸��� ������ ������ ����̹Ƿ� ���� �̸��� ������ �迭�� ������ ����. �迭 ũ�� [100]
	// 4. ���� ���Ͽ� w ���� ��� ���Ͽ� ���� 
	// 5. ���� ����, ����(�б�), �ݱ�

	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �˻� ����");
		exit(0);
	}
	ADDR ad = { 0 };
	ADDR del_arr[200] = { 0 };
	int count = 1;
	int check = 0;
	int i = 0;
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, delname) != 0) { // ������ �̸��� �ƴ϶��(�迭�� ������ ����)
			del_arr[i].id = ad.id; // ����Ǵ� ���� 5���� �ݺ��� 5�� �ᵵ ��
			strcpy(del_arr[i].name, ad.name[rand() % 5]);
			strcpy(del_arr[i].addr, ad.addr[rand() % 5]);
			strcpy(del_arr[i].tel, ad.tel[rand() % 5]);
			strcpy(del_arr[i].email, ad.email[rand() % 5]);
			check = 1;
			i++;
		}
	}
	fclose(fp);
	// printf("������ ���� %d\n", i); // ������
	if (check == 0) {
		printf("������ �����Ͱ� �������� �ʽ��ϴ�\n");
		return; // void �Լ��� ����, return 0 = main �Լ��� ����
	}
	// �迭�� ����� ����ü ������ ���Ͽ� ���� (����� ����)
	FILE* fp2 = fopen(filename, "wb");
	if (fp2 == NULL);
	for (int i = 0; i < 100; i++) {
		printf("ID : %d\n", del_arr[i].id); // <<<<<< ������ 
	// �ڵ� �����ϴ� �������� ����� �ϴ� ���� �� ���̱� (�Է� Ȯ���� ��� Ȯ���ϱ�) printf �� ���� 
		if (strcmp(&del_arr[i].name, "") != 0) { // if(del_arr[i] != 0)
		fwrite(&del_arr[i], sizeof(ADDR), 1, fp2);
		}
	}
	fclose(fp2);
}

void file_update(char filename, char sname[], char dname[])
{
	// �˻��� �̸� scanf �Է� �ް� ���Ͽ��� ���� ������ �� �� ������ �˻�
	// 1. �˻��� �̸�, ������ �̸� �ʿ� -> 2���� �̸��� �Է¹��� 
	// 2. ���Ͽ��� �о�� �̸��� �˻��� �̸��� ���ؼ� ������ ������ �̸����� ��ü �� �� �迭�� ���� 
	// 3. ������ �迭�� ���Ͽ� ���ξ��� 

	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �˻� ����");
		exit(0);
	}
	ADDR ad = { 0 };
	ADDR d_arr[200] = { 0 };
	int count = 1;
	int check = 0;
	int i = 0;
	// �����Ͱ� 1�� �������� ������ ���� �ʴ� ���� ������!!
	while (fread(&ad, sizeof(ad), 1, fp) == 1) {
		if (strcmp(ad.name, sname) == 0) { // ������ �̸��� ���ٸ� ���� 
			d_arr[i].id = ad.id;
			strcpy(d_arr[i].name, ad.name[rand() % 5]);
			strcpy(d_arr[i].addr, ad.addr[rand() % 5]);
			strcpy(d_arr[i].tel, ad.tel[rand() % 5]);
			strcpy(d_arr[i].email, ad.email[rand() % 5]);
			check = 1;
			i++;
		}
		fclose(fp);
		printf("������ ����:%d\n", i);
		int size = i;
		if (check == 0) {
			printf("������ �����Ͱ� �������� �ʽ��ϴ�\n");
			return;
		}
		FILE* fp2 = fopen(filename, "rb");
		if (fp2 == NULL);
		printf("���� �˻� ����");
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