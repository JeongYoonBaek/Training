#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy ���ڿ� ó�� ���� 
#include <stdlib.h>
#include <time.h> // time()
char show_hak(int avg);


struct exam // 1���� ���� ���� ����ü
{
    int kor; int eng; int math;
    int hap; int avg; char grade; char name[20]; // Ʋ�� �ϳ��� ���� ����. �ڿ� �� �Է�x 
};

int main()
{
    // �л� 5���� ��,��,�� ������ ����, ���, ������ �����ϴ� ����ü
    // ������ 2���� �迭, ������ �Ϲ� ����
    // 1. ����ü�� �����ϰ� ����ü �迭 ��������
    char* name[5] = { "ȫ�浿", "�̼���", "������", "����ġ", "������" };
    int s[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }; // s��� ���� �迭 ������ �Է� 
    struct exam arr[100] = { 0 }; // 100���� ���� ����  
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        strcpy(arr[i].name, s[rand() % 5]);
        printf("%d��° �л� �̸� => %s\t", arr[i].name);
        arr[i].kor = s[rand() % 10]; // s �迭 ������ 10���� �� �������� ��� 0~9 s[5]= % 6
        printf("%d��° �л� �������� => %d\t", i + 1, arr[i].kor);
        arr[i].eng = s[rand() % 10];
        printf("%d��° �л� �������� => %d\t", i + 1, arr[i].eng);
        arr[i].math = s[rand() % 10];
        printf("%d��° �л� �������� => %d\t", i + 1, arr[i].math);
        int hap = arr[i].kor + arr[i].eng + arr[i].math;
        printf("%d��° �л� ���� => %d\t", i + 1, hap);
        int avg = hap / 3;
        char grade;
        printf("%d��° �л� ��� => %d\t", i + 1, avg);
        printf("%d��° �л� ���� => %d\t", i + 1, grade);
        printf("\n");
    }
}

char show_hak(int avg)
{
    if (avg >= 90 && avg <= 100) {
        printf("A����");
    }
    else if (avg >= 80 && avg <= 90) {
        printf("B����");
    }
    else  if (avg >= 70 && avg <= 80) {
        printf("C����");
    }
    else  if (avg >= 60 && avg <= 70) {
        printf("D����");
        }
    else if (avg >= 50 &&  avg <= 60) {
        printf("E����");
    }
    else {
        printf("F����");
    }
}