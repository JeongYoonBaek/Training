#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct time { // ����ü�� �̿��Ͽ� �ð� ���� �����Ѵ�. 
	int hour, min;
};

int main() {
	struct time ent; // ���� �ð� ����ü
	struct time exit; // ���� �ð� ����ü
	int hour, min; // �ð�, �� ���� 

	srand(time(NULL));
	int ent_hour[2] = { 0 };
	int ent_min[2] = { 0 };
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			ent_hour[i] = (rand() % 14) + 06; // �ð� ���� ���� ���� �Է� �ޱ� (06��~21�ñ��� �̿밡��)
			ent_min[j] = (rand() % 59); // �� ���� ���� ���� �Է� �ޱ� 
			printf("���� �ð�: %d�� %d�� \t", ent_hour[i], ent_min[j]);
			printf("\n");

			printf("���� �ð��� �Է��ϼ��� =>  ");
			scanf("%d : %d", &exit.hour, &exit.min);
			hour = exit.hour - (ent_hour[0]);
			min = exit.min - (ent_min[0]);
			if (exit.min < ent_min[0]) {
				hour = (exit.hour - (ent_hour[0])) - 1;
				min = ((exit.min - ent_min[0])) + 60;
			}
			printf("�̿� �ð� : %d�ð� %d�� \n", hour, min);

			int car_num = 1234;
			int fee = 5000; // �̿� �ݾ� ����
			int cost = 0;   // ���� �ݾ� ����
			char str = "";

			printf("�̿� �ݾ� : %d��\n", fee); // �̿�ݾ� ���
			printf("�ݾ��� �����ϼ��� => ");   // �̿� �ݾ� ����
			scanf("%d", &cost);              // ������ �ݾ� �Է� 
			printf("�ݾ��� ���� �Ͽ����ϴ�.\n"); // ���������� �ݾ� �����Ͽ����� ���

			if (fee == cost) {  // �̿�ݾװ� ���� �ݾ��� ������ ���� �Ϸᰡ �Ǿ��ٴ� ���ǹ��� �ۼ�
				printf("������ �Ϸ� �Ǿ����ϴ�! �̿� ���ּż� �����մϴ� ^^\n");
			}
			else if (fee < cost) {  // ���� �ݾ��� �̿� �ݾ׺��� ���� �� �Ž����� �ݾ��� ���
				printf("�Ž����� %d���� �������� �̿� ���ּż� �����մϴ� ^^\n", cost - fee);
			}
			else if (fee > cost) { // ���� �ݾ��� ������ �� �ݾ��� �����ϴٴ� ������ ���
				printf("���� �ݾ��� ���� �մϴ�!");
			}
			else if (str) {
				printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է� ���ּ���\n");
			}
			else {
			}
			printf("------------------------------\n");
			printf("   ���� �̿� �ý��� ������\n");
			printf("------------------------------\n");
			printf("���� ��ȣ : %d \n", car_num);
			printf("���� �ð� : %d�� %d�� \n", ent_hour[i], ent_min[j]);
			printf("���� �ð� : %d�� %d�� \n", exit.hour, exit.min);
			printf("�̿� �ð� : %d�ð� %d��\n", hour, min);
			printf("���� �ݾ� : %d�� \n", fee);
			printf("------------------------------\n");
			printf("�̿� ���ּż� �����մϴ�\n");
			printf("------------------------------\n");
		}
	}
}