#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()
#include <time.h> // time()

void hap_func(int score[5][3]);
void avg_func(int hap);
char grade_func(int avg);
// if, �ݺ���, �迭 Ȱ��
int main()
{   
	// ����ü(Ŭ������ ���)�� ����Ͽ� ó���ϴ� ���� �� ȿ�����̴�.
	// 5���� ������ ������ �����ϰ� ���� (0~100)
	int score[5][3] = { 0 };
	srand(time(NULL));
	// �����ϰ� �߻��� ���ڸ� 5���� �л����� (5x3�迭)���� ����
	// 1. ����� ���ϴ� �Լ� 
	// 2. ������ ���ϴ� �Լ�
	// 3. ������ ���ϴ� �Լ� 
	int hap = 0;
	int avg = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			score[i][j] = (rand() % 101);
			printf("score[%d][%d]=%d\t", i, j, score[i][j]);
			       // ���� ��� ���� ���
			hap = hap + score[i][j]; // add += score[i][j]
		} // ���� ������ ��ġ
		avg = hap / 3; // avg = avg_func(hap);
		printf("����:%d\t ���:%d\t", hap, avg);
		printf("%c����\t", grade_func(avg));
		hap = 0; // ���� ���� ����
		printf("\n");
	} 
}

void hap_func(int score[5][3])
{   
	// ���� ���ϴ� �Լ��� ������� �ʴ� ���� ȿ�����̴�.
	int hap = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			score[i][j] = (rand() % 101);
			hap = hap + score[i][j];
			printf("score[%d][%d]=%d\t", i, j, score[i][j]);
		}
	}
}

void avg_func(int hap, int avg)
{
	avg = hap / 3;
	printf("����:%d\t ���:%d\t", hap, avg);
	hap = 0; // ���� ���� ����
}

char grade_func(int avg) // A,B,C,D,E,F ���ڿ� ����� ���� char ��� 
{
	    char grade = '0';
		if (avg >= 90 && avg <= 100) {
			grade = 'A';
		}
		else if (avg >= 80 && avg <= 89) {
			grade = 'B';
		}
		else if (avg >= 70 && avg <= 79) {
			grade = 'C';
		}
		else if (avg >= 60 && avg <= 69) {
			grade = 'D';
		}
		else if (avg >= 50 && avg <= 59) {
			grade = 'E';
		}
		else {
			grade = 'F';
		}
		return grade;
}
