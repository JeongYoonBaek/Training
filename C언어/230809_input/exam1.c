#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>
int main()
{
	// 1. 원주율 (PI)을 저장하는 실수형 상수 변수를 생성하고 값을 설정 (PI=3.14)
	// 2. 원의 반지름을 저장하는 실수형 변수를 생성하고 입력 받기.
	// 3. 원의 면적을 출력하기 (반지름 * 반지름 * PI = 원의 면적)

	const float PI = 3.14; // 상수형 변수 (대문자로 표시)
	float r;
	printf("원의 반지름 입력:");
		scanf("%f", &r);
	float area = r * r * PI;
	printf("원의면적:%f\n", area);

	// 1. 국영수과 정수형 변수 생성
	// 2. 국영수과 점수 입력 받기
	// 3. 모든 과목의 평균값과 총점을 저장할 변수를 생성
	// 4. 평균값과 총점을 출력

	int result;
	int kor;
	int eng;
	int math;
	int sci;
	int add = kor + eng + math + sci;
	int avg = kor + eng + math + sci / 4;

	printf("국어 점수 입력:%d\n", kor);
	scanf("%d", &kor);
	printf("영어 점수 입력:%d\n", eng);
	scanf("%d", &eng);
	printf("수학 점수 입력:%d\n", math);
	scanf("%d", &math);
	printf("과학 점수 입력:%d\n", sci);
	scanf("%d", &sci);
	result = kor + eng + math + sci;
	printf("총점:%d\n", add, result);
	result = kor + eng + math + sci / 4;
	printf("평균점수:%d\n", avg, result);

	// 1. 화씨온도를 저장하는 정수형 변수 생성
	// 2. 화씨 온도를 입력 받기.
	// 3. 섭씨 온도를 저장하는 실수형 변수 생성
	// 4. 화씨 온도를 섭씨 온도로 변환. 섭씨온도=(화씨온도 -32)/1.8
	// 5. 섭씨 온도를 출력

	int hwa;
		printf("화씨온도를 입력:℉\n");
	scanf("%d", &hwa);

	float sup = (hwa - 32) / 1.8;
	printf("섭씨온도:%F.1℃\n", &sup);
}