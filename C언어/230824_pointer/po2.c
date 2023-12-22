#include <stdio.h>

int main()
{
	int num1 = 100, num2 = 100;
	int* pnum = NULL; // NULL : 값을 모른다 또는 없다 (포인트변수 초기화)

	pnum=&num1;
	(*pnum) += 30; // 130

	pnum=&num2;
	(*pnum) -= 30; // (*pnum) = (*pnum) - 30;

	printf("num1:%d, num2:%d \n", num1, num2);
	return 0;
}
