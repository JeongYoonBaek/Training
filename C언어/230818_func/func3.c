#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_number();
char get_char();

void main()
{
	// ��ȯ���� ������Ÿ�� �Լ���() {return ��}
	// return�� 200�� ���� ���� n�� ����
	int n = get_number();
	printf("���Ϲ��� ��:%d\n", n);
	// !!���α׷����� �����ʿ��� ���� ����!!
	char c = get_char();
	printf("���Ϲ��� ����:%c\n", c);

    // ������ ����ؼ� ���ϰ��� �����ʰ� 
    // ���� �Լ� ���ϰ��� %d�� ����
	printf("�Լ� ���ϰ�:%c\n", get_char());
}

int get_number()
{
	int n = 200;
	// �Լ��� ����Ǳ����� return ���� ȣ���� ������ �ǵ�����
	return n; // ���ϰ��� 1���� ���� ����
}

char get_char()
{
	char c = 'B';
	return c;
}