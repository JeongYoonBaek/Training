#ifndef __MENU_H__
#define __MENU_H__

typedef enum {
	MAIN_RAND_INS = 1,	// ���� ���� �޴�
	MAIN_DIR_INS,		// ���� �Է� �޴�
	MAIN_ALL_DEL,		// ��ü ����
	MAIN_VIEW,			// ��ü ����
	MAIN_SEARCH,		// �˻�
	MAIN_DELETE,		// ����
	MAIN_UPDATE,		// ����
	MAIN_EXIT			// ����
} MAIN_MENU;

extern int main_menu();
extern int search_menu();

#endif