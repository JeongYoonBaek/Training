#define _CRT_SECURE_NO_WARNINGS // �����޼��� ��ó���� 
#include <stdio.h>
int main()
{
	// 1. ������ (PI)�� �����ϴ� �Ǽ��� ��� ������ �����ϰ� ���� ���� (PI=3.14)
	// 2. ���� �������� �����ϴ� �Ǽ��� ������ �����ϰ� �Է� �ޱ�.
	// 3. ���� ������ ����ϱ� (������ * ������ * PI = ���� ����)

	const float PI = 3.14; // ����� ���� (�빮�ڷ� ǥ��)
	float r;
	printf("���� ������ �Է�:");
		scanf("%f", &r);
	float area = r * r * PI;
	printf("���Ǹ���:%f\n", area);

	// 1. �������� ������ ���� ����
	// 2. �������� ���� �Է� �ޱ�
	// 3. ��� ������ ��հ��� ������ ������ ������ ����
	// 4. ��հ��� ������ ���

	int result;
	int kor;
	int eng;
	int math;
	int sci;
	int add = kor + eng + math + sci;
	int avg = kor + eng + math + sci / 4;

	printf("���� ���� �Է�:%d\n", kor);
	scanf("%d", &kor);
	printf("���� ���� �Է�:%d\n", eng);
	scanf("%d", &eng);
	printf("���� ���� �Է�:%d\n", math);
	scanf("%d", &math);
	printf("���� ���� �Է�:%d\n", sci);
	scanf("%d", &sci);
	result = kor + eng + math + sci;
	printf("����:%d\n", add, result);
	result = kor + eng + math + sci / 4;
	printf("�������:%d\n", avg, result);

	// 1. ȭ���µ��� �����ϴ� ������ ���� ����
	// 2. ȭ�� �µ��� �Է� �ޱ�.
	// 3. ���� �µ��� �����ϴ� �Ǽ��� ���� ����
	// 4. ȭ�� �µ��� ���� �µ��� ��ȯ. �����µ�=(ȭ���µ� -32)/1.8
	// 5. ���� �µ��� ���

	int hwa;
		printf("ȭ���µ��� �Է�:��\n");
	scanf("%d", &hwa);

	float sup = (hwa - 32) / 1.8;
	printf("�����µ�:%F.1��\n", &sup);
}