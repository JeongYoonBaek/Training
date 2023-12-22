#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 스탠다드 라이브러리 srand()
#include <time.h> // time()
void show_lotto(int lotto[]);

int main()
{
	/* != : 다르다 == : 같다 참 : 1 거짓 : 0
	 1. 로또 생성(중복 방지) - 배열까지의 학습 내용
	 2. 함수로 처리 - 함수 학습

	 1. 로또 번호를 저장할 배열 생성 (랜덤값 1~45) - 이중 반복문 필요
	 2. 거품 정렬, 삽입 정렬, 선택 정렬 = 정렬 알고리즘 중 가장 기초
	 3. 로또 생성값과 이미 저장된 값과 비교하는 비교문 생성
	 4. 중복된 값이 생기면 i의 기회비용이 하나 사라지기 때문에 
	 그 기회비용을 살리기 위해 감소를 해줘야 함 */

	int lotto[6] = { 0 }; // 로또 번호 저장할 배열 생성
	srand(time(NULL));
	show_lotto(lotto);
	for (int i = 0; i < 6; i++) { // 6개의 로또번호 생성
	    printf("%d\t", lotto[i]);  // 디버깅 확인용  for (int i = 0; i < 6; i++) {
	}
}

void show_lotto(int lotto[])
{
	for (int i = 0; i < 6; i++) { // 6개의 로또번호 생성
		lotto[i] = (rand() % 45) + 1; // 괄호안 (0~44)+1 = 45가지 숫자 
		printf("%d\t", lotto[i]);  // 디버깅 확인용
		for (int j = 0; j < i; j++) {
			// 배열에 있는 숫자와 새로 획득한 숫자 비교
			if (lotto[i] == lotto[j]) {
				// i배열과 j배열은 같다
				i--; // 증가된 값을 다시 복구 시키기 위해서 감소
				break; // 탈출
			}
		}
	}
}
