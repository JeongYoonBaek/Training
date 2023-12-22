#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct fren // 구조체 타입
{
	char name[10];
	char sex;
	int age;
} Friend; // 구조체 정의

int main()
{
	FILE* fp;
	Friend myfren1;
	Friend myfren2;
	
    /*** 파일 쓰기 ***/
	// 구조체는 보통 바이너리 형태를 많이 씀
	fp = fopen("friend.bin", "wb"); // 2진 파일형태 
	printf("이름, 성별, 나이 순 입력: ");
	scanf("%s %c %d", myfren1.name, &myfren1.sex, &myfren1.age);
	fwrite(&myfren1, sizeof(myfren1), 1, fp);
	      // 주소값 (포인터 변수)
	fclose(fp);

	/*** 파일 읽기 ***/
	fp = fopen("friend.bin", "rb");
	fread(&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);

}
 