#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void show_num(int num);
int main()
{
	// 1~5���� ���������� �Ű����� �����Ͽ� 
	// ����ϴ� �Լ� �ۼ�
	// �Լ��� show_num()
	show_num(1); // show_num �Լ� ȣ��(����)
	show_num(2); // function 
	show_num(3);
	show_num(4);
	show_num(5);

	int num = 0;
	for (int i = 1; i <= 5; i++) { //!!! �տ�ó�� �ݺ��� ����ؼ�
		show_num(i);  // 1~10000���� �������� ��� ����!!!
	}

void show_num(int num); // int n = 10; (X)
	{
		printf("����ϴ� �Լ�: %d \n", num);
	}
}