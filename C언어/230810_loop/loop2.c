#define _CRT_SECURE_NO_WARNINGS // �����޼��� ��ó���� 
#include <stdio.h>

int main()
{
	int dan = 0, num = 1;
	printf("������ �Է�:");
	scanf("%d", &dan);
	while (num<10)
	{
		printf("%d*%d=%d \n", dan, num, dan * num);
		num++;
	}
	printf("���α׷� ����\n");
}