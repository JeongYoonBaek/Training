#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //sleep
#include "menu.h"
#include "file.h"
#include "data.h"
#include "ui.h"

int main() {
	char file[] = "parkingfee.bin";	//�����̸�
	srand(time(NULL));	//�����Լ�

	set_cursor_type(NOCURSOR);
	font_color(YELLOW);
	title();
	_getch();	//ȭ���� �Ͻ����� ���·� ����� ���� , system("pause") ��밡��

	system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);

	PARKING car = { 0 };
	while (1) {
		system("cls");
		char menu = main_menu();
		rewind(stdin);

		if (MAIN_CAR_NUM == menu) {													// �ϵ��ڵ��� �����ϱ� ���� enum�� ����  
			while (1) {
				car.car_num = insert_carnum(car);									//������ȣ ���ڸ� �޴� �Լ�
				system("cls"); 
				if (car.car_num >= CAR_NUM_MIN && 
					car.car_num <= CAR_NUM_MAX)						//������ȣ �Է¹��� ���� 
					break;															//���� ���ڸ��� �Էµ����� ���� �Է� �� ���ѷ��� 
			}
			strcpy(car.area.eng, eng[rand() % 8]);
			car.area.num = num[rand() % 11];

			car.time.ent_hour = (rand() % 14) + 6;	//���� �� 06~20 ���� ������ ����	 
			car.time.ent_min = rand() % 59;	
			
			//���� �� 00~59 ���� ������ ���� 
			file_write(car, file);					//���Ͽ� ������ȣ�� �����ð� ����
			show_title();							//�ߺ��Ǵ� �ȳ��� �Լ���
			file_read(file);						//�� ���� �о����
			printf("\n");
			int num;
			printf("	1 �Է½� ó������ �ǵ��ư��ϴ�. \n");
			printf("\n");
			printf("	  >>>  ");
			scanf("%d", &num);
			printf("\n");
			system("pause");						//while���� ����� �ʵ��� �Ͻ����� ���¸� �������
		}
		else if (MAIN_PAYMENT == menu) {
			system("cls");
			while (1) {
				car.car_num = insert_carnum(car);	//������ȣ ���ڸ� �Է¹޴� �Լ�
				system("cls");
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX) {
					break;
				}
			}
			system("cls");
			show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
			show_ent_time(car);	//������ȣ,�����ð� �ȳ�
			int num;
			printf("	1 �Է½� �������� �Ѿ�ϴ�. \n");
			printf("\n");
			printf("	  >>>  ");
			scanf("%d", &num);
			printf("\n");
			system("pause");
			system("cls");
			while (1) {
				system("cls");
				show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
				insert_exit_time();	//�����ð� �Է�
				scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
				//������ ���ϰ�� �극��ũ ���������� ����

				if ((car.time.exit_hour > car.time.ent_hour				  //1. �����ð��� �����ð����� ũ��(�ʰ�),
					&& car.time.exit_hour >= 6
					&& car.time.exit_hour < 22 && car.time.exit_min <= 59)	 //2. �����ð��� 6�ÿ��� 21:59�� �����̰ų� 	
					|| (car.time.exit_hour == 22 && car.time.exit_min == 00))	//3. �����ð��� 22: 00���� �� while�� Ż��. 
					break
			}

			if (car.time.exit_min >= car.time.ent_min) {
				car.time.hour = car.time.exit_hour - (car.time.ent_hour);
				car.time.min = car.time.exit_min - (car.time.ent_min);
			}
			else {				//���� (���� �� - ���� ��) ���� �� �������� ���´ٸ� 
				car.time.hour = (car.time.exit_hour - (car.time.ent_hour)) - 1;		//�ð� -1
				car.time.min = ((car.time.exit_min - car.time.ent_min)) + 60;		//�� +60
			}
			system("cls");
			show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���

			file_write(car, file);
			printf("\n");
			file_read2(car, file);		//������ȣ, ����, ����, �̿�ð� �ȳ�
			printf("\n");
			printf("\n");
			cal_fee(car);
		}
	}//while �� �ݴ� ��ȣ��
}