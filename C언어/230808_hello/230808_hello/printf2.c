#include <stdio.h>

int main(void)
{
	printf("My age: %d\n", 27);
	printf("%d is my point \n", 100);
	printf("Good \nmorning \neverybody\n");
	// 정보: 숫자(정수, 실수), 문자(문자, 문자열)
	// 정수: %d, 실수: %f, 문자:%c, 문자열:%s
	// >> 자리수 표현, 기타 정보 표현등은 외울 필요가 X <<
	// 실무에서는 인터넷으로 찾아서 처리
	printf("실수표시:%.2f\n", 3.14); // 소수점 2자리까지만 표시
	printf("문자표시: % c\n", 'A'); // 주의:문자(''), 문자열("")
	printf("문자열:%s\n", "홍길동");
	return 0;
	// 알고리즘 : 남의 것을 베끼는건 도움이 안됨

	
}