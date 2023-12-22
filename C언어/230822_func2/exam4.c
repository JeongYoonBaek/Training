#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // 스탠다드 라이브러리 srand()
#include <time.h> // time()

int pick_lotto(int arr);

int main()
{
	// 간단한 로또 프로그램 만들기
	// 로또 번호를 저장할 비어있는 1차원 배열 6개 만들기 1-45번 숫자
	// 반복문 6번이 돌아감. 반복문 유형은 1개 쓰임. 
	// 6이 최초로 나오면 중복되지 않아서 첫번째 배열에 들어감
	// 두번째 10이 나오고 기존에 나왔던 번호와 같은지 다른지 비교 후
	// 다르면 두번째 배열에 들어감. !비교 연산자 사용 
	// // != : 다르다 == : 같다 참: 1 거짓: 0
	// 세번째 6이 나오면 하나씩 비교 후 같으면 값을 버리기
	// 그리고 다시 로또번호 뽑아서 7이 나오면 나온 숫자들과 비교

	int lotto[6] = { 0 };
	int lotto = pick_lotto;
	int random = 0;
	printf("%d\t", random);
	return 0;
	pick_lotto(6);
}

int pick_lotto(arr)
{
	srand(time(NULL));
	int random = 0;
	for (int i = 0; i < 6; i++) {
		random = (rand() % 45) + 1;

		lotto[i] = random;
	
}
