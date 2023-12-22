#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 구조체 파일
typedef struct _PERSON {
	char name[20];
	int age;
	char tel[20];
	char addr[50];
} PERSON;

int main()
{
	PERSON son[2] = {
		{"홍길동", 100, "010-1234-1234", "조선 한양 홍대감댁"},
		{"전우치", 200, "010-1234-4321", "조선 강원 두메산골"}
	};

	// 파일 쓰기
	FILE* fp = fopen("person_arr.bin", "wb");
	if (fp == NULL) {
		printf("파일 쓰기 오픈 에러!!\n");
		return -1;
	}
	fwrite(&son[0], sizeof(PERSON), 1, fp); // &son[0] 배열의 일반변수값
	fwrite(&son[1], sizeof(son[1]), 1, fp); // son = son + 1
	printf("파일에 정상적으로 저장되었습니다!\n");
	fclose(fp);

	// 파일 읽기
	FILE* fp3 = fopen("person_arr.bin", "rb");
	if (fp3 == NULL) {
		printf("파일 읽기 오픈 에러!!\n");
		return -1;
	}

	PERSON temp3 = { 0 }; // 파일에서 구조체 정보를 열어 저장하는 빈 구조체 
	// 파일에서 정상적으로 구조체 1개를 읽었다면
	while (fread(&temp3, sizeof(temp3), 1, fp3) == 1) {
		printf("이름:%s 나이:%d 전화:%s 주소:%s\n",
			temp3.name, temp3.age, temp3.tel, temp3.addr);
	}
	fclose(fp3);
}