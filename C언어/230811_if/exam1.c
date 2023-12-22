#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// 관계연산자, 논리연산자가 if문의 조건으로 많이 사용

	// 연습1.
	// 1개의 숫자를 입력받아서 짝수, 홀수인지 체크하는 프로그램 작성
	// 나머지 연산자 활용 
/*
	 printf("숫자 입력)
	 int num; // 정수형 변수 선언(생성)
	 scanf(%d,&num);
	 if ( n % 2 != 0) { // <, <=, ==, !=, &&, ||
	 printf("입력받은 %는 홀수\n);

	 else if ( n % 2 == 0){
		  printf("입력받은 %는 짝수\n);
		  }*/

		  // 연습2
		  // 2개의 숫자를 입력받아서 크다, 작다, 같다를 체크하는 프로그램

	  //int num;
	  //printf("정수 입력: ");
	  //scanf("%d", &num);
	  //
	  //if (num > 5) {
	  //	printf("입력값은 5보다 크다.\n");
	  //}
	  //else if (num < 5) {
	  //	printf("입력 값은 5보다 작다.\n");
	  //}
	  //else if (num = 5) {
	  //	printf("입력 값은 5와 같다.\n");
	  //}
	  //printf("정수 입력: ");
	  //scanf("%d", &num);
	  //
	  //if (num > 5) {
	  //	printf("입력값은 5보다 크다.\n");
	  //}
	  //else if (num < 5) {
	  //	printf("입력 값은 5보다 작다.\n");
	  //}
	  //else if (num = 5) {
	  //	printf("입력 값은 5와 같다.\n");
	  //}
	  //}


		  // 연습3 
		  // 국어, 영어, 수학 점수를 입력받아서 총점, 평균, 학점을 구하는 프로그램
		  // 학점: 100~90:A학점, 89~80:B학점, 79~70:C학점, 69~60:D학점, 59~0:F학점
		  // A,B,C,D,F학점
		  // if (90 <= num <=100) -> (num >=90 && num <=100) 

	int kor; int eng; int math;
	double add = 0; double avg = 0;
	char grade = 0;

	printf("국어 점수를 입력하세요:\n");
	scanf("%d", &kor);
	printf("영어 점수를 입력하세요:\n");
	scanf("%d", &eng);
	printf("수학 점수를 입력하세요:\n");
	scanf("%d", &math);

	add = kor + eng + math;
	avg = add / 3;
	if (avg >= 90 && avg <= 100) { // 논리 연산자 사용 ~와 ~사이  90~100점 사이
		// 비교 할 대상을 왼쪽 그리고 정보는 오른쪽에 작성
		printf("총점:%d, 평균:%d => A학점\n", add, avg);
	}
	else if (avg >= 80 && avg <= 90) { // 80~90점 사이
		printf("총점:%d, 평균:%d => B학점\n", add, avg);
	}
	else if (avg >= 70 && avg <= 80) {// 70~80점 사이
		printf("총점:%d, 평균:%d => C학점\n", add, avg);
	}
	else if (avg >= 60 && avg <= 70) { // 60~70점 사이
		printf("총점:%d, 평균:%d => D학점\n", add, avg);
	}
	else { // 59 ~ 0
		printf("총점:%d, 평균:%d => F학점\n", add, avg);
	}
}