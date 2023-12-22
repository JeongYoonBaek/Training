#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 스탠다드 라이브러리 srand()
#include <time.h> // time()


// if, 반복문, 배열 활용
int main()
{
	// 5명의 국영수 점수를 랜덤하게 생성 (0~100)
	int score[5][3] = { 0 };
	srand(time(NULL));
	// 랜덤하게 발생한 숫자를 5명의 학생에게 (5x3배열)에게 저장
	for (int i = 0; i < 5; i++) { // 5행
		for (int j = 0; j < 3; j++) { // 3열
			score[i][j] = (rand() % 101); // 100점까지 출력(나머지 연산자)
			printf("score[%d][%d]=%d\t", i, j, score[i][j]);
			// 총점 평균 학점 출력
			int add = 0; int avg = 0;
			add = add + score[i][j]; // add += score[i][j]
			printf("총점:%d\t 평균%d\t", add, add / 3);
			add = 0; // 총점 누적 방지
			printf("\n");
			avg = (add) / 3;

	    if (avg >= 90 && avg <= 100) {
		    printf("총점:%d => A학점\n", add);
			}
		else if (avg >= 80 && avg <= 89) {
			printf("총점:%d => B학점\n", add);
			}
		else if (avg >= 70 && avg <= 79) {
			printf("총점:%d => C학점\n", add);
			}
		else if (avg >= 60 && avg <= 69) {
			printf("총점:%d => D학점\n", add);
			}
		else if (avg >= 50 && avg <= 59) {
			printf("총점:%d => E학점\n", add);
			}
		else {	
		    printf("총점:%d => F학점\n", add);
			}
		}
	}
}
