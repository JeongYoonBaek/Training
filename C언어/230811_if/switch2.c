#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c;
	printf("A ~ E 문자 입력:"); // 1부터 5사이
	scanf("%c", &c);
	switch (c) 
	{
	case 'A': // case도 마찬가지로 동일한 데이터 형태로 작성
		printf("A은 ONE \n"); break;
	case 'B':
		printf("B는 TWO \n"); break;
	case 'C':
		printf("C은 THREE \n"); break;
	case 'D':
		printf("D는 FOUR \n"); break;
	case 'E':
		printf("E는 FIVE \n"); break;
	Default:  // 생략 가능
		printf("I don't Know! \n");
	}
}
