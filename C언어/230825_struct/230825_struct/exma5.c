#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy ���ڿ� ó�� ���� 
#include <stdlib.h>
#include <time.h> // time()
struct car
{
	char car_model[20];
};

struct manager
{
	char name2[20];
};

struct customer
{
	char name[20];
	struct car ca;
	struct manager mg;
};


char* name[5] = { "ȫ�浿", "����ġ", "������", "�̼���", "������" };
char* car_model[5] = { "�׷���", "���׽ý�", "��Ÿ��", "�ҳ�Ÿ", "K9" };
char* name2[5] = {"��浿", "�̿�ġ", "�ڰ���", "�����", "������"};

int main_menu();
void ins_customer(struct customer cu[]);
void random_customer(struct customer cu[]);
void show_customer(struct customer cu[]);

int main()
{   
	// ���̸�, ������, �Ŵ����� (����ü 3�� �ʿ�, ���� 1������ �ʿ�)
	//------------------------------
	// �� ���� ���� ���α׷� v1.6
	//------------------------------
	// 1. ������ ���� �Է� scanf �Է�
	// 2. ������ ���� �Է� �����ϰ� printf
	// 3. ������ ���� scanf �Է°� �����ֱ� 
	// 4. ����
	//------------------------------
	// �޴�����:

	srand(time(NULL)); // �����Լ��� ����ϱ� ���� �ʼ�����
	struct customer cu[10] = { 0 }; // ����ü �̸��� ���ÿ� (������Ÿ��)

	while (1) {
		// �ؿ��� ������. int menu = main_menu();
		switch (main_menu()) {
		case 1:
			ins_customer(cu);
			break;
		case 2:
			random_customer(cu);
			break;
		case 3:
			show_customer(cu);
			// for (int i =0; i < 5; i++){
			// cu[i].name �� ���� ""�� ���ٸ�
			// // ��, �������� ������ Ż��
			// if (strcmp(cu[i].name, "")== 0) ���̸� ������ X { // strcmp : ���� ���ڿ����� ���� 
			// break; }
			break;
		case 4:
			printf("���α׷� ����!\n");
			exit(0);
		default:
			printf("�߸��� �޴� ����!!!\n");
		}
	}
}

int main_menu()
{
	printf("----------------------------\n");
	printf("������ ���� ���α׷� v1.6\n");
	printf("----------------------------\n");
	printf("1. ������ ���� �Է�\n");
	printf("2. ������ ���� �Է�\n");
	printf("3. ������ ����\n");
	printf("----------------------------\n");
	printf("�޴� ���� :");
	int menu;
	scanf("%d", &menu);
	return menu; // �Լ� ���� ���� (�Ű�����)
}

void ins_customer(struct customer cu[])
{      
		printf("���� �Է�:%s\n");
		scanf("%s", cu[0].name);
		printf("������ �Է�:%s\n");
		scanf("%s", cu[0].ca.car_model);
		printf("�Ŵ����� �Է�:%s\n");
		scanf("%s", cu[0].mg.name2);
		printf("���������� �����Ͱ� �ԷµǾ����ϴ�\n");
		printf("=============================\n");
}

void random_customer(struct customer cu[])
{
	for (int i = 0; i < 10; i++) {
		strcpy(cu[i].name, name[rand() % 5]);
		strcpy(cu[i].ca.car_model, car_model[rand() % 5]);
		strcpy(cu[i].mg.name2, name2[rand() % 5]);
		printf("����:%s\n", cu[i].name);
		printf("������:%s\n", cu[i].ca.car_model);
		printf("�Ŵ�����:%s\n", cu[i].mg.name2);
	}
	printf("���������� �����Ͱ� �ԷµǾ����ϴ�\n");
}

void show_customer(struct customer cu[])
{  
	for(int i = 0; i < 10; i++) {
		printf("����:%s\n", cu[i].name);
		printf("������:%s\n", cu[i].ca.car_model);
		printf("�Ŵ�����:%s\n", cu[i].mg.name2);
		printf("==============================\n");
	}
}