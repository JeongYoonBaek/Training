#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // ��,���
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()

// �������� : �Լ� �ۿ��� ����Ǵ� ����
// �������� : �Լ� �ȿ����� ����Ǵ� ����
const char CHECK_FULL = 'f'; // �������� - ��� �Լ��� ���� ���ް���!
// #define CHECK_FULL 'f'�ε� ���� ����
const char CHECK_EVEN = 'e'; // const - ��� ������ ������ �� ���
const char CHECK_ODD = 'o';  // ��� - ���� ������ �� ���� ����

int main_menu();
void gugu(char n);

int main()
{
	
	while (1) { // ���� �ݺ�
		int menu = main_menu(1); //���� ������ �ż� �������� ����
		switch (menu) {
		case 1: // ¦��
			gugu(CHECK_EVEN); // �Ű������� ��� (¦���� ��� �߰�)
			break;
		case 2: // Ȧ��
			gugu(CHECK_ODD); // �Լ��� ���Ե� �ٸ� ����� �����Ϸ��� �Ű����� ���
			break;
		case 3: // ��ü
			gugu(CHECK_FULL);
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
	scanf("%d", &menu); // �޴��� �Է¹���
	return menu; // ���� �ް� ����ġ������ ���ư��� ���
}

void gugu(char n)
{
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			if (j % 2 == 0 && n == CHECK_EVEN) {// (j % 2 == 0)¦�� �ܸ� ���
				printf("%d * %d = %d\t", j, i, j * i);
			}
			else if (j % 2 != 0 && n == CHECK_ODD) { // ������ �Ŵ� ���
				printf("%d * %d = %d\t", j, i, j * i);
			}
			else if (n == CHECK_FULL) { // ��ü
				printf("%d * %d = %d\t", j, i, j * i);
			} // hard coding : �����ڵ� © �� ��� x
		}
		printf("\n");
	}
}
