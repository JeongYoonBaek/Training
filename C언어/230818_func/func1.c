#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 유형1 전달인자 있고 반환 값 있다.

void greeting(); // main 함수 아래에 정의가 있다는 것을 알려줌 (컴파일에게)

int main() // 메인함수 (반드시 1개만 존재)
{
	 greeting(); // greeting 함수 정의를 호출함
	 printf("main함수의 다른 동작\n");
	 greeting(); // 함수의 호출은 다른 함수 정의에서 가능
}
// >>>>>> 중요! <<<<<<
// 함수의 정의는 실행되지 못함 
// -> 사용하기 위해서는 다른 함수에서 해당 함수 호출이 필요
void greeting() // 내가 만든 함수의 정의
{
	 printf(">>>> 함수시작 <<<<\n");
	 printf("안녕하세요\n");
	 printf("반갑습니다\n");
	 printf(">>>> 함수종료 <<<<\n");
}

void greeting2() // 함수의 정의2 
{
	 greeting(); // 함수의 호출은 다른 함수 정의에서 가능
}