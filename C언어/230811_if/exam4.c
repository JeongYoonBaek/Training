#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// 1) 3���� ���ڸ� �Է¹޾Ƽ� Ȧ��, ¦�� �����ϱ�
	// ����1) �ݺ����� ����ؼ� �Է¹ޱ�.

	/*for (int i = 0; i < 3; i++) {
		printf("���� %d�� �Է��ϼ���:", i + 1);
		int n;
		scanf("%d", &n);
		if (n % 2 == 0) {
			printf("%d�� ¦���Դϴ�\n", n);
		}
		else {
			printf("%d�� Ȧ���Դϴ�\n", n);
		}
	}
}*/




// 2) 1~100 ������ �����߿��� 5�� ����� ����ϱ�.
// ����1) �ݺ��� for,while ����ϱ�

	int i = 1;
	while (i <= 100) //�񱳿�����
	{
		printf(" %d", i);
		i++;
	}
	printf("\n===================================\n");
	for (int i = 1; i <= 100; i++) {
		if (i % 5 == 0) { // 5�� ��� ����ϱ�
			printf(" %d", i);
		}
	}
}