import java.util.Scanner;

public class String_fun {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		// String 관련 함수
		// 1. equals() 함수 
		String s1 = scan.next();
		String s2 = "abc";
		System.out.println(s1.equals(s2)); // ==은 숫자끼리 비교할 때 사용 권장. 
	 	                                   //문자열 같은 경우는 되도록이면 equals() 사용권장
		 
		// 2. length() 함수 : : 문자열 길이/크기를 반환하는 함수
        System.out.println("입력값의 길이: " + s1.length());
        
        // 3. charAt(i) 함수 : : i를 넣은 이유는 매개변수가 있기 때문 (i번째 요소에 접근/반환하는 함수)
        System.out.println("1번째 요소 : " + s1.charAt(0));
        System.out.println("2번째 요소 : " + s1.charAt(1));
        System.out.println("3번째 요소 : " + s1.charAt(2));
        
        // 4. StringtoChar() 함수 : : String -> char형 배열로 변환 (값은 그대로, 
        char ch[] = s1.toCharArray();
        System.out.println("1번째 요소 : " + ch[0]);
        System.out.println("2번째 요소 : " + ch[1]);
        System.out.println("3번째 요소 : " + ch[2]);
        
	}
}
