#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#incluede <stdlib.h> // exit() ����
    //printf("�߸��� ���� ���� �Է�!\n");
	//exit(0); // ���α׷� ���� ���� �Ǵ� return 0;


void sub(int kor, int eng, int math);
int main()
{
	//1. ���� �Է��� main()���� �Է� ����.
	//2. �Է� �޴� ������ 0~100 ������ ���ڸ� �Է¹޵��� ���� üũ
	// -> �����ϰ� �ѹ��� üũ�ϸ� �� (����ڰ� �Ǽ��� �߸� �Է��ϸ�
	// �����޽��� ����ϰ� ���� ó��)
	//3. ��,��,�� ������ ������ �Ű������� �����Ͽ� ����, ��հ���
	// ����ϴ� �޽�� �ۼ�.
	//4. ����3���� �׽�Ʈ �Ϸ� ���Ŀ� �߸� �Է��� �� üũ�� Ȯ���ϱ�
	// �Ǽ��� �Է��ϸ� ���Է� ���� �� �ֵ��� ó��

	int kor, eng, math;
	int add = 0;  int avg = 0;

	do
	{
		printf("���� ���� �Է�:\n");
		scanf("%d", &kor);
	} while (kor < 0 || kor > 100);

	do
	{
		printf("���� ���� �Է�:\n");
		scanf("%d", &eng);
	} while (eng < 0 || eng > 100);

	do
	{
	    printf("���� ���� �Է�:\n");
	    scanf("%d", &math);
    }while (math < 0 || math > 100);
		sub(kor, eng, math);
	}

void sub(int kor, int eng, int math)
{
	int add = kor + eng + math;
	int avg = (add) / 3;
	printf("����:%d\n", add);
	printf("�������:%d\n", avg);
}