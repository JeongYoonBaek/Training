#define _CRT_SECURE_NO_WARNINGS // �����޼��� ��ó���� 
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