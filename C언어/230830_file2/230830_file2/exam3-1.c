// exam3.c
// ������ ���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()

typedef struct _CAR {
	char model[20];
	char price[20];
	int year;
} CAR;

typedef struct _CUST {
	char name[20];
	char tel[20];
	char addr[50];
	CAR car;
} CUST;

const char* name[] = { "ȫ�浿", "����ġ", "������", "������", "�̼���" };
const char* tel[] = { "010-1234-1234", "010-1234-1111", "010-1234-2222",
	"010-1234-3333", "010-1234-4444" };
const char* addr[] = { "�뱸 ���� �ž�4��", "���� ���� �ž�4��" ,
	"���� ���� �ž�4��", 	"���� ���� �ž�4��", "�λ� ���� �ž�4��" };
const char* model[] = { "�׷���", "���׽ý�", "K7", "K9", "�ҳ�Ÿ" };
const char* price[] = { "4õ����", "5õ����", "6õ����", "7õ����", "8õ����" };
const int year[] = { 2020, 2021, 2022, 2023, 2024 };

int main_menu();
void write_cust_dir(char fileName[]); // �Ű����� ����ؼ� �Լ� ȣ���غ��� 
void write_cust_rand(char fileName[]);
void read_cust(char fileName[]);
void del_all_cust(char fileName[]);

int main()
{
	// ����: ���Ͽ� �����Ҷ� ���� �����Ͱ� ��� �����ؾߵ�!!!
	char fileName[] = "customer.bin";
	// ������ �̸��� �Ű������� ����
	while (1) {
		switch (main_menu()) {
		case 1:
			write_cust_dir(fileName);
			break;
		case 2:
			write_cust_rand(fileName);
			break;
		case 3:
			read_cust(fileName);
			break;
		case 4:
			del_all_cust(fileName);
			break;
		case 5:
			printf("���α׷� ����\n");
			exit(0);
		default:
			printf("�߸��� �޴� ����!!\n");
		}
	}
}

int main_menu()
{
	printf("=============================\n");
	printf("�� ���� ���� ���α׷� v2.0\n");
	printf("=============================\n");
	printf("1.�� ���� ���� �Է�\n");
	printf("2.�� ���� ���� �Է�\n");
	printf("3.�� ���� ����\n");
	printf("4.�� ���� ��ü ����\n");
	printf("5.����\n");
	printf("=============================\n");
	printf("�޴� ����:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

// ���Ͽ� ������ ���� �Է�
void write_cust_dir(char fileName[])
{
	CUST cust = { 0 };
	printf("����:");
	scanf("%s", cust.name);
	printf("��ȭ:");
	scanf("%s", cust.tel);
	printf("�ּ�:");
	getchar();
	gets(cust.addr); // ������ �Է¹ޱ����� ���			
	printf("������:");
	scanf("%s", cust.car.model);
	printf("����:");
	scanf("%s", cust.car.price);
	printf("����:");
	scanf("%d", &cust.car.year);

	FILE* fp = fopen(fileName, "ab");
	if (fp == NULL) {
		printf("���� ����(D) ���� ����!!\n");
		return -1;
	}
	fwrite(&cust, sizeof(cust), 1, fp);
	fclose(fp);
	printf("�������� ���Ͽ� ����Ǿ����ϴ�!\n");
}

// ���Ͽ� ������ ���� �Է�
void write_cust_rand(char fileName[])
{
	CUST cust_arr[5] = { 0 };
	FILE* fp = fopen(fileName, "ab");
	if (fp == NULL) {
		printf("���� ����(R) ���� ����!!\n");
		return -1;
	}
	for (int i = 0; i < 5; i++) {
		strcpy(cust_arr[i].name, name[rand() % 5]);
		strcpy(cust_arr[i].tel, tel[rand() % 5]);
		strcpy(cust_arr[i].addr, addr[rand() % 5]);

		strcpy(cust_arr[i].car.model, model[rand() % 5]);
		strcpy(cust_arr[i].car.price, price[rand() % 5]);
		cust_arr[i].car.year = year[rand() % 5];
		fwrite(&cust_arr[i], sizeof(cust_arr[i]), 1, fp);
	}
	fclose(fp);
	printf("������ �����Ͱ� ���Ͽ� ����Ǿ����ϴ�!\n");
}

// ���Ͽ� ������ ����
void read_cust(char fileName[])
{
	CUST temp = { 0 };
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf("���� �б� ���� ����!!\n");
		return -1;
	}
	int cnt = 1;
	while (fread(&temp, sizeof(temp), 1, fp) == 1) {
		printf("��ȣ:%d ��:%s ��ȭ:%d �ּ�:%s\n", cnt++,
			temp.name, temp.tel, temp.addr);
		printf("��:%s ����:%s ����:%d\n",
			temp.car.model, temp.car.price, temp.car.year);
		printf("=================================\n");
	}
	fclose(fp);
}

// ������ ��ü ����
void del_all_cust(char fileName[])
{
	FILE* fp = fopen(fileName, "wb");
	printf("���� ��ü ����!\n");
	fclose(fp);
}