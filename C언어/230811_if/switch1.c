#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	printf("1부터 5이하의 정수 입력:"); // 1부터 5사이
	scanf("%d", &num);
	switch (num) // 동일한 데이터 형태가 와야함 EX) 문자 - 문자
		{
	case 1:
		printf("1은 ONE \n");
		break;
	case 2:
		printf("2는 TWO \n");
		break;
	case 3:
		printf("3은 THREE \n");
		break;
	case 4:
		printf("4는 FOUR \n");
		break;
	case 5:
		printf("5는 FIVE \n");
		break;
	Default:  // 생략 가능
		printf("I don't Know! \n");
		}
	}
