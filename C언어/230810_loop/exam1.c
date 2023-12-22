#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main()
{
	// ★★★★★★★★★★★★★★★★★★★★★★★★★
	// 반복문: 특정한 문장을 반복적으로 실행

	// 디버깅 하는 습관 필수. 라인앞에 버튼 클릭하면 빨간 동그라미 생성
	// 밑에 코드 앞에 노란 화살표가 생기면 디버거 실행하고 코드 오류가 있으면 식별자 확인

	// for문
	// for (int i = 0; i < 100; i++) { // 100번 반복
	// ③printf("안녕하세요\n");
	// }


	// while문
	//  int ii = 0; // ①     
	//	while (ii < 3){ ②
	//③ printf("안녕하세요\n");
	//	ii++ ④          ii=ii+2 < 2씩 증가
	// }


	// 디버깅(debugging): 오류를 해결하는 과정

	// int j=0;
	// do {    먼저 한번은 실행하고 난 후 조건 체크   
	//     printf("do-while안녕하세요\n");
	//     pritnf("j:%d\n",j); // 로그를 확인 (디버깅)
	// j++ < 무한루프에 빠지지 않게 증감식 넣어준다
	// } while(j < 3); << do while문은 조건문이 뒤로 온다




	// 1) 1개의 숫자를 입력받아 구구단 출력하는 프로그램
	// ex) 3을 입력하면 구구단 3단 출력
	/*
	int dan = 0, num = 1;

	//scanf("%d", &dan);
	printf("숫자를 입력하세요:");

	while (num < 10)
	{
		printf("%d*%d = %d\n", dan, num, dan * num);
		num +=2;	// 홀수 나오기
	}
}
// for( int i =2; i<10; i=i+2){ // 짝수 나오기
// printf("%d*%d = %d\n, dan, num, dan*num);
// }
*/


// 2) 시작값과 마지막값을 입력받아 합 구하는 프로그램
// ex) 1번째 입력:2, 2번째 입력:5
// 2+3+4+5 = 14
// 조건) 만약에 2번째 수가 1번째 수보다 작거나 같으면 다시 입력.


	//in/*t fir, scd;
	/*printf("시작값 입력:");
	scanf("%d", &fir);
	int backup = fir;***/// // 첫번째 입력값을 백업해서 보존
	//printf("마지막값 입력:");
	//scanf("%d", &scd);
	//while (fir >= scd) {
	//	printf("마지막 숫자 재입력:");
	//scanf("%d", &scd);
	//}
	//do {
	//	printf("마지막 숫자 입력:");
	//	scanf("%d", &scd);
	//} while (fir >= scd);
	//    int total = 0;
	////  for (; fir <= scd; fir++) {
	//	for (int i = fir; i <= scd; i++) {
	//		total = total + i;
	//	}
	//	printf("%d~%d의 합: %d\n", fir, scd, total);
	//}

	// 3) 구구단 전체 출력
	// 2x1=2 3x1=3 4x1=4 ... 9x1=9
	// 2x2=4 3x2=6 4x2=8 ... 9x2=18
	// ...
	// 2x9=18 3x9=27 4x9=36 ... 9x9=81

	 // 행과 열의 개념은 반드시 2중 반복문에서 적용
	
	for (int i = 0; i < 3; i++) {
		printf("1행의 %d\t", i + 1);
	}
	printf("\n");
	// \t: tab 키 간격
	for (int i = 0; i < 3; i++) { // 행
		for (int j = 0; j < 2; j++) { // 열
			printf("%d행 %d열\t", i, j);
			
		}
		printf("\n");
	}
	// 구구단 출력
	

	for (int i = 1; i < 10; i++); { //1-9단 
		for (int j = 2; j < 10; j++); { // 단
			printf("%d* %d =%d\t", i, j, i * j);
		}
		printf("\n");
	
	}
}