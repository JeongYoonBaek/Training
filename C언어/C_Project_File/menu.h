#ifndef __MENU_H__		
#define __MENU_H__
#include <stdio.h>
#include "file.h"
typedef enum {
	MAIN_CAR_NUM = '1',		//������ȣ��ȸ �޴�												
	MAIN_PAYMENT 			//���� �޴�


} MAIN_MENU;

extern int main_menu();				//extern �ܺο� �����ֵ��� �ϴ� ���, �Ⱥٿ�����
void show_title();
int insert_carnum(PARKING car);
void insert_exit_time();
void pay(PARKING CAR);
void receipt(PARKING car);
void show_ent_time(PARKING car);
void cal_fee(PARKING car);
#endif