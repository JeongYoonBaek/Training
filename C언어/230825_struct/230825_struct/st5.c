#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy ���ڿ� ó�� ���� 
// �ʱⰪ �Է� ���� �ʰ� 3���� ������ �Է¹޾Ƽ� ����ϱ�

struct person
{
	char name[20];
	char phoneNum[20];
	int age; // �ٸ� �������� �߰� �ϰ� ������ ���⿡�� Ȯ���ϸ� ��. 
};

/* struct car //������ �������� �����ϸ� ��ȿ�����̾ ���ο� ����ü ������
{
    char name[20];
	int year;
	int price;
}*/

int main(void)
{    // person : ����ü ���� (8~10 line) 
	struct person arr[3] = { 0 }; // �迭 �ʱ�ȭ 
	for (int i = 0; i < 3; i++) {
		printf("�̸� �Է� :"); scanf("%s", arr[i].name); // �迭
		printf("��ȣ �Է� :"); scanf("%s", arr[i].phoneNum); // �迭
		printf("���� �Է� :"); scanf("%d", &(arr[i].age)); // �Ϲݺ���&
		// scanf�� ���� ������ �ڿ� ���ڰ� �߸�
	}
	for(int i=0; i<3; i++){
	printf("�̸�: %s\n", arr[i].name);
	printf("��ȣ: %s\n", arr[i].phoneNum);
	printf("����: %d\n", arr[i].age);
	printf("=============================\n");
	}
	return 0;
}
