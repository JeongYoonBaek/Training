#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void show_number(int n);
void show_number2(int n, int n2);

int main() 
{
	// void 함수명() -> (void: 생략가능)
	// void 함수명(매개변수, ...) 매개변수는 n개
	
	// 중요★ 반드시 매개변수가 있는 함수를 호출할 경우
	// !! ()안에 매개변수로 전달하는 값(변수)을 넣어줌!!
	show_number(100); // !!!! F12: 함수 바로 찾기 기능, 
	int n = 100; // 저장버튼 옆에 함수 뒤로탐색 앞으로 탐색 가능
	int n2 = 200;
	show_number2(n, n2);// show_number2(100, 200)와 같은 의미
 // int n = 200; 같은 함수 안에서는 동일한 이름의 변수 사용X
}

// 코딩 스타일
// 스네이크 방식: show_number -> (C언어 스타일) 단어와 단어를 언더바로 연결
// 카멜(낙타) 방식: showNumber -> 자바,자바스크립트(객체지향)
// 파스칼 방식: ShowNumber -> C++,C#(객체지향) 첫글자와 연결되는 글자가 대문자
void show_number(int n) // (int n) => 매개변수(인수, 인자)가 있는 함수 정의
{
	 int sum = n + 100;
	 printf("함수의 변수1 sum:%d\n", sum);
}
               // 15라인에 있는 변수들과 전혀 다른 변수들. 혼동X
void show_number2(int n, int n2) // (int n) => 매개변수가 있는 함수 정의
               // 매개변수 선언 꼭 순서대로 하기
{
	 int sum = n + n2;
	 printf("함수의 변수2 sum:%d\n", sum); 
	 // 지역변수(로컬변수) (중괄호 안에서 사용되는 변수)
}