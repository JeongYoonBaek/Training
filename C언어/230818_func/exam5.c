#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void gugudan(int n);

int main()
{
	// 1. �������� ����ϴ� ���ڸ� main���� �Է� ����.
	// 2. ��) 3�� �Է¹޾� �Ű������� �����ϸ� 3�� ���
	// 3. �Է¹��� ���ڸ� �Ű������� �����Ͽ� ������ ���

	int n;
	printf("���� �Է�:");
	scanf("%d", &n);
	gugudan(n);
}

void gugudan(int n)
{
	for (int n2 = 1; n2 < 10; n2++) {
		printf("%d* %d =%d\n", n, n2, n*n2);
	}
}
