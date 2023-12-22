#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main()
{
	int total = 0, num = 0;
	do
	{
		printf("정수 입력(0 to quit):");
		scanf("%d", &num);
		total += num;
	}while (num != 0);
	printf("합계: %d\n", total);
}