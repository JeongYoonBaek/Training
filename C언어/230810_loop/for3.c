#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main()
{

	for (int cur = 2; cur < 10; cur++)
	{
		for (int is = 1; is < 10; is++) {
			printf("%d*%d=%d\n", cur, is, cur * is);
			printf("\n");
		}
	}
}