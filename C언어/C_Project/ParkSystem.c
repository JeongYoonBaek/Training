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

	printf("------------------------\n");
	printf("���� ��� ����� \n");
	printf("------------------------\n");   // ���� ��� ����� Ʋ �ۼ�	
	printf("������ȣ %d\n");
	printf("------------------------\n");

	srand(time(NULL));
	int ent_hour[2] = { 0 };
	int ent_min[2] = { 0 };
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			ent_hour[i] = (rand() % 14) + 06; // �ð� ���� ���� ���� �Է� �ޱ� (06��~21�ñ��� �̿밡��)
			ent_min[j] = (rand() % 59); // �� ���� ���� ���� �Է� �ޱ� 
			printf("���� �ð�: %d�� %d�� \t", ent_hour[i], ent_min[j]);
			printf("\n");
		}
	}
	int exit_hour[2] = { 0 };
	int exit_min[2] = { 0 };
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			exit_hour[i] = (rand() %   +(ent_hour[i]))+1;
			exit_min[j] = (rand() % 59 +(ent_min[j]));
			printf("���� �ð�: %d�� %d�� \t ", exit_hour[i], exit_min[j]);
			printf("\n");

		}
	}
	int money = 0;

}