#ifndef __MENU_H__
#define __MENU_H__

typedef enum {
	MAIN_RAND_INS = 1,	// 랜덤 생성 메뉴
	MAIN_DIR_INS,		// 직접 입력 메뉴
	MAIN_ALL_DEL,		// 전체 삭제
	MAIN_VIEW,			// 전체 보기
	MAIN_SEARCH,		// 검색
	MAIN_DELETE,		// 삭제
	MAIN_UPDATE,		// 수정
	MAIN_EXIT			// 종료
} MAIN_MENU;

extern int main_menu();
extern int search_menu();

#endif