#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void show_day(int n);

int main()
{
	// main �Լ����� 1~7 ������ ���ڸ� �Է¹޾Ƽ�
	// �Ű������� �����Ͽ� �Ű������� ���� 
	// 1�̸�, ������ ���
	// 2�̸�, ȭ���� ���
	// 3=�� 4=�� 5=�� 6=�� 7=�� ����ϴ� �Լ� �ۼ�
	// show_day()

    printf("���� �Է�:(1:������ 2:ȭ���� 3:������ 4:����� 5:�ݿ��� 6:����� 7:�Ͽ���)=>");
	int day;
	scanf("%d", &day); // 1���� 7���� �Է�
	//// �Լ� ȣ���Ҷ� �ݵ�� ��ȣ �ȿ� int�� void ������ ���� ////
	show_day(day); // show_day �Լ� ȣ��(����)
	}

void show_day(int n)
{

	switch (n) {
	case 1:
		printf("������"); break;
	case 2:
		printf("ȭ����"); break;
	case 3:
		printf("������"); break;
	case 4:
		printf("�����"); break;
	case 5:
		printf("�ݿ���"); break;
	case 6:
		printf("�����"); break;
	case 7:
		printf("�Ͽ���"); break;
	default:
		printf("�߸��� ����"); break;
	}
}
