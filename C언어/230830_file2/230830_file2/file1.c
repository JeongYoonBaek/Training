#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ����ü ����
typedef struct _PERSON {
	char name[20];
	int age;
	char tel[20];
	char addr[50];
} PERSON;

int main()
{
	PERSON son = { "ȫ�浿", 100, "010-1234-1234", "���� �Ѿ� ȫ�밨��" };
	PERSON so2 = { "����ġ", 200, "010-1234-4321", "���� ���� �θ޻��" };
	
	//���� ����
	FILE* fp = fopen("person.bin", "wb"); // ����ü �� ���� b
	if (fp == NULL) {
		printf("���� ���� ���� ����!!\n");
		return -1; // -1 : ���α׷� ����, 0:success
	}
	fwrite(&son, sizeof(son), 1, fp); // ����ü �Ϲݺ��� &(�ּҰ�) ������
	fwrite(&so2, sizeof(so2), 1, fp);
	printf("���Ͽ� ���������� ����Ǿ����ϴ�!\n");
	fclose(fp);

	// ���� �б�
	
	FILE* fp3 = fopen("person.bin", "rb"); // ���� ���� ������ �̹� �����ϰ� �־�� ��.
	if (fp3 == NULL) {
		printf("���� �б� ���� ����!!\n");
		return -1;
	}

	PERSON temp3 = { 0 }; // ���Ͽ��� ����ü ������ ���� �����ϴ� �� ����ü 
	// ���Ͽ��� ���������� ����ü 1���� �о��ٸ�
	while (fread(&temp3, sizeof(temp3), 1, fp3) == 1) {
		printf("�̸�:%s ����:%d ��ȭ:%s �ּ�:%s\n",
			temp3.name, temp3.age, temp3.tel, temp3.addr);
	}
	fclose(fp3);
}