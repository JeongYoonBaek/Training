#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void call_by_addr(int a[]);
int main()
{
	// Call by Address (�ּҰ��� ���� ����)
	// ��� ���� ���α׷��� ���
	int arr[2] = { 10, 20 };
	printf("1.main()=>arr[0]:%d, arr[1]:%d\n", arr[0], arr[1]);
	call_by_addr(arr); // �ּҰ��� �ؿ� int a[] �Լ��� ����
	printf("2.main()=>arr[0]:%d, arr[1]:%d\n", arr[0], arr[1]);
}

void call_by_addr(int a[]) // a �ּҵ� ���۰���
                           // 2���� �迭�� ���ȣ 2��
{
	// a�� b�� ���� ���� �ٲ�ġ��
	// �ּҰ� ��ü�� ���� ���� ���ſ��� ���󰡱� ���� 

	int temp = a[0]; // a�� ���� �ӽú����� ���(���ϸ� ���� ����������)  // ���� ����
	a[0] = a[1];  // �Լ��� �Ҹ�Ǿ ������ �Ҹ� �ȵ�.
	a[1] = temp;  // �׷��� main ������ �� ���� �״�� ����� ��
	printf("call_by_addr()=>arr[0]:%d, arr[1]:%d\n", a[0], a[1]);
}