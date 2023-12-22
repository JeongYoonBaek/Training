#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a = 3;
int b = 5;

void swap()
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	printf("a= %d, b= %d\n", a, b);
	swap();
	printf("a= %d, b= %d\n", a, b);
	return 0;
}