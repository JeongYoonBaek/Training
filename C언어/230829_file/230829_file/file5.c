#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	FILE* src = fopen("src.txt", "rt");
	FILE* des = fopen("dst.txt", "wt");
	int ch;
	if (src == NULL || des == NULL);{
	puts("파일오픈 실패!");
	return -1;
}
	while ((ch = fgetc(src)) != EOF) {
		// 파일의 처음부터 끝까지 문자 1개씩 읽고나서 des에 넘김
		fputc(ch, des);
	}
	// 파일의 끝에 도달했다면
	if (feof(src) != 0) {
		puts("파일복사 완료!");
	}
	else {
		puts("파일복사 실패!");
		fclose(src);
		fclose(des);
	}
}
  