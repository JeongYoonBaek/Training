#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ch, i;
	FILE* fp = fopen("data.txt", "rt");
	if (fp == NULL) {
		printf("파일오픈 실패!");
		return -1;
	}
	for (i = 0; i < 3; i++) {
		ch = fgetc(fp); // fp로부터 하나의 문자를 읽어서 변수 ch에 저장하기
		printf("%c \n", ch);
	}
	fclose(fp);
	return 0;
}