#include <stdio.h>

int main()
{
    char* a = "������";
    int b = 200;
    int c = 6489-7505;
    char d = "��� ���̽� �۵��� 105, 108�� 808ȣ";
    float e = 180.2;
    float f = 78.5;
    char g = 'O';

    printf("-------------------------\n");
    printf("   ������ ���� Ȯ�μ�\n");
    printf("-------------------------\n");
    printf("�̸�:%s\n", a); // ���ڿ�
    printf("����:%d\n", b); // ����
    printf("��ȭ:010-%d%d\n", c); // ���ڿ�
    printf("�ּ�:%s\n", d); // ���ڿ�
    printf("Ű:%.1fcm\n",e); // �Ǽ�
    printf("������:%.1fkg\n", f); // �Ǽ�
    printf("������:%c��\n", g); // ����
    printf("-------------------------\n");
    
}