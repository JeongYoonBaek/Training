#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int sub_menu();

int main()
{
	while (1) {
		system("cls");
		printf("������ȣ 4�ڸ��� �Է��Ͽ� �ֽʽÿ�.\n");	// ������ȣ �Է� �ȳ��� ���
		int car_num[4] = { 0 };							// ������ȣ ���� �迭 ����

		for (int i = 0; i < 4; i++) {					// �迭 �ε����� ������ȣ 1���� ��� ���� 4��(4�ڸ�) �ݺ�
			if (scanf("%1d", &car_num[i]) == 0) {		// ���� �Է��� ���� ���ڰ� �ƴ϶��(scanf�� ��ȯ���� �ֳ��g!)
				system("cls");
				printf("�߸� �Է��ϼ̽��ϴ�.\n");			// �ٽ� �Է��϶�� �ȳ��� ���
				printf("������ȣ 4�ڸ��� �ٽ� �Է��Ͽ� �ֽʽÿ�.\n");
				int c;
				while ((c = getchar()) != '\n' && c != EOF);// ���� �Է½� ���ۿ� ���� �ִ� '����'�� '\n' ����
				i = -1;										// ���� �Է½� i�� -1�� �缳�� ��
			}
			// if�� Ż��� i++�Ǿ� �ᱹ i�� 0�� �ȴ�(= car_num[0]���� �ٽ� �Է��� ����)
		}
		getchar();
		printf("\n");


		// [�����] ������ȣ(�� �ڸ��� x 4�� �ݺ�)
		for (int i = 0; i < 4; i++) {
			printf("car_num[%d] = %d\n", i, car_num[i]);
		}
		printf("\n");


		// �Է��� ������ȣ�� �´��� ��Ȯ�� �ȳ��� ���
		system("cls");
		printf("�Է��Ͻ� ������ȣ�� Ȯ���Ͽ� �ֽʽÿ�.\n");
		for (int i = 0; i < 4; i++) {	// ������ȣ �� �ڸ���x�� �� ���
			printf("%d", car_num[i]);
		}
		printf("\n");

		while (1) {
			int answer = sub_menu();
			if (answer == 2) {		// 2�� �Է½� while���� Ż��, ���� while������ �ǵ��ư���
				break;
			}
		}
	}
}

int sub_menu()
{
	int menu;
	while (1) {
		printf("1.���� �ܰ�  2.�ٽ� �Է�\n");
		scanf("%d", &menu);
		if (menu != 1 && menu != 2) {	// ���� �Է��� menu�� 1�� �ƴϰ� 2�� �ƴ� ���
			system("cls");
			int c;
			while ((c = getchar()) != '\n' && c != EOF);	// ���� �Է½� ���� �ʱ�ȭ
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			printf("�ٽ� �Է��Ͽ� �ֽʽÿ�.\n");
		}
		else if (menu == 1) {	// ���� �Է��� menu�� 1�̶��
			printf("���� ȭ������ �Ѿ�ϴ�.\n");
			system("pause");
			break;
		}
		else if (menu == 2) {	// ���� �Է��� menu�� 2���
			printf("ó�� ȭ������ �ǵ��ư��ϴ�.\n");
			system("pause");
			break;
		}
	}
	return menu;
}