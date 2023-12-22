#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// 파일 오픈
	// 파일 오픈, 파일(읽기, 쓰기), 닫기
	// 쓰기) 1. 파일오픈 2. 파일쓰기 3. 파일 닫기
	// 읽기) 1. 파일오픈 2. 파일읽기 3. 파일 닫기
	

	// 1. 파일 오픈 wt: 쓰기, text (쓰기 모드)
	// w: 기존의 내용을 무시하고 덮어씀 (기존 삭제)
	// a: 기존의 내용을 보존하고 뒤에 붙여씀.
	// r: 파일의 내용을 읽어옴

	// 쓰기모드는 w,a
	FILE * fp = fopen("data.txt", "at"); // 매개변수 2개 (텍스트파일, 붙여쓰기)
	// C:/ 바로 밑에는 관리자 권한으로 인해 생성X
	// C:/ 폴더에는 생성 가능

	if (fp == NULL) {
		printf("파일오픈 실패!");
		return -1; // exit(0);
    }
	fputc('B', fp); // fputc :문자 1개를 파일에 입력
	fputc('C', fp);
	fputc('D', fp);
	fclose(fp); // open이 나왔으면 close가 나와야함.
	return 0;
}