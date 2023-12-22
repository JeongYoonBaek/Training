#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 

struct point
{
	int xpos; // x좌표
	int ypos; // y좌표
};

struct person
{
	char name[20];
	char phoneNum[20];
	int age;
};

int main(void)
{
	struct point pos = { 10, 20 };
	struct person man = { "이승기", "010-1212-0001", 21 };
	           // man : 구조체 정의를 사용하여 구조체 변수 선언
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);
	return 0;
}