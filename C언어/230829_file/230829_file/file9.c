#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct fren // ����ü Ÿ��
{
	char name[10];
	char sex;
	int age;
} Friend; // ����ü ����

int main()
{
	FILE* fp;
	Friend myfren1;
	Friend myfren2;
	
    /*** ���� ���� ***/
	// ����ü�� ���� ���̳ʸ� ���¸� ���� ��
	fp = fopen("friend.bin", "wb"); // 2�� �������� 
	printf("�̸�, ����, ���� �� �Է�: ");
	scanf("%s %c %d", myfren1.name, &myfren1.sex, &myfren1.age);
	fwrite(&myfren1, sizeof(myfren1), 1, fp);
	      // �ּҰ� (������ ����)
	fclose(fp);

	/*** ���� �б� ***/
	fp = fopen("friend.bin", "rb");
	fread(&myfren2, sizeof(myfren2), 1, fp);
	printf("%s %c %d \n", myfren2.name, myfren2.sex, myfren2.age);
	fclose(fp);

}
 