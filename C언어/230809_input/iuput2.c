#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main(void)
{
    int result;
    int num1, num2, num3, num4, num5;// 일반변수 : 재사용 가능
    
    printf("5일간 교통비입력: ");
    scanf("%d", &num1);
    printf("5일간 교통비입력: ");
    scanf("%d", &num2);
    printf("5일간 교통비입력: ");
    scanf("%d", &num3);
    printf("5일간 교통비입력: ");
    scanf("%d", &num4);
    printf("5일간 교통비입력: ");
    scanf("%d", &num5);
    result = num1 + num2 + num3 + num4 + num5;

    printf("%d + %d + %d + %d + %d = %d원\n", num1, num2, num3, num4, num5, result);

    //상수변수: const가 변수 앞에 붙음. (재사용 불가)
    // const int n = 100;
    // int n2 = 200;
    // n2 = 300; // 일반변수는 값을 변경 가능
    // n = 500;
}