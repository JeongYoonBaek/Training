#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 

struct person { // 구조체 정의 (정의로는 동작하지 않음)
	char name[20]; // 20자 이상 초과되면 잘림
	char phoneNum[20];
	int age;   // 6-8 구조체의 멤버 변수 
};

int main(void)
{    
	struct person man1, man2; // 구조체 변수 man1, man2
	//     person = 구조체 데이터 타입, 구조체에선 int와 char과 같은 형태임.
	// 100명, 1000명의 정보를 사용하려면 구조체 배열을 사용
	strcpy(man1.name, "안성준"); // strcopy : name 배열에 안성준값 복사 
	strcpy(man1.phoneNum, "010 - 1122 - 3344"); // .을 찍으면 위에 있는 정보 조회됨
	man1.age = 23; 
	
	printf("이름 입력: "); scanf("%s", man2.name); // 배열변수라서 & 생략
	printf("번호 입력: "); scanf("%s", man2.phoneNum);
	printf("나이 입력: "); scanf("%d", &(man2.age));

	// 구조체 변수가 가지는 정보를 출력
	printf(">>>>>> 구조체에 저장된 정보 출력 <<<<<\n");
	printf("이름: %s\n ", man1.name); 
	printf("번호: %s\n ", man1.phoneNum);
	printf("나이: %d\n ", man1.age);

	printf("이름: %s\n ", man2.name);
	printf("번호: %s\n ", man2.phoneNum);
	printf("나이: %d\n ", man2.age);
	return 0; 
}