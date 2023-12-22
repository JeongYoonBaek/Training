import java.util.Scanner; // 노란색 줄 뜨고 있는건 신경 안써도 됨. 선언하는데 별도로 사용하지 않아서 거기에 대한 경고문임. 에러는 아님 

public class Tutorial {
    public static void main(String args[]) {
    	Scanner scan = new Scanner(System.in);
    	
    	// 여기에서, 주요 명령문 작성하면 됨
    	
    	// 정수형 자료형 
    	int i;  
    	long l;
    	
    	// 실수형 자료형
    	double d;  
    	float f; 
    	// 둘의 차이는 float는 소수점 4자리까지 표현 가능한 반면, double은 소수점 8자리까지 표현 가능하다.
    	
    	// 문자형 자료형
    	char c = 'a';  
    	String s = "abc";
    	
        // 출력문 
    	System.out.printf("결과값은 %d입니다.", 3); // C언어 출력 표기법임. 
    	System.out.println("Hello111"); // 표준 (98~99%가 이 양식을 사용함), "Hello111" + "\n"
    	System.out.print("Hello222"); // "Hello2" + "\n"
    	
    	System.out.println(); // "\n" -> 출력값이 있는 상태
    	//System.out.print();   // 출력값이 없음
    	         // 무언가를 출력하려고 출력문을 작성했는데, 출력값이 없네? 에러 발생.
    	
    	// 입력문 -> 
    	
    	// 정수형 자료형
    	int i = scan.nextInt();
    	long l = scan.nextLong();
    	
    	// 실수형 자료형
    	double d = scan.nextDouble();
    	float f = scan.nextFloat();
    	
    	// ★문자형 자료형★
    	char c = scan.next().charAt(0);
    	String s1 = scan.next(); // " "을 만나면 종료 : 단어나 공백이 포함되지 않은 문장에는 이것이 좋고
    	String s2 = scan.nextLine(); // "\n"을 만나면 종료 : 문장이나 공백이 포함된 긴 문장에는 이것이 좋음 
    	
    	// 
    	
    	char name  = '';
    	int b = 
    	
    }
}
