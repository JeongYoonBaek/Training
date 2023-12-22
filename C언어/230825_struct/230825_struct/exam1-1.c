// exam1.c
#include <stdio.h>
#include <stdlib.h>	// srand()
#include <time.h>	// time()
#include <string.h>

// 학생 점수 구조체
struct score {
	int kor;	// 국어
	int eng;	// 영어
	int math;	// 수학
	int hap;	// 총점
	int avg;	// 평균
	char hak;	// 학점
	char name[20];
};

int main()
{   
	char* name[5] = { "홍길동", "이순신", "유관순", "전우치", "김유신" };
	int s[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	struct score sc_arr[100] = { 0 };
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		strcpy(sc_arr[i].name, name[rand() % 5]);
		sc_arr[i].kor = s[rand() % 10];
		sc_arr[i].eng = s[rand() % 10];
		sc_arr[i].math = s[rand() % 10];

		printf(">>> %d번째 %s 학생점수 <<<\n", i + 1, sc_arr[i].name);
		printf("sc_arr[%d] 국어:%d\n", i + 1, sc_arr[i].kor);
		printf("sc_arr[%d] 영어:%d\n", i + 1, sc_arr[i].eng);
		printf("sc_arr[%d] 수학:%d\n", i + 1, sc_arr[i].math);
		printf("----------------------------\n");
	}
}
