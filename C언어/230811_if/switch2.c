#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c;
	printf("A ~ E ���� �Է�:"); // 1���� 5����
	scanf("%c", &c);
	switch (c) 
	{
	case 'A': // case�� ���������� ������ ������ ���·� �ۼ�
		printf("A�� ONE \n"); break;
	case 'B':
		printf("B�� TWO \n"); break;
	case 'C':
		printf("C�� THREE \n"); break;
	case 'D':
		printf("D�� FOUR \n"); break;
	case 'E':
		printf("E�� FIVE \n"); break;
	Default:  // ���� ����
		printf("I don't Know! \n");
	}
}
