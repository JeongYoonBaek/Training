#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // ���Ĵٵ� ���̺귯�� srand()
#include <time.h> // time()

int pick_lotto(int arr);

int main()
{
	// ������ �ζ� ���α׷� �����
	// �ζ� ��ȣ�� ������ ����ִ� 1���� �迭 6�� ����� 1-45�� ����
	// �ݺ��� 6���� ���ư�. �ݺ��� ������ 1�� ����. 
	// 6�� ���ʷ� ������ �ߺ����� �ʾƼ� ù��° �迭�� ��
	// �ι�° 10�� ������ ������ ���Դ� ��ȣ�� ������ �ٸ��� �� ��
	// �ٸ��� �ι�° �迭�� ��. !�� ������ ��� 
	// // != : �ٸ��� == : ���� ��: 1 ����: 0
	// ����° 6�� ������ �ϳ��� �� �� ������ ���� ������
	// �׸��� �ٽ� �ζǹ�ȣ �̾Ƽ� 7�� ������ ���� ���ڵ�� ��

	int lotto[6] = { 0 };
	int lotto = pick_lotto;
	int random = 0;
	printf("%d\t", random);
	return 0;
	pick_lotto(6);
}

int pick_lotto(arr)
{
	srand(time(NULL));
	int random = 0;
	for (int i = 0; i < 6; i++) {
		random = (rand() % 45) + 1;

		lotto[i] = random;
	
}
