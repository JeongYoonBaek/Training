#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 스탠다드 라이브러리 srand()
#include <time.h> // time()

void hap_func(int score[5][3]);
void avg_func(int hap);
char grade_func(int avg);
// if, 반복문, 배열 활용
int main()
{   
	// 구조체(클래스와 비슷)를 사용하여 처리하는 것이 더 효율적이다.
	// 5명의 국영수 점수를 랜덤하게 생성 (0~100)
	int score[5][3] = { 0 };
	srand(time(NULL));
	// 랜덤하게 발생한 숫자를 5명의 학생에게 (5x3배열)에게 저장
	// 1. 평균을 구하는 함수 
	// 2. 총점을 구하는 함수
	// 3. 학점을 구하는 함수 
	int hap = 0;
	int avg = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			score[i][j] = (rand() % 101);
			printf("score[%d][%d]=%d\t", i, j, score[i][j]);
			       // 총점 평균 학점 출력
			hap = hap + score[i][j]; // add += score[i][j]
		} // 열이 끝나는 위치
		avg = hap / 3; // avg = avg_func(hap);
		printf("총점:%d\t 평균:%d\t", hap, avg);
		printf("%c학점\t", grade_func(avg));
		hap = 0; // 총점 누적 방지
		printf("\n");
	} 
}

void hap_func(int score[5][3])
{   
	// 합을 구하는 함수는 사용하지 않는 것이 효율적이다.
	int hap = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			score[i][j] = (rand() % 101);
			hap = hap + score[i][j];
			printf("score[%d][%d]=%d\t", i, j, score[i][j]);
		}
	}
}

void avg_func(int hap, int avg)
{
	avg = hap / 3;
	printf("총점:%d\t 평균:%d\t", hap, avg);
	hap = 0; // 총점 누적 방지
}

char grade_func(int avg) // A,B,C,D,E,F 문자열 출력을 위해 char 사용 
{
	    char grade = '0';
		if (avg >= 90 && avg <= 100) {
			grade = 'A';
		}
		else if (avg >= 80 && avg <= 89) {
			grade = 'B';
		}
		else if (avg >= 70 && avg <= 79) {
			grade = 'C';
		}
		else if (avg >= 60 && avg <= 69) {
			grade = 'D';
		}
		else if (avg >= 50 && avg <= 59) {
			grade = 'E';
		}
		else {
			grade = 'F';
		}
		return grade;
}
