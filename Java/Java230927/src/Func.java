import java.util.Scanner;
public class Func {
          // public [반환형] [함수명](매개변수 타입 매개변수명, ....){
//				명령문들
//  }
	// static 메서드 (정적 메서드) :: 물건을 만들 때와 상관없이 설계도 자체에 속하는 기능 
	// 인스턴스 메서드 :: 실제로 물건(객체)를 만든 후에 그 물건에 대해 수행되는 동작 
	public static int plus(int a, int b) { // 함수 구현
		return a + b;
	}
	public static int minus(int a, int b) {
		return a - b;
	}
	public static int multi(int a, int b) {
		return a * b;
	}
	public static double division(int a, int b) { // 나눗셈은 계산기처럼 소숫점까지 출력이 되려면 
		return (double) a / b;
		// (int) / (int) = (int)
		// (double) / (int) = (double)
		// (int) / (double) = (double) int가 4바이트 double은 8바이트. 표현할 수 있는 범위가 double이 크니까 좀 더 면밀한
		// 형태를 출력할 수 있는 double을 사용한다.
		
	}
	public static int remain(int a, int b) {
		return a % b;
	}
    
	// 출력은, 콘솔 상에서 확인할 수 있는 값일 뿐이고
	// 반환은, 프로그램 실행 흐름상 "뱉어지는" 결과물 
	
	public static void main(String[] args) {
           Scanner scan = new Scanner(System.in);
		// 함수 :: 특정 목적을 위해 묶어둔 "명령문들의 집합"
		
		// 예제 :: 계산기 구현 (+, -, *, /, %)
		// 2개의 숫자와 1개의 연산자 입력받고, 연산 결과 출력하라.
           
        // 1. 입력 (2개의 숫자, 1개의 연산자(char)) // 숫자를 제외한 문자는 모두 char
       	System.out.println("첫 번째 숫자 입력 : ");
        int num1 = scan.nextInt();
        System.out.println("두 번째 숫자 입력 : ");
		int num2 = scan.nextInt();
		System.out.println("연산자 입력 : ");
		char oper = scan.next().charAt(0);
		
		// 2. 연산자에 따라, 연산 수행 
		// 함수호출 :: [함수명]
		switch(oper) {
		case '+': 
			System.out.println("덧셈 결과:" + plus(num1, num2));
			break;
		case '-':
			System.out.println("뺄셈 결과:" + minus(num1, num2));
			break;
		case '*':
			System.out.println("곱셈 결과:" + multi(num1, num2));
			break;
		case '/': // 몫 나누기 수행
			System.out.println("몫 나눗셈 결과:" + division(num1, num2));
			break;
		case '%': // 나머지 나누기 수행 
			System.out.println("나머지 결과:" + remain(num1, num2));
			break;
	    default:  // 옳바르지 않게 연산자를 입력했을 경우 -> 오류메시지 출력 
	    	System.out.println("error!!!");
		}
	}
}
