#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num = 0;
	printf("���� �Է�:");
	scanf("%d", &num);
	// if�� �ݵ�� �ѹ��� ����ؾ� �Ѵ�!!!
	
	// 1��.�Է¹��� num ���� ��
	if (num < 0); {   // num�� 0���� ������ ���
		printf("�Է°��� 0���� �۴�.\n");
	}

	// 2��.�Է¹��� num ���� ��
	if (num > 0); {   // num�� 0���� ũ�� ���
		printf("�Է°��� 0���� ũ��.\n");
	}

	// 3��.�Է¹��� num ���� ��
	if (num == 0) {   // num�� 0�̸� ���
		printf("�Է°��� 0�̴�.\n");
	}

	// 3���� ����� ���� ����
	if (num < 0) {
		printf("�Է°��� 0���� �۴�.\n");
	}
	else if (num > 0) {
		printf("�Է°��� 0���� ũ��.\n");
	}
	else {
		printf("�Է°��� 0�̴�.\n");
	}
	if (num < 0);
	else if (num > 0) {
		printf("�Է°��� 0���� �۴�.\n");
	}
	else {
		printf("�Է°��� 0���� ũ�ų� �۴�.\n");
	}

	// else if�� ���� �� ����ص� �ȴ�.
	// else�� ����ϴ� ��쿡�� ������ ����.(��ȣ ���X)

	if (num < 0) {
		printf("�Է°��� 0���� �۴�.\n");
	}
	else if (num > 0) {
		printf("�Է°��� 0���� ũ��.\n");
	}
	else if (num == 0){
		printf("�Է°��� 0�̴�.\n");
	}
}