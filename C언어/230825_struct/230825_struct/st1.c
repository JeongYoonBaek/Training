#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	// �л� ���� ���α׷� (100��) - �̸�, ��ȭ, ����
	char name1[20];
	char tel[20];
	int age1;
	// �Ϲ� ������ ���� �ϱ⿡�� �����ϴ� (300�� �ʿ�)

	// �Ϲݺ����� ����ϱ� �迭�� ó��
	char name[100][20];
	char tel[100][20];
	int age[100];
	// �迭�� ����ϸ� �Ϲ� ������ ����ϴ°ͺ��� 
	// ������ ���� ������ ���α׷����� �ϱ⿡�� ���� �����ϴ�

	// 1���� �л� ������ ������ ����(Ʋ)
	struct student {
	    char name[20];
		char tel[20];
		int age1;
	};
	// 1000���� �л� ������ �����ϴ� ����
	struct student arr[1000]; // ����ü �迭 ���� arr

}