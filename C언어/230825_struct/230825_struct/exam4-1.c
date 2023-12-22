#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy ���ڿ� ó�� ���� 
#include <stdlib.h>
#include <time.h> // time()

// ������Ʈ ���� ���� : ����ȸ�� => �䱸���� => ���� => ���� => �׽�Ʈ => ��������
// �䱸���� : B2B(����� ���) B2C(����� ��) B2G(����� ����) 
// ���� : UI(�̹��� ���� �����), DB, ���α׷�(��)
// ���� : �˰����� ���� �߿���
// �������� : ���� ���� �� ���׷��̵� 
// ȸ����� ���α׷� : ERP) ȸ�����, �������, ��������, ������ ���õ� ��� �͵��� �����ϴ� ���α׷�
// �÷��� ���� : īī�� �ý�, ���, ��ٸ��� 

// C��� ������ ���α׷��� - ������ �켱��
// ��ü���� ���α׷��� - ��ü�� �켱��

struct member // �� ���� ����ü
{
	char name[20];
	char tel[20];
	char addr[20];
	char job[20];
	char birth[20];
};

struct car // ���� ���� ����ü
{
	char car_model[20];
	int price;
	int year;
	char color[20];
	char store[20];
};

int main_menu();
void ins_customer(struct customer cu[]);
void show_customer(struct customer cu[]);

int main()
{
	//----------------------------------
	// ������ ���� ���α׷� v1.5
	//----------------------------------
	// 1. ���� �������� �Է� // ���� �Է� x 1�� �����ϸ� ���� �����ϰ� �̾ƿ��� ��
	// 2. ���� �������� ���� : �������� ����� 100�� ���� ������ printf ��� 
	// 3. ���� exit(0);
	//----------------------------------
	// �޴� ����: 
	main_menu();
	ins_customer;
	show_customer;
}

int_main_menu(cu)
{   
		srand(time(NULL));
		while (1) {
			switch (main_menu(cu)) {
			case 1:
				ins_customer(cu);
				break;
			case 2:
				show_customer(cu);
				break;
			case 3:
				printf("���α׷� ���� \n");
				exit(0);
			Default: 
				printf("�߸��� �޴� ����! \n");
			}
		}
}

void ins_customer(struct customer cu[])
{
	printf("----------------------------------\n");
	printf("�� ���� ���� ���α׷� v1.5\n");
	printf("----------------------------------\n");
	printf("1.���� �������� �Է�\n");
	printf("2.���� �������� ����\n");
	printf("3.����\n");
	printf("----------------------------------\n");
	int menu;
	printf("�޴� ����:");
	scanf("%d", &menu);
	printf("----------------------------------\n");
	return menu;
};

void show_customer(menu)
{
	struct member cu[100] = { 0 };
	char* name[5] = { "ȫ�浿", "����ġ", "������", "�̼���", "������" };
	char* tel[5] = { "010 - 1234 - 1111" , "010 - 1234 - 2222", "010 - 1234 - 3333",
		"010 - 1234 - 4444", "010 - 1234 - 5555" };
	char* addr[5] = { "����", "�λ�", "��õ", "����", "�뱸" };
	char* job[5] = { "ȸ���", "������", "����", "�ֺ�", "�ڿ�����" };
	char* birth[5] = { "1�� 6��", "3�� 6��", "6�� 6��", "9�� 6��", "12�� 6��" };

	struct car cu2[100] = { 0 };
	char* car_model[5] = { "�ƹݶ�", "EŬ����", "�������ι�", "K5", "�䷹��" };
	int price[5] = { "20000000", "30000000", "40000000", "60000000", "80000000" };
	int year[5] = { "2016", "2018", "2020", "2022", "2024" };
	char* color[5] = { "��", "ȭ��Ʈ", "���", "�������", "����" };
	char* store[5] = { "����", "����", "���", "����ι�", "�ֿ�" };

	for (int i = 0; i < 100; i++) {
		strcpy(cu[i].name, name[rand() % 5]);
		strcpy(cu[i].tel, tel[rand() % 5]);
		strcpy(cu[i].addr, addr[rand() % 5]);
		strcpy(cu[i].job, job[rand() % 5]);
		strcpy(cu[i].birth, birth[rand() % 5]);

		strcpy(cu2[i].car_model, car_model[rand() % 5]);
		cu2[i].price = price[rand() % 5];
		cu2[i].year = year[rand() % 5];
		strcpy(cu2[i].color, color[rand() % 5]);
		strcpy(cu2[i].store, store[rand() % 5]);
};
