#ifndef __FILE_H__
#define __FILE_H__

#define STR_EMPTY	""		//���ڿ�
#define ID_EMPTY	-1

typedef struct TIME {
	int ent_hour;	//���� �� ����
	int ent_min;	//���� �� ����
	int exit_hour;	//���� �� �Է�	
	int exit_min;	//���� �� �Է�
	int hour;
	int min;
}TIME;

typedef struct AREA {
	char eng[20];
	int num;
}AREA;

typedef struct PAYMENT {
	int fee;
	int cost;
}PAYMENT;

typedef struct PARKING {
	int car_num;		//������ȣ
	TIME time;
	AREA area;
	PAYMENT pay;
} PARKING;

void file_write(PARKING car, char filename[]);
void file_read(char filename[]);
void file_read2(PARKING car, char filename[]);
#endif