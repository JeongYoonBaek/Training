#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void change_num(int n);

int main()
{
	// 2���� ����(a,b)�� �����Ѵ�.
	// a�� b�� ���� ����غ���.
	// a�� b�� ���� ���� �ٲ� �� �� ����غ���. // ������ 
	// a�� b�� ���� �ٲ��ִ� �Լ��� �����.
	// �Լ��� ���Ͽ� ���� �ٲ� �� �� ����� ����Ѵ�.

	int a = 100;
	int b = 200;
	
	printf("a= %d \n", a);
	printf("b= %d \n", b);

	int temp = a;
	a = b;
	b = temp;

	printf("a= %d \n", a);
	printf("b= %d \n", b);

		return 0;
}

void change_num(int n)
{


}