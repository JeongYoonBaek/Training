#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // ��,���
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()
#include <time.h> // time()

// console ��Ŀ�� ȭ�� : ������ �͹̳� ȯ��

int main_menu(int n);
void gugu1(int n);
void gugu2(int n);
void full_gugu(int n);

int main()
{
	// �Ʒ��� �޴��� ����ϴ� �Լ� �����
	//--------------------------------
	//  �������� ����ϴ� �Լ� ����v1.0
	//--------------------------------
	// 1. ������ ¦���� ��� (2~8)
	// 2. ������ Ȧ���� ��� (3~9)
	// 3. ������ ��ü ���(2~9)
	// 4. ����
	//---------------------------------
	// �޴� ����:

	while (1) { // ���� �ݺ�
		int menu = main_menu(1); //���� ������ �ż� �������� ����
		switch (menu) {
		case 1:
			gugu1(menu); // ¦���� ��� �߰�
			break;
		case 2:
			gugu2(menu); // �Լ��� ���Ե� �ٸ� ����� �����Ϸ��� �Ű����� ���
			break;
		case 3:
			full_gugu(menu);
			break;
		case 4:
			printf("���α׷� ����\n");
			exit(0); // ���α׷��� ������ �����ϴ� �Լ�
		default:
			printf("�߸��� �޴��Է�!!\n");
		}
	}
}

int main_menu(int n)
{
	printf("------------------------------------\n");
	printf("  �������� ����ϴ� �Լ� ���� v1.0\n");
	printf("------------------------------------\n");
	printf(" 1.������ ¦���� ��� (2~8)\n");
	printf(" 2.������ Ȧ���� ��� (3~9)\n");
	printf(" 3.������ ��ü ���(2~9)\n");
	printf(" 4.���� \n");
	printf(" ------------------------------------\n");
	printf(" �޴� ����:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void gugu1(int n)
{
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			if (j % 2 == 0 && n == 1) {// (j % 2 == 0)¦�� �ܸ� ���
				printf("%d * %d= %d\t", j, i, j * i);
			}
			printf("\n");
		}
	}
}
void gugu2(int n)
{
	for (int i = 1; i < 10; i++) {
		for (int j = 3; j < 10; j++) { //(j += 2) 2������ 0�� �ƴѰ� ¦��
			if (j % 2 != 0 && n == 2)
				printf("%d * %d = %d\t", j, i, j * i);
		}
		printf("\n");
	}
}

void full_gugu(int n) // ��ü ������ ��� �Լ�
{
	for (int i = 1; i < 10; i++) { // x1 ~ x9
		for (int j = 2; j < 10; j++) { // 2�ܺ��� 9��
			 printf("%d * %d= %d\t", j, i, j * i);
		}
		printf("\n");
	}
}
