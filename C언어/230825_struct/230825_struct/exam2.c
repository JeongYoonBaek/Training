#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy ���ڿ� ó�� ���� 
#include <stdlib.h>
#include <time.h> // time()


struct professor { // ��� ���� ����
	char name[20];  // ������
	char major[20]; // ��������
	int age;        // ��������
};


struct member // �л� ����
{
	char name[20]; // �л���
	char tel[20];  // ��ȭ��ȣ
	char addr[20]; // �ּ�
	int age;       // ����
	struct professor pro; // ��米��
};

int main()
{
	// 1. �л� ���� ����ü �����
	// 2. �л� ������ �̸�, �޴��� ��ȣ, ����, �ּҰ� ����
	// 3. 100���� �л� ������ �����ϰ� �����Ͽ� ���
	// 4. �������� �迭�� ���� �����ϰ� �����ϰ� �ҷ����� ó��

	// ���ڿ��� �����ϴ� �迭 ���� �ڵ�
	/*strcpy(num1.name, "ȫ�浿");
	strcpy(num1.tel, "010-1234-1111");
	strcpy(num1.addr, "����");
	num1.age = 10; */

	struct member num1, num2, num3, num4, num5;

	char* name[5] = { "ȫ�浿", "����ġ", "������", "������", "������" };
	char* tel[] = { 010 - 1234 - 1111 , 010 - 1234 - 2222, 010 - 1234 - 3333, 
		            010 - 1234 - 4444, 010 - 1234 - 5555 }; // -�� �ִ� ������ []���� ���� ����
	char* addr[5] = { "����", "���", "��õ", "�뱸", "���ֵ�" };
	int age[5] = { 10, 20, 30, 40, 50 };
	struct member st[100] = { 0 }; // 100���� ���� ����
	srand(time(NULL));

	for (int i = 0; i < 100; i++) { // 100���� �л� ���� ���� 
		strcpy(st[i].name, name[rand() % 5]); // 5������ ���� �������� ��� 
		strcpy(st[i].tel, tel[rand() % 5]);
		strcpy(st[i].addr, addr[rand() % 5]);
		st[i].age = age[rand() % 5]; // �Ϲ� ������ strcpy�� ����� �ʿ䰡 ����		
	}

	for (int i = 0; i < 100; i++) {
		printf(">>> %d��° �л� ���� <<<\n", i + 1);
		printf("�̸�:%s\n", st[i].name);
		printf("��ȣ:%s\n", st[i].tel);	
		printf("�ּ�:%s\n", st[i].addr);
		printf("����:%d\n", st[i].age);
		printf("==========================\n");
	}

	st[0].pro.age = 50; // ù��° �л��� ��米�� ����
	strcpy(st[0].pro.name, "ȫ����"); // ù��° �л��� ��米�� �̸�
	printf("%s �л��� ��� ����:%s\n", st[0].name , st[0].pro.name);

}