#define _CRT_SECURE_NO_WARNINGS // �����޼��� ��ó���� 
#include <stdio.h>

int main(void)
{
    int result;
    int num1, num2, num3, num4, num5;// �Ϲݺ��� : ���� ����
    
    printf("5�ϰ� ������Է�: ");
    scanf("%d", &num1);
    printf("5�ϰ� ������Է�: ");
    scanf("%d", &num2);
    printf("5�ϰ� ������Է�: ");
    scanf("%d", &num3);
    printf("5�ϰ� ������Է�: ");
    scanf("%d", &num4);
    printf("5�ϰ� ������Է�: ");
    scanf("%d", &num5);
    result = num1 + num2 + num3 + num4 + num5;

    printf("%d + %d + %d + %d + %d = %d��\n", num1, num2, num3, num4, num5, result);

    //�������: const�� ���� �տ� ����. (���� �Ұ�)
    // const int n = 100;
    // int n2 = 200;
    // n2 = 300; // �Ϲݺ����� ���� ���� ����
    // n = 500;
}