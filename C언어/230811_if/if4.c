#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum = 0, num = 0;

	while (1) // ���ѷ��� (���ѹݺ�)
	{
		sum += num;
		if (sum > 5000) { // ** �������̸� �򰥸� �� ������ �߰�ȣ ���� ���� ���� �� **
			break; // �ڽ��� ���� �ݺ������� Ż��
		}
		num++;
	}
	printf("sum: %d\n", sum); // dead code ���ѹݺ��� ������ ������ �ʴ� �ڵ�
	printf("num: %d\n", num); // dead code ���ѹݺ��� ������ ������ �ʴ� �ڵ�
}
