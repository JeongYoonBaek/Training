#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int n1, int n2); // ������Ÿ�� ����
int sub(int n1, int n2);

void main()
{
	// ���ϰ��� ������Ÿ�� �Լ���(�Ű�����, ...)
	int n1 = 200; // ��������
	int n2 = 50;
	int a = add(n1, n2);
	printf("���Ϲ��� add �Լ���:%d\n", a);
	int s = sub(n1, n2);
	printf("���Ϲ��� sub �Լ���:%d\n", s);
	printf("���Ϲ��� sub �Լ���2:%d\n", sub(n1, n2));

	// add()�Լ� ȣ���ؼ� ���ϰ��� main���� ���
    // sub()�Լ� ȣ���ؼ� ���ϰ��� main���� ���
}

int add(int n1, int n2) // �Լ� ���Ǵ� �� ������ 
                        // -> ȣ�������� ���� ä����
{
	return n1 + n2;
}

int sub(int n1, int n2)
{
	int res = n1 - n2;
	return res;
}