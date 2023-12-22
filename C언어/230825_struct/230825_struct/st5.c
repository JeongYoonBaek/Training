#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 
// 초기값 입력 받지 않고 3명의 정보를 입력받아서 출력하기

struct person
{
	char name[20];
	char phoneNum[20];
	int age; // 다른 정보들을 추가 하고 싶으면 여기에서 확장하면 됨. 
};

/* struct car //변수가 많아지기 시작하면 비효율적이어서 새로운 구조체 생성함
{
    char name[20];
	int year;
	int price;
}*/

int main(void)
{    // person : 구조체 정의 (8~10 line) 
	struct person arr[3] = { 0 }; // 배열 초기화 
	for (int i = 0; i < 3; i++) {
		printf("이름 입력 :"); scanf("%s", arr[i].name); // 배열
		printf("번호 입력 :"); scanf("%s", arr[i].phoneNum); // 배열
		printf("나이 입력 :"); scanf("%d", &(arr[i].age)); // 일반변수&
		// scanf에 공백 넣으면 뒤에 문자가 잘림
	}
	for(int i=0; i<3; i++){
	printf("이름: %s\n", arr[i].name);
	printf("번호: %s\n", arr[i].phoneNum);
	printf("나이: %d\n", arr[i].age);
	printf("=============================\n");
	}
	return 0;
}
