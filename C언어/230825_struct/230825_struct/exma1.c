#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 
#include <stdlib.h>
#include <time.h> // time()
char show_hak(int avg);


struct exam // 1명의 성적 정보 구조체
{
    int kor; int eng; int math;
    int hap; int avg; char grade; char name[20]; // 틀은 하나에 대해 정의. 뒤에 값 입력x 
};

int main()
{
    // 학생 5명의 국,영,수 점수와 총점, 평균, 학점을 정의하는 구조체
    // 국영수 2차원 배열, 나머지 일반 변수
    // 1. 구조체를 정의하고 구조체 배열 변수선언
    char* name[5] = { "홍길동", "이순신", "유관순", "전우치", "김유신" };
    int s[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }; // s라는 점수 배열 정보를 입력 
    struct exam arr[100] = { 0 }; // 100명의 성적 관리  
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        strcpy(arr[i].name, s[rand() % 5]);
        printf("%d번째 학생 이름 => %s\t", arr[i].name);
        arr[i].kor = s[rand() % 10]; // s 배열 정보의 10개값 중 랜덤으로 출력 0~9 s[5]= % 6
        printf("%d번째 학생 국어점수 => %d\t", i + 1, arr[i].kor);
        arr[i].eng = s[rand() % 10];
        printf("%d번째 학생 영어점수 => %d\t", i + 1, arr[i].eng);
        arr[i].math = s[rand() % 10];
        printf("%d번째 학생 수학점수 => %d\t", i + 1, arr[i].math);
        int hap = arr[i].kor + arr[i].eng + arr[i].math;
        printf("%d번째 학생 총점 => %d\t", i + 1, hap);
        int avg = hap / 3;
        char grade;
        printf("%d번째 학생 평균 => %d\t", i + 1, avg);
        printf("%d번째 학생 학점 => %d\t", i + 1, grade);
        printf("\n");
    }
}

char show_hak(int avg)
{
    if (avg >= 90 && avg <= 100) {
        printf("A학점");
    }
    else if (avg >= 80 && avg <= 90) {
        printf("B학점");
    }
    else  if (avg >= 70 && avg <= 80) {
        printf("C학점");
    }
    else  if (avg >= 60 && avg <= 70) {
        printf("D학점");
        }
    else if (avg >= 50 &&  avg <= 60) {
        printf("E학점");
    }
    else {
        printf("F학점");
    }
}