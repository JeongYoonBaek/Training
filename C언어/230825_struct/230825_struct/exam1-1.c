// exam1.c
#include <stdio.h>
#include <stdlib.h>	// srand()
#include <time.h>	// time()
#include <string.h>

// �л� ���� ����ü
struct score {
	int kor;	// ����
	int eng;	// ����
	int math;	// ����
	int hap;	// ����
	int avg;	// ���
	char hak;	// ����
	char name[20];
};

int main()
{   
	char* name[5] = { "ȫ�浿", "�̼���", "������", "����ġ", "������" };
	int s[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	struct score sc_arr[100] = { 0 };
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		strcpy(sc_arr[i].name, name[rand() % 5]);
		sc_arr[i].kor = s[rand() % 10];
		sc_arr[i].eng = s[rand() % 10];
		sc_arr[i].math = s[rand() % 10];

		printf(">>> %d��° %s �л����� <<<\n", i + 1, sc_arr[i].name);
		printf("sc_arr[%d] ����:%d\n", i + 1, sc_arr[i].kor);
		printf("sc_arr[%d] ����:%d\n", i + 1, sc_arr[i].eng);
		printf("sc_arr[%d] ����:%d\n", i + 1, sc_arr[i].math);
		printf("----------------------------\n");
	}
}
