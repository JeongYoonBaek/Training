#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy ���ڿ� ó�� ���� 

struct point
{
	int xpos; // x��ǥ
	int ypos; // y��ǥ
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
	struct person man = { "�̽±�", "010-1212-0001", 21 };
	           // man : ����ü ���Ǹ� ����Ͽ� ����ü ���� ����
	printf("%d %d \n", pos.xpos, pos.ypos);
	printf("%s %s %d \n", man.name, man.phoneNum, man.age);
	return 0;
}