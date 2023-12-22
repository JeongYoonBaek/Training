#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	// 1) 간단한 계산기.
	// 1. 2개의 숫자를 입력받고, 문자 +,-,*,/를 입력받음.
	// 2. 출력 형태는 아래 참고.
	// 3. >>> 입력 예시 <<<
	// 1번째 숫자 입력:10
	// 2번째 숫자 입력:20
	// 연산자 입력(+,-,*,/): +


	// int n1, n2; // 2개의 숫자 변수
	// char op; // 1개의 연산자
	// // printf("1번째 숫자 입력:");
	// // scanf("%d", &n1);
	// printf("연산자 입력(+, -, *, /) \n");
	// scanf("%c", &op); 
	// 바로 위에서 숫자를 입력하고 엔터키를 치면 엔터키값이
	// op 변수에 자동으로 저장되어지는 오류 발생.
	// 해결 방법: " %c" -> %c앞에 공백을 1칸 둠.
	// >>> 출력 예시 <<<
	// 10 + 5 = 15
	// if, switch 사용 가능

	/*int num, num2;
	char op;
	double result;
	printf("1번째 숫자 입력 \n");
	scanf("%d", &num);
	printf("2번째 숫자 입력 \n");
	scanf("%d", &num2);
	printf("연산자 입력(+, -, *, /) \n");
	scanf(" %c", &op);

	if (op=='+') {
		printf("%d + %d = %d\n", num, num2, num + num2);

	}
	else if (op=='-') {
		printf("%d - %d = %d\n", num, num2, num - num2);

	}
	else if (op=='*') {
		printf("%d * %d = %d\n", num, num2, num * num2);

	}
	if (op=='/') {
		printf("%d / %d = %d\n", num, num2, num / num2);
	}
}
*/








// 2) 윤년 구분하는 프로그램 
// 1. 입력한 년도를 4로 나누면 나머지가 0이고, 100으로 // 비교연산자와 논리 연산자
// 나누면 0이 아님.
// 2. 입력한 년도를 400으로 나누면 나머지가 0 -> 윤년
// if만 가능
// 1번, 2번 조건 만족해도 윤년

//	int yrs;
//	printf("년도를 입력:");
//	scanf("%d", yrs);
//
//	if (yrs % 4 == 0 && yrs % 100 != 0); {
//		printf("%d는 윤년입니다 \n", yrs);
//	}
//	else if (yrs % 400 == 0); {
//		printf("%d는 윤년입니다 \n", yrs);
//	else {
//			printf("%d는 윤년이 아님 \n");
//		}
//		// 방법2 (yrs % 4 == 0 && yrs % 100 != 0) || (yrs % 400 == 0) {
//	}
//}