// loop1.c
#define _CRT_SECURE_NO_WARNINGS // 오류메세지 전처리기 
#include <stdio.h>

int main()
{
    int num = 0;
    while (num < 100) {
        printf("Hello world! %d\n", num);
        num++;
    }
}