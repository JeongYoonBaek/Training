#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h> // string copy 문자열 처리 관련 
#include <stdlib.h>
#include <time.h> // time()


struct professor { // 담당 교수 정보
	char name[20];  // 교수명
	char major[20]; // 전공과목
	int age;        // 교수나이
};


struct member // 학생 정보
{
	char name[20]; // 학생명
	char tel[20];  // 전화번호
	char addr[20]; // 주소
	int age;       // 나이
	struct professor pro; // 담당교수
};

int main()
{
	// 1. 학생 정보 구조체 만들기
	// 2. 학생 정보는 이름, 휴대폰 번호, 나이, 주소가 있음
	// 3. 100명의 학생 정보를 랜덤하게 저장하여 출력
	// 4. 랜덤값은 배열에 값을 저장하고 랜덤하게 불러오게 처리

	// 문자열을 저장하는 배열 샘플 코드
	/*strcpy(num1.name, "홍길동");
	strcpy(num1.tel, "010-1234-1111");
	strcpy(num1.addr, "서울");
	num1.age = 10; */

	struct member num1, num2, num3, num4, num5;

	char* name[5] = { "홍길동", "전우치", "김유신", "유관순", "강감찬" };
	char* tel[] = { 010 - 1234 - 1111 , 010 - 1234 - 2222, 010 - 1234 - 3333, 
		            010 - 1234 - 4444, 010 - 1234 - 5555 }; // -가 있는 변수는 []숫자 생략 가능
	char* addr[5] = { "서울", "경기", "인천", "대구", "제주도" };
	int age[5] = { 10, 20, 30, 40, 50 };
	struct member st[100] = { 0 }; // 100명의 정보 저장
	srand(time(NULL));

	for (int i = 0; i < 100; i++) { // 100명의 학생 정보 저장 
		strcpy(st[i].name, name[rand() % 5]); // 5가지의 값을 랜덤으로 출력 
		strcpy(st[i].tel, tel[rand() % 5]);
		strcpy(st[i].addr, addr[rand() % 5]);
		st[i].age = age[rand() % 5]; // 일반 변수는 strcpy를 사용할 필요가 없음		
	}

	for (int i = 0; i < 100; i++) {
		printf(">>> %d번째 학생 정보 <<<\n", i + 1);
		printf("이름:%s\n", st[i].name);
		printf("번호:%s\n", st[i].tel);	
		printf("주소:%s\n", st[i].addr);
		printf("나이:%d\n", st[i].age);
		printf("==========================\n");
	}

	st[0].pro.age = 50; // 첫번째 학생의 담당교수 나이
	strcpy(st[0].pro.name, "홍교수"); // 첫번째 학생의 담당교수 이름
	printf("%s 학생의 담당 교수:%s\n", st[0].name , st[0].pro.name);

}