#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	printf("Start! ");
	   //      ��         ��       ��
	for(int num = 1; num < 20; num++) {
	      //          && : -�̰ų� (���ÿ�) 
	if (num % 2 == 0 || num % 3 == 0){ // 2�� ���� ������0, 3���� ���� ������ 0
	// if (num % 2 == 0 && num % 3 == 0){ 2�� ������� ���ÿ� 3�� ��� : 6
		continue;
	}// ����Ȯ�� : �ݺ��� �������� �ʰ� ���� Ȯ���Ϸ� �ٽ� ���� �ö�
	printf("%d", num); // 11 - 15 ��
	}
	printf("End! \n");
	}



