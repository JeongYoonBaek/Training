#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum = 0, num = 0;

	while (1) // 무한루프 (무한반복)
	{
		sum += num;
		if (sum > 5000) { // ** 가급적이면 헷갈릴 수 있으니 중괄호 쓰는 습관 들일 것 **
			break; // 자신이 속한 반복문에만 탈출
		}
		num++;
	}
	printf("sum: %d\n", sum); // dead code 무한반복문 때문에 사용되지 않는 코드
	printf("num: %d\n", num); // dead code 무한반복문 때문에 사용되지 않는 코드
}
