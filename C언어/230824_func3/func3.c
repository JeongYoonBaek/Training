#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()
#include <time.h> // time()


// if, �ݺ���, �迭 Ȱ��
int main()
{
	// 5���� ������ ������ �����ϰ� ���� (0~100)
	int score[5][3] = { 0 };
	srand(time(NULL));
	// �����ϰ� �߻��� ���ڸ� 5���� �л����� (5x3�迭)���� ����
	for (int i = 0; i < 5; i++) { // 5��
		for (int j = 0; j < 3; j++) { // 3��
			score[i][j] = (rand() % 101); // 100������ ���(������ ������)
			printf("score[%d][%d]=%d\t", i, j, score[i][j]);
			// ���� ��� ���� ���
			int add = 0; int avg = 0;
			add = add + score[i][j]; // add += score[i][j]
			printf("����:%d\t ���%d\t", add, add / 3);
			add = 0; // ���� ���� ����
			printf("\n");
			avg = (add) / 3;

	    if (avg >= 90 && avg <= 100) {
		    printf("����:%d => A����\n", add);
			}
		else if (avg >= 80 && avg <= 89) {
			printf("����:%d => B����\n", add);
			}
		else if (avg >= 70 && avg <= 79) {
			printf("����:%d => C����\n", add);
			}
		else if (avg >= 60 && avg <= 69) {
			printf("����:%d => D����\n", add);
			}
		else if (avg >= 50 && avg <= 59) {
			printf("����:%d => E����\n", add);
			}
		else {	
		    printf("����:%d => F����\n", add);
			}
		}
	}
}
