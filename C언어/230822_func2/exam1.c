// exam1.c
#include <stdio.h>
#include <stdlib.h>	// srand()
#include <time.h>	// time()
void check_odd(int arr[]);
int main()
{
	// 1.main()���� 10���� ���ڸ� �����ϴ� 1���� �迭 ����
	// 2.�����ϰ� 10���� ���ڸ� �迭�� ����
	// 3.�迭�� �ּҰ��� �Ű������� �����ϰ� Ȧ,¦�� �����Ͽ� ��� �Լ�
	srand(time(NULL));	// �Ź� �ٸ� �õ尪 ����
	int random = 0;		// ������ ������ ����
	int arr[10] = { 0 };// 10���� ���ڸ� �����ϴ� 1���� �迭
	for (int i = 0; i < 10; i++) { // 10ȸ �ݺ�
		random = (rand() % 45) + 1; // ���� ���� 1~45
		//printf("%d\n", random);
		arr[i] = random; // arr[0] ~ arr[9] �� ������ ����
	}
	check_odd(arr);
}

void check_odd(int arr[])
{
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 == 0) {
			printf("%d ¦��\n", arr[i]);
		}
		else {
			printf("%d Ȧ��\n", arr[i]);
		}
	}
}