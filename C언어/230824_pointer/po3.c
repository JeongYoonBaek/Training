#include <stdio.h>

// 포인터 다른 파트들
/* 1.void
2. 함수포인터
3. 메모리 동적할당
4. 함수 포인터
5. 포인터 배열*/

int main()
{
	int n = 100;
	int* p = &n; // 포인터변수 p에 변수n의 주소값을 참조
	//int *p = NULL;
	//p = &n;

	int arr[5] = { 10, 20, 30, 40, 50 };
	// 포인터 변수 p에 배열변수arr의 주소값을 참조
	p = arr;
	printf("p[0]:%d\n", p[0]);
	printf("*p:%d\n", *p); // *(p+0)
	printf("arr[0]:%d\n", arr[0]);

	printf("p[1]:%d\n", p[1]);
	printf("*(p+1):%d\n", *(p + 1));
	printf("arr[1]:%d\n", arr[1]);

	for (int i = 0; i < 5; i++) {
		printf("p[%d]:%d\n", i, p[i]);
		printf("*(p+%d):%d\n", i, *(p + i));
		printf("arr[%d]:%d\n", i, arr[i]);
	}
}