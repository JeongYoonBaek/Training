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

char* model[] = { "�ƹݶ�", "�ҳ�Ÿ", "���׽ý�", "K5", "520d" };
char* price[] = { "20000000", "30000000", "40000000", "50000000", "60000000" };
int year[] = { 2018, 2019, 2020, 2021, 2022 };

char* name[] = { "ȫ�浿", "������", "������", "������", "����ġ" };
char* tel[] = { "010-1234-1111", "010-1234-2222", "010-1234-3333", "010-1234-4444", "010-1234-5555" };
char* addr[] = { "����", "�λ�", "����", "�뱸", "����" };

int main_menu();
void cust_write();
void cust_random();
void cust_read();

int main()
{    
	// ������ ���̽� ���� ó�� 4���� ���� : 1. �Է�, 2. �˻�, 3. ���ʿ��� ������ ����, 4. ����  
	// ����: ���Ͽ� ������ �� ���� �����Ͱ� ��� �����ؾ���.
	//================================
	// �� ���� ���� ���α׷� v2.0
	//================================
	// 1. �� ���� ���� �Է� (rand x)
	// 2. �� ���� ���� �Է� (rand o)
	// 3. �� ���� ���� 
	// 4. ����
	//================================
	// �޴� ���� : 
	// �� ����: �̸�, ��ȭ, �ּ�
	// ���� ����: �𵨸�, ����, ���� 

	while (1) {
		switch (main_menu()) {
		case 1:
			cust_write();
			break;
		case 2:
			cust_random();
			break;
		case 3:
			cust_read();
			break;
		case 4:
			
		case 5:
			printf("���α׷� ����!\n");
			exit(0);
		default:
			printf("�߸��� �޴� ����!!\n");
		}
	}
}

int main_menu()
{
	printf("================================\n");
	printf(" �� ���� ���� ���α׷� v2.0\n");
	printf("================================\n");
	printf(" 1. �� ���� ���� �Է�\n");
	printf(" 2. �� ���� ���� �Է�\n");
	printf(" 3. �� ���� ����\n");
	printf(" 4. �� ���� ��ü ����\n"); // wb
	printf(" 5. ����\n");
	printf("================================\n");
	printf("�޴� ����");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void cust_write()
{
	CUST Customer = { 0 };
	CAR Car = { 0 };
	FILE* fp = fopen("cust.bin", "wb");

	printf("���� �Է�:");
	scanf("%s", &Customer.name);
	printf("�ּ� �Է� :");
	scanf(" %c", &Customer.addr);
	getchar();
	// gets(cust.addr) ������ �Է¹ޱ� ���� ���. Scanf�� ���ȵ� 
	printf("����ó �Է� :");
	scanf(" %d", &Customer.tel);
	printf("�𵨸� �Է�:");
	scanf(" %s", &Car.model);
	printf("���� �Է�:");
	scanf(" %s", &Car.price);
	printf("���� �Է�:");
	scanf(" %d", Car.year);
	fclose(fp);
	printf("�����Ͱ� ���������� �ԷµǾ����ϴ�\n");
}

void cust_random()
{
	CUST per_arr[10] = { 0 };
	CAR per_arr2[10] = { 0 };
	FILE* fp = fopen("cust.bin", "ab"); // ���ٿ� ����
	 
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		strcpy(per_arr[i].name, name[rand() % 5]);
		strcpy(per_arr[i].tel, tel[rand() % 5]);
		strcpy(per_arr[i].addr, addr[rand() % 5]);
		strcpy(per_arr2[i].model, model[rand() % 5]);
		strcpy(per_arr2[i].price, price[rand() % 5]);
		per_arr2[i].year = year[rand() % 5];
		fwrite(&per_arr[i], sizeof(per_arr[i]), 1, fp);
		fwrite(&per_arr2[i], sizeof(per_arr2[i]), 1, fp);	
	}
	fclose(fp);
	printf("�����Ͱ� ���������� �ԷµǾ����ϴ�\n");
}

void cust_read()
{
	CUST temp = { 0 };
	CAR temp2 = { 0 };
	FILE* fp = fopen("cust.bin", "rb");
	int cnt = 1;
	while (fread(&temp, sizeof(CUST), 1, fp) == 1 &&
		fread(&temp2, sizeof(CAR), 1, fp) == 1) {
		pritnf("&d��° ������\n");
		printf("�̸�:%s ��ȣ:%d �ּ�:%s �𵨸�:%s ����:%s ����:%d  \n", cnt++,
			temp.name, temp.tel, temp.addr, temp2.model, temp2.price, temp2.year);
	}
	fclose(fp);
}
