#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main()
{

	// 조건1 동전은 각각 500원, 100원 50원과 10원 사용
	// 조건2 동전의 각각의 갯수를 저장할 변수들을 만들고 초기값 0으로 설정
	// 조건3 특정 금액의 지폐를 입력 받으세요 (예:1370)
	// 조건4 지폐를 500원 동전 갯수 구함.
	// 조건5 나머지 금액이 있으면 100원 동전 갯수 구함
	// 조건6 나머지 금액이 있으면 50원 동전 갯수 구함
	// 조건7 나머지 금액이 있으면 10원 동전 갯수 구함
	// 조건8 반드시 아래와 같은 형태로 출력하기 바람.


	/*
	----------------------------------------
	       동전 교환기 프로그램 v1.0
    ----------------------------------------
	       오백원 갯수 : ? 개
		   백원 갯수 : ? 개
		   오십원 갯수 : ? 개
		   십원 갯수 : ? 개
		   바꾸지 못한 잔돈 : ? 개
	----------------------------------------
	*/
	// 디버깅 - 1. 오류를 해결하는 과정 2. 변수를 추적
	printf("------------------------------\n");
	printf("동전 교환기 프로그램 v1.0\n");
	printf("------------------------------\n");
	printf("금액을 투입하세요:");

	int coin500 = 0; // 500원 동전 개수
	int coin100 = 0; 
	int coin50 = 0; 
	int coin10 = 0; 
	int in_money = 0; // 입력받는 금액

	scanf("%d", &in_money);
	coin500 = in_money / 500; // 500으로 나눈 몫(개수)
	// 디버깅 작업 (coin500 변수에 들어있는 값을 확인)
	printf("오백원 갯수 : %d\n", coin500); // 나머지를 구하는 작업
	int lstmoney = 0;
	lstmoney = lstmoney % 500;
	printf("오백원 남은 갯수 :%d\n", lstmoney); //디버깅
	coin100 = in_money / 100;
	printf("백원 갯수: %d\n", coin100);
	lstmoney = lstmoney % 100;
	printf("백원 남은 갯수: %d\n", lstmoney);
	coin50 = in_money / 50; 
	printf("오십원 갯수: %d\n", coin50);
	lstmoney = lstmoney % 50;
	printf("오십원 남은 갯수:%d\n", lstmoney);
	coin10 = in_money / 10;
	printf("십원 갯수: %d\n", coin10);
	lstmoney = lstmoney / 10;
	printf("십원 남은 갯수: %d\n", lstmoney);
	lstmoney = lstmoney % 10;
	printf("바꾸지 못한 잔돈: %d\n", lstmoney);
}