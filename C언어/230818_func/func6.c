#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 호출, 매개변수, Return 값
int Add(int num1,int num2)
{
	return num1 + num2;
}
void ShowAddResult(int num) // 인자전달 O, 반환 값 X
{
	printf("덧셈결과 출력: %d \n", num);
}
int ReadNum() // 인자전달 X, 반환 값 O
{
	int num;
	scanf("%d", &num);
	return num;
}
void HowToUseThisProg()  // 인자전달 X 반환 값 X
{
	printf("두 개의 정수를 입력하시면 덧셈결과가 출력됩니다. : \n");
	printf("자! 그럼 두 개의 정수를 입력하세요. \n");
}
int main(void)
{
	int result, num1, num2;
	HowToUseThisProg();
	num1 = ReadNum();
	num2 = ReadNum();
	result = Add(num1, num2);
	ShowAddResult(result);
	return 0;
}