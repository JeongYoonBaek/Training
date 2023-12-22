#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()

// �Լ����� main������ ����ϱ�
typedef struct _PERSON {
	char name[20];
	int age;
	char tel[20];
	char addr[50];
} PERSON;

int main_menu();

int main()
{
	char* name[] = { "ȫ�浿", "����ġ", "������", "������", "�̼���" };
	int age[] = { 20, 30, 40, 50, 60 };
	char* tel[] = { "010-1234-1234", "010-1234-1111", "010-1234-2222",
		"010-1234-3333", "010-1234-4444" };
	char* addr[] = { "�뱸 ���� �ž�4��", "���� ���� �ž�4��" ,
		"���� ���� �ž�4��", 	"���� ���� �ž�4��", "�λ� ���� �ž�4��" };

	srand(time(NULL));

	while (1) {
		switch (main_menu()) {
		case 1:
		{
			PERSON per_arr[100] = { 0 };
			FILE* fp = fopen("friend2.bin", "wb");
			for (int i = 0; i < 100; i++) {
				strcpy(per_arr[i].name, name[rand() % 5]);
				strcpy(per_arr[i].tel, tel[rand() % 5]);
				strcpy(per_arr[i].addr, addr[rand() % 5]);
				per_arr[i].age = age[rand() % 5];
				fwrite(&per_arr[i], sizeof(per_arr[i]), 1, fp);
			}
			fclose(fp);
			printf("������ �����Ͱ� ���Ͽ� ����Ǿ����ϴ�!\n");
			break;
		}
		case 2:
		{
			PERSON temp = { 0 };
			FILE* fp = fopen("friend2.bin", "rb");
			int cnt = 1;
			while (fread(&temp, sizeof(PERSON), 1, fp) == 1) {
				printf("��ȣ:%d �̸�:%s ����:%d ��ȭ:%s �ּ�:%s\n", cnt++,
					temp.name, temp.age, temp.tel, temp.addr);
			}
			fclose(fp);
			break;
		}
		case 3:
			printf("���α׷� ����\n");
			exit(0);
		default:
			printf("�߸��� �޴� ����!!\n");
		}
	}

}

int main_menu()
{
	printf("---------------------------\n");
	printf("���� ���� ���α׷� v1.0\n");
	printf("---------------------------\n");
	printf("1.������ ������ ���� �Է�\n");
	printf("2.������ ������ ���� ����\n");
	printf("3.����\n");
	printf("---------------------------\n");
	printf("�޴� ����:");
	int menu;
	scanf("%d", &menu);
	return menu;
}