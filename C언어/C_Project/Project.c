#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct time { // ����ü�� �̿��Ͽ� �ð� ���� �����Ѵ�. 
	int hour, min;
};

int main_menu();
int main() {

	//�������ð� ���ϴ� ���� �Լ���
	struct time ent; // ���� �ð� ����ü
	struct time exit; // ���� �ð� ����ü
	int hour, min; // �ð�, �� ���� 

	srand(time(NULL));

	while (1) {

		int menu = main_menu();	// Y/N ȣ�� 
		system("cls");
		if (menu == 1) {
			int ent_hour[2] = { 0 };
			int ent_min[2] = { 0 };
			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < 1; j++) {
					ent_hour[i] = (rand() % 15) + 06; // �ð� ���� ���� ���� �Է� �ޱ� (06��~21�ñ��� �̿밡��)
					ent_min[j] = (rand() % 59); // �� ���� ���� ���� �Է� �ޱ� 
					printf("���� �ð�: %d : %d \t", ent_hour[i], ent_min[j]);
					printf("\n");
				}
			}
			//�����ʿ�. hour���� 6~21 , min����:00~59 
			//�߸� �Է��ϸ� �ٽ� �Է¹ޱ�?
			printf("���� �ð��� �Է��ϼ��� =>  ");
			scanf("%d : %d", &exit.hour, &exit.min);
			hour = exit.hour - (ent_hour[0]);
			min = exit.min - (ent_min[0]);
			if (exit.min < ent_min[0]) {
				hour = (exit.hour - (ent_hour[0])) - 1;
				min = ((exit.min - ent_min[0])) + 60;
			}
			printf("�̿� �ð� : %d�ð� : %d�� \n", hour, min);

			break; //-�����ʿ�. �������� ����Ǿ� �ϴµ� break �ɸ鼭 �ý��� �����
		}
		else if (menu == 2) {
			//�����ʿ�. 2���� ������ �ٽ� ���θ޴��� ���ư��� ��
		}
		else
		{
			//�����ʿ�. �ٸ��� ������ ���..?
		}
		system("cls");

	}
}

int main_menu() {
	int num;

	//�����ʿ�
	//������ȣ ���ڸ� ���Ƿ� �������
	printf("������ȣ ���ڸ��� �Է��ϼ���\n");
	printf("������ȣ: ");
	scanf("%d", &num);
	printf("\n");
	printf("=================================\n");
	printf("        ���� ��ȣ ����\n");
	printf("=================================\n");
	printf("\n");
	printf("������ ������ȣ�� �½��ϱ�? \n");
	printf("\n");
	printf("%d\n", num);
	printf("\n");
	printf("1. ��			2. �ƴϿ�\n");
	printf("\n");
	printf("\n");

	int menu;
	scanf("%d", &menu);
	printf("\n");
	return menu;
}