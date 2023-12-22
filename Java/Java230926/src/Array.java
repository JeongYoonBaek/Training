import java.util.*; // Scanner 말고 *을 붙혀도 됨. (모두 다 파일에 통합해서 불러올 수 있음)

public class Array {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		// 배열 :: 동일한 자료형으로 여러 공간 갖고 있는 변수
		// 배열 선언 
		
		// 1. 초기화하며 선언
		// 자료형 (배열명)[] = {초기화할 값};
		double arr[] = {11.1, 22.2, 33.3}; // 3개의 크기 저장
		char ch[] = {'a', 'b', 'c'};       // 3개의 크기 저장
		
		
		// 2. 크기 지정하여 선언 
		// 자료형 (배열명)[] = new 자료형 [배열크기]; [] : 어떤 크기에 대한 정보를 지정안하고 대괄호의 역할은 단순히 배열의 형태를 갖고있다. 
		// 하나의 공간만 가지고 있는 것이 아닌것을 언급하는 역할
		int alpha[] = new int [26];
		
		
		// 예제 :: 학생 수(n)와 각 학생의 키를 입력받고, 평균을 출력하라. 
		// 1. 학생 수 입력값 받기
	   System.out.println("학생 수 입력: ");
	   int n = scan.nextInt();
	    
		// 2. 학생들의 키를 입력받기 (키는 대부분 소수점 한 자릿수까지 출력하기 때문에 double 실수형을 사용함)
		// C언어에서는 double key[n]; 선언이 안됐지만 자바에서는 됨
		Double key[] = new Double[n]; 
		for(int i = 0; i < n; i++) {           // 입력한 학생 수 만큼 키 입력받는 반복문 생성 
			System.out.println("학생 키 입력 : ");   // 학생 키 입력 안내문 출력 
			key[i] = scan.nextDouble();           // 입력한 학생 키를 배열에 저장함. 
		}
		
		// 평균을 구하기 위한 총합
		double sum = 0;  // 실수형 총합 변수 선언 
		for(int i = 0; i < n; i++) {  // key 배열에 있는 저장된 i 값을 반복문으로 출력함 
			sum += key[i]; // 학생들의 저장된 키 값을 sum 이라는 총합에 더한 뒤 저장함 
		}
	    double avg = sum / n;  // 학생들의 키 총합과 학생 수를 나눠서 평균값에 저장함  
	    System.out.println("총합 키 :" + sum); // 총합 키 출력
	    System.out.println("평균 키 : "+ avg); // 평균 키 출력 
	}
}
	
		
		

