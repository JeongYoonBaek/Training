#include <stdio.h>

int main()
{
    char* a = "백정윤";
    int b = 200;
    int c = 6489-7505;
    char d = "경북 구미시 송동로 105, 108동 808호";
    float e = 180.2;
    float f = 78.5;
    char g = 'O';

    printf("-------------------------\n");
    printf("   수강생 정보 확인서\n");
    printf("-------------------------\n");
    printf("이름:%s\n", a); // 문자열
    printf("나이:%d\n", b); // 정수
    printf("전화:010-%d%d\n", c); // 문자열
    printf("주소:%s\n", d); // 문자열
    printf("키:%.1fcm\n",e); // 실수
    printf("몸무게:%.1fkg\n", f); // 실수
    printf("혈액형:%c형\n", g); // 문자
    printf("-------------------------\n");
    
}