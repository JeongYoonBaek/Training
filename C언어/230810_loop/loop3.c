#define _CRT_SECURE_NO_WARNINGS // �����޼��� ��ó���� 
#include <stdio.h>

int main()
{
	int gugu = 2;
	int dan = 0;

	while (gugu < 10)
	{
		dan = 1;
		while (dan < 10)
		{
			printf("%d*%d=%d \n", gugu, dan, gugu * dan);
			dan++;
		}
		gugu++;
	}
}