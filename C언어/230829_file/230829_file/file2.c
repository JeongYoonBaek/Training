#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ch, i;
	FILE* fp = fopen("data.txt", "rt");
	if (fp == NULL) {
		printf("���Ͽ��� ����!");
		return -1;
	}
	for (i = 0; i < 3; i++) {
		ch = fgetc(fp); // fp�κ��� �ϳ��� ���ڸ� �о ���� ch�� �����ϱ�
		printf("%c \n", ch);
	}
	fclose(fp);
	return 0;
}