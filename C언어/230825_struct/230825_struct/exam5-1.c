// exam5.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strcpy(), strcmp()
#include <stdlib.h>	// srand()
#include <time.h>	// time()

struct car {
	char model[20];		// 모델명	
};

struct manager {
	char name[20];
};

struct customer {
	char name[20];
	struct manager ma;
	struct car ca;
};

char* cu_name[] = { "홍길동", "전우치", "유관순", "이순신", "김유신" };
char* model[] = { "그랜저", "제네시스", "산타페", "소나타", "K9" };
char* ma_name[] = { "안중근", "김좌진", "홍범도", "임꺽정", "신사임당" };

int main_menu();

int main()
{
	srand(time(NULL));
	struct customer cu[5] = { 0 };	// 랜덤 입력 저장
	while (1) {
		switch (main_menu()) {
		case 1:
			printf("고객명 입력:");
			scanf("%s", &cu[0].name);
			printf("차량명 입력:");
			scanf("%s", &cu[0].ca.model);
			printf("매니저 입력:");
			scanf("%s", &cu[0].ma.name);
			printf("고객정보가 수동으로 입력되었습니다.\n");
			break;
		case 2:
			for (int i = 0; i < 5; i++) {
				strcpy(cu[i].name, cu_name[rand() % 5]);
				strcpy(cu[i].ca.model, model[rand() % 5]);
				strcpy(cu[i].ma.name, ma_name[rand() % 5]);
			}
			printf("고객정보가 랜덤하게 입력되었습니다.\n");
			break;
		case 3:
			for (int i = 0; i < 5; i++) {
				// cu[i].name 의 값이 ""과 같다면
				// 즉, 고객정보가 없으면 탈출함.
				if (strcmp(cu[i].name, "") == 0) {
					break;
				}
				printf("고객번호:%d\n", i + 1);
				printf("고객명:%s\n", cu[i].name);
				printf("차량명:%s\n", cu[i].ca.model);
				printf("매니저명:%s\n", cu[i].ma.name);
				printf("--------------------------\n");
			}
			break;
		case 4:
			printf("프로그램 종료!\n");
			exit(0);
		default:
			printf("잘못된 메뉴 선택!!!\n");
		}
	}
}

int main_menu()
{
	printf("----------------------------\n");
	printf("고객차량 관리 프로그램 v1.6\n");
	printf("----------------------------\n");
	printf("1. 고객정보 직접 입력\n");
	printf("2. 고객정보 랜덤 입력\n");
	printf("3. 고객정보 보기\n");
	printf("4. 종료\n");
	printf("----------------------------\n");
	printf("메뉴 선택 :");
	int menu;
	scanf("%d", &menu);
	return menu;
}