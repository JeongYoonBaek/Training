#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#incluede <stdlib.h> // exit() 실행
    //printf("잘못된 국어 점수 입력!\n");
	//exit(0); // 프로그램 강제 종료 또는 return 0;


void sub(int kor, int eng, int math);
int main()
{
	//1. 점수 입력은 main()에서 입력 받음.
	//2. 입력 받는 점수는 0~100 사이의 숫자만 입력받도록 조건 체크
	// -> 간단하게 한번만 체크하면 됨 (사용자가 실수로 잘못 입력하면
	// 에러메시지 출력하고 종료 처리)
	//3. 국,영,수 점수를 각각의 매개변수로 전달하여 총점, 평균값을
	// 출력하는 메쏘드 작성.
	//4. 조건3까지 테스트 완료 이후에 잘못 입력한 값 체크를 확장하기
	// 실수로 입력하면 재입력 받을 수 있도록 처리

	int kor, eng, math;
	int add = 0;  int avg = 0;

	do
	{
		printf("국어 점수 입력:\n");
		scanf("%d", &kor);
	} while (kor < 0 || kor > 100);

	do
	{
		printf("영어 점수 입력:\n");
		scanf("%d", &eng);
	} while (eng < 0 || eng > 100);

	do
	{
	    printf("수학 점수 입력:\n");
	    scanf("%d", &math);
    }while (math < 0 || math > 100);
		sub(kor, eng, math);
	}

void sub(int kor, int eng, int math)
{
	int add = kor + eng + math;
	int avg = (add) / 3;
	printf("총점:%d\n", add);
	printf("평균점수:%d\n", avg);
}