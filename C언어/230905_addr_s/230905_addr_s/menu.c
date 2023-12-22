#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h" // menu.c 와 menu.h 는 동일한 폴더에 존재

int main_menu()
{
	printf("=============================\n");
	printf("주소록 관리 프로그램 v1.0\n");
	printf("=============================\n");
	printf("1.주소록 자동 생성\n");
	printf("2.주소록 직접 입력\n");
	printf("3.주소록 전체 삭제\n");
	printf("4.주소록 보기\n");
	printf("5.주소록 검색\n");
	printf("6.주소록 삭제\n");
	printf("7.주소록 수정\n");
	printf("8.종료\n");
	printf("=============================\n");
	printf("메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

int search_menu()
{
	printf("=============================\n");
	printf("데이터 검색\n");
	printf("=============================\n");
	printf("1.이름 검색\n");
	printf("2.아이디 검색\n");
	printf("3.이메일 검색\n");
	printf("4.메인 메뉴\n");
	printf("=============================\n");
	printf("메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}