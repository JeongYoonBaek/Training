#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main()
{
	int dan = 0, num = 1;
	printf("구구단 입력:");
	scanf("%d", &dan);
	while (num<10)
	{
		printf("%d*%d=%d \n", dan, num, dan * num);
		num++;
	}
	printf("프로그램 종료\n");
}