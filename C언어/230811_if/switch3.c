#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char sel;
	printf("M 오전, A 오후, E 저녁 \n");
	printf("입력: ");
	scanf("%c", &sel);

	switch (sel) // 동일한 문자형태 입력 
	{
	case'M': case'm': // 동일 라인에 두 케이스 입력 표시 
		printf("Morning \n");
		break;
	case'A': case'a': 
		printf("Afternoon \n");
		break;
	case'E': case'e':
		printf("Evening \n");
		break; // 사실 불필요한 break문!
	}
}
