#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()

typedef struct _CAR {
	char model[20];
	char price[20];
	int year;
} CAR;

typedef struct _CUST {
	char name[20];
	char tel[20];
	char addr[50];
	CAR car;
} CUST;

char* model[] = { "아반떼", "소나타", "제네시스", "K5", "520d" };
char* price[] = { "20000000", "30000000", "40000000", "50000000", "60000000" };
int year[] = { 2018, 2019, 2020, 2021, 2022 };

char* name[] = { "홍길동", "강감찬", "김유신", "유관순", "전우치" };
char* tel[] = { "010-1234-1111", "010-1234-2222", "010-1234-3333", "010-1234-4444", "010-1234-5555" };
char* addr[] = { "서울", "부산", "대전", "대구", "광주" };

int main_menu();
void cust_write();
void cust_random();
void cust_read();

int main()
{    
	// 데이터 베이스 정보 처리 4가지 순서 : 1. 입력, 2. 검색, 3. 불필요한 데이터 삭제, 4. 수정  
	// 주의: 파일에 저장할 때 기존 데이터가 계속 존재해야함.
	//================================
	// 고객 차량 관리 프로그램 v2.0
	//================================
	// 1. 고객 정보 직접 입력 (rand x)
	// 2. 고객 정보 랜덤 입력 (rand o)
	// 3. 고객 정보 보기 
	// 4. 종료
	//================================
	// 메뉴 선택 : 
	// 고객 정보: 이름, 전화, 주소
	// 차량 정보: 모델명, 가격, 연식 

	while (1) {
		switch (main_menu()) {
		case 1:
			cust_write();
			break;
		case 2:
			cust_random();
			break;
		case 3:
			cust_read();
			break;
		case 4:
			
		case 5:
			printf("프로그램 종료!\n");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!!\n");
		}
	}
}

int main_menu()
{
	printf("================================\n");
	printf(" 고객 차량 관리 프로그램 v2.0\n");
	printf("================================\n");
	printf(" 1. 고객 정보 직접 입력\n");
	printf(" 2. 고객 정보 랜덤 입력\n");
	printf(" 3. 고객 정보 보기\n");
	printf(" 4. 고객 정보 전체 삭제\n"); // wb
	printf(" 5. 종료\n");
	printf("================================\n");
	printf("메뉴 선택");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void cust_write()
{
	CUST Customer = { 0 };
	CAR Car = { 0 };
	FILE* fp = fopen("cust.bin", "wb");

	printf("고객명 입력:");
	scanf("%s", &Customer.name);
	printf("주소 입력 :");
	scanf(" %c", &Customer.addr);
	getchar();
	// gets(cust.addr) 공백을 입력받기 위해 사용. Scanf은 사용안됨 
	printf("연락처 입력 :");
	scanf(" %d", &Customer.tel);
	printf("모델명 입력:");
	scanf(" %s", &Car.model);
	printf("가격 입력:");
	scanf(" %s", &Car.price);
	printf("연식 입력:");
	scanf(" %d", Car.year);
	fclose(fp);
	printf("데이터가 정상적으로 입력되었습니다\n");
}

void cust_random()
{
	CUST per_arr[10] = { 0 };
	CAR per_arr2[10] = { 0 };
	FILE* fp = fopen("cust.bin", "ab"); // 덧붙여 쓰기
	 
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		strcpy(per_arr[i].name, name[rand() % 5]);
		strcpy(per_arr[i].tel, tel[rand() % 5]);
		strcpy(per_arr[i].addr, addr[rand() % 5]);
		strcpy(per_arr2[i].model, model[rand() % 5]);
		strcpy(per_arr2[i].price, price[rand() % 5]);
		per_arr2[i].year = year[rand() % 5];
		fwrite(&per_arr[i], sizeof(per_arr[i]), 1, fp);
		fwrite(&per_arr2[i], sizeof(per_arr2[i]), 1, fp);	
	}
	fclose(fp);
	printf("데이터가 정상적으로 입력되었습니다\n");
}

void cust_read()
{
	CUST temp = { 0 };
	CAR temp2 = { 0 };
	FILE* fp = fopen("cust.bin", "rb");
	int cnt = 1;
	while (fread(&temp, sizeof(CUST), 1, fp) == 1 &&
		fread(&temp2, sizeof(CAR), 1, fp) == 1) {
		pritnf("&d번째 고객정보\n");
		printf("이름:%s 번호:%d 주소:%s 모델명:%s 가격:%s 연식:%d  \n", cnt++,
			temp.name, temp.tel, temp.addr, temp2.model, temp2.price, temp2.year);
	}
	fclose(fp);
}
