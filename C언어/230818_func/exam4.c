#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_num(int n1, int n2, char a);
int main()
{
	// 1) ���� 2���� ��Ģ ������(+,-,x,/)�� main()���� �Է¹���.
	// 2) ��Ģ�����ڴ� ���ڷ� �Է¹���. (+,-,x,/) // 100���� �����Է�
	// 3) 3���� ������ �Ű������� �Ѳ����� ����
	// 4) ��� ������� �����Ͽ� main()���� ����ϱ� (void ���x)

	// scanf���� �����Է� �� ���� �Է½ÿ��� " %c" ���

	int n1, n2 = 0;
	char a;
	printf("ù��° ���ڸ� �Է��ϼ���:");
	scanf("%d", &n1);
	printf("�ι�° ���ڸ� �Է��ϼ���:");
	scanf("%d", &n2);
	printf("��Ģ�����ڸ� �Է��ϼ���:");
	scanf(" %c", &a);
	int result = my_num(n1, n2, a);
	printf("�����: %d\n", result);
}

int my_num(int n1, int n2, char a)
{
	int result= 0;
	if (a == '+') {
		return n1 + n2; // a+b ���� �����ϸ鼭 calc �Լ��� ����
	}
	if (a == '-') {
		result = n1 - n2;
	}
	if (a == 'x') {
		result = n1 * n2;
	}
	if (a == '/') {
		result = n1 / n2;
	}
	return result;
}