// main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <conio.h>
#include <windows.h>// Sleep()	
#include "menu.h" 
#include "ui.h" 
#include "file.h"
#include "rdata.h"

// #define NOCURSOR			0
// #define SOLID_CURSOR		1
// #define NORMAL_CURSOR	2

int main()
{
	char file[] = "address.bin";
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
			ADDR ad[RAND_SIZE] = { 0 };
			int len = sizeof(ad) / sizeof(ADDR); // �迭 ũ��
			for (int i = 0; i < len; i++) {
				ad[i].id = id[rand() % 5];
				strcpy(ad[i].name, name[rand() % 5]);
				strcpy(ad[i].addr, addr[rand() % 5]);
				strcpy(ad[i].tel, tel[rand() % 5]);
				strcpy(ad[i].email, email[rand() % 5]);
			}
			file_write_rand(ad, file, len);
			printf("���� �����͸� �������Դϴ�......\n");
			Sleep(2000); // sec - ms - us - ns
			system("pause");
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
			file_write(ad, file);
			printf("�����Ͱ� �Է����Դϴ�......\n");
			Sleep(1000);
			system("pause");
			break;
		}
		case 3:
			file_del_all(file);
			printf("��ü �����͸� �������Դϴ�......\n");
			Sleep(1000);
			system("pause");
			break;
		case 4:
			file_read(file);
			system("pause");
			break;
		case 5:
		{   
			search_menu();
			char name[20] = { 0 };
			printf("������ �˻����� �̵����Դϴ�....\n:");
			Sleep(1000);
			system("pause");
			break;
		}
		case 6:
		{
			printf("������ �̸� �Է�:");
			char name[20];
			scanf("%s", name);
			printf("%s �����͸� �������Դϴ�...\n", name);
			file_delete2(file, name);
			Sleep(1000);
			system("pause");
			break;
		}
		case 7:
		{
			printf("�˻��� �̸� �Է�:");
			char sname[20];
			scanf("%s", sname);
			printf("������ �̸� �Է�:");
			char dname[20];
			scanf("%s", dname);
			printf("%s �����͸� �������Դϴ�...\n", sname);
			file_update(file, sname, dname);
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
