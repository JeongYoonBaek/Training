#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[30];
	int ch;
	FILE* fp = fopen("simple.txt", "rt");
	if (fp == NULL); {
		puts("���Ͽ��� ����!");
		return -1;
	}
	while ((ch = fgetc(fp)) != EOF) {
		fgetc(ch, fp);
		printf("%c", ch);
	}
	/*while (1) {
	    ch = fgetc(fp);
	    if (ch == eof) break;
	    printf("%c", ch);
	    }*/
		fclose(fp);
}