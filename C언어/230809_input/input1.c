#define _CRT_SECURE_NO_WARNINGS // �����޼��� ��ó���� 
#include <stdio.h>

int main(void)
{
	int result;
	int num1, num2;
	printf("���� one: ");
	scanf("%d", &num1); // �ڿ� \n ���x
	printf("���� two: ");
	scanf("%d", &num2);
    result = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, result);
	// �ֽ� ���־�Ʃ��������� scanf�� ���Ұ�.
	// scanf_s��� �Լ��� ��ü�Ǿ���.
	// ������ C��� ǥ���Լ��� scanf�� ����.
}