#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy ���ڿ� ó�� ���� 
#include <stdlib.h>
#include <time.h> // time()


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

int main()
{
	// ���������� ���α׷� 1.0
	// �� ����, ���� ���� ����ü -> (Ŭ������ Ȯ��)
	// �� : �̸�, ��ȭ��ȣ, �ּ�, ����, ���� 
	// ���� : �𵨸�, ����, ����, ����, ������
	// 10���� ���� ���������� �迭���� �����ϰ� �����Ͽ� �Է� �� ��� 

	struct member st[10] = { 0 }; 
	char* name[5] = { "ȫ�浿", "����ġ", "������", "�̼���", "������" };
	char* tel[5] = { "010 - 1234 - 1111" , "010 - 1234 - 2222", "010 - 1234 - 3333",
	    "010 - 1234 - 4444", "010 - 1234 - 5555" };
	char* addr[5] = { "����", "�λ�", "��õ", "����", "�뱸" };
	char* job[5] = { "ȸ���", "������", "����", "�ֺ�", "�ڿ�����" };
	char* birth[5] = { "1�� 6��", "3�� 6��", "6�� 6��", "9�� 6��", "12�� 6��" };

	struct car st1[10] = { 0 };
	char* car_model[5] = { "�ƹݶ�", "EŬ����", "�������ι�", "K5", "�䷹��" };
	int price[5] = { "20000000", "30000000", "40000000", "60000000", "80000000" };
	int year[5] = { "2016", "2018", "2020", "2022", "2024" };
	char* color[5] = { "��", "ȭ��Ʈ", "���", "�������", "����" };
	char* store[5] = { "����", "����", "���", "����ι�", "�ֿ�" };

	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		strcpy(st[i].name, name[rand() % 5]);
		strcpy(st[i].tel, tel[rand() % 5]);
		strcpy(st[i].addr, addr[rand() % 5]);
		strcpy(st[i].job, job[rand() % 5]);
		strcpy(st[i].birth, birth[rand() % 5]);

		strcpy(st1[i].car_model, car_model[rand() % 5]);
		st1[i].price = price[rand() % 5];
		st1[i].year = year[rand() % 5];
		strcpy(st1[i].color, color[rand() % 5]);
		strcpy(st1[i].store, store[rand() % 5]);
	}

	for (int i = 0; i < 10; i++) {
		printf(">>> %d��° �� ���� ���� <<<\n", i + 1);
		printf("�̸�:%s\n", st[i].name);
		printf("��ȣ:%s\n", st[i].tel);
		printf("�ּ�:%s\n", st[i].addr);
		printf("����:%s\n", st[i].job);
		printf("����:%s\n", st[i].birth);

		printf("�𵨸�:%s\n", st1[i].car_model);
		printf("����:%d\n", st1[i].price);
		printf("����:%d\n", st1[i].year);
		printf("����:%s\n", st1[i].color);
		printf("������:%s\n", st1[i].store);
		printf("==========================\n");
	}
}
