#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char* name[] = { "홍길동","김길동","박길동", "최길동" };
	FILE* fp = fopen("simple.txt", "wt");
	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}
	fputc('A', fp); // 데이터
	fputc('B', fp);
	fputs("My name is Yoon\n", fp); // 파일 포인터
	fputs("you are name is Yoon\n", fp);
	for (int i = 0; i < 4; i++) {
		fputs(name[i], fp); // 배열 변수값 집어넣기
		fputc('\n', fp);
	}
	fclose(fp);
}