#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num;
	printf("Start! ");
	   //      ①         ②       ④
	for(int num = 1; num < 20; num++) {
	      //          && : -이거나 (동시에) 
	if (num % 2 == 0 || num % 3 == 0){ // 2로 나눈 나머지0, 3으로 나눈 나머지 0
	// if (num % 2 == 0 && num % 3 == 0){ 2의 배수이자 동시에 3의 배수 : 6
		continue;
	}// 조건확인 : 반복문 무시하지 않고 조건 확인하러 다시 위로 올라감
	printf("%d", num); // 11 - 15 ③
	}
	printf("End! \n");
	}



