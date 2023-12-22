import java.util.Scanner;

public class Overloading {
	public static int sum() { 	// 매개변수 없이
		return 1+1;
	}
	public static int sum(int a) {	 // 매개변수 하나
		return a+1;
	}
	public static int sum(int a, int b) { 	// 매개변수 둘
		return a+b;
	}
	public static void main(String[] args) {
		// 오버로딩 :: 함수에 적용되는 개념 
		// "매개 변수 구성이 다르다면, 함수명을 같게 하여도 "함께 사용"할 수 있다."
		Scanner scan = new Scanner(System.in);
				
		/*int a;
		int a;
		int a; // 변수는 이름이 중복되면 에러가 생김 */
		
		int num = scan.nextInt();
		System.out.println("sum() 호출 결과 : "+ sum());	// 매개변수 없이 계산한 값 출력
		System.out.println("sum(num) 호출 결과 : "+ sum(num));		// 매개변수 1개로 계산한 값 출력
		System.out.println("sum(num,num) 호출 결과 : "+ sum(num,num));		// 매개변수 2개로 계산한 값 출력 
	}
}
