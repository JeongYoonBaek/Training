import java.util.Scanner;

public class exam2 {
	public static void main(String[] args) {
	
		// 문장을 입력받고
		// 문장에 대한 26개의 알파벳에 대한 각 빈도수를 측정하여 각각 출력하라.
		// (대문자 및 소문자를 모두  포함하여 입력받는다고 가정한다.)
		// (다만, 한번도 나타나지 않은 알파벳은 출력하지 않도록 한다)
		// ex) 입력값 :: Hello
		// <출력 결과>
		// e : 1개 
		// h : 1개
		// l : 2개
		// o : 1개
		
		// 알파벳 빈도 저장하는 배열(alpha) 별도 선언
		// A와 a의 횟수 :: alpha[0]에 저장
		// B와 b의 횟수 :: alpha[1]에 저장 
	    // .... Z와 z의 횟수 :: alpha[25]에 저장
		// A~Z (65~90) -> 0~25
		// a~z (97~122) -> 0~25
		
		// 문제 :: 문장을 입력받고, 문장에 포함된 각 알파벳 개수 출력하기
		// 1. 문장 입력받기
		Scanner scan = new Scanner(System.in);
		String st = scan.nextLine();
		
		// 2. 문장에 포함된 알파벳 각 빈도수 측정 
		// -> 알파벳 빈도 저장하는 배열(alpha) 별도 선언
		int alpha[] = new int [26]; // 정수형 배열 생성 
		for(int i = 0; i < st.length(); i++) {  // 0번~(문자열 길이-1)까지
            // 'A' ::65, 'a' ::97		
			char ch = st.charAt(i); // 문자열 변수 생성 
			if(ch >='A' && ch <= 'Z') { // 대문자인 경우
			   alpha[ch-'A']++; // (문자열 변수 - A) A:65니까 EX) H-A = 7 그러면 alpha[7]이 됨.
			}
			if(st.charAt(i)>='a' && st.charAt(i) <= 'z') { // 소문자인 경우 
				alpha[ch-'a']++;
			
			}
		}
		
		for(int i = 0, j = 65; i < 26; i++, j++) { // 알파벳 범위만큼 반복문 실행  대문자 A부터 시작해서 소문자 z까지 출력함
			// 0인 경우는, 해당 알파벳이 아예 안 나온 경우 
			if(alpha[i]>0) {
				System.out.println((char)j +": " + alpha[i]); // 입력 후 해당 알파벳 빈도수 측정
			}
			
			/*System.out.println((char)(i+'A')+": " + alpha[i]);   // 대문자 알파벳 빈도수 측정 
			System.out.println((char)(i+'a')+": " + alpha[i]);  */ // 소문자 알파벳 빈도수 측정 
		}
		
			
			
			
			
		/* // 입력문 선언
		int alpha[] = new int [26]; // 자바 배열선언 방법 
		char c = scan.nextLine();
		for(int i = 0; i < alpha.length(); i++) {
			if (alpha[i]>= 'A' && alpha[i] <= 'Z') {
				System.out.println((int)c);
			}
		}
			int alpha2[] = new int [26];
			String alpha[] = scan.nextLine();
			for(int j = 0; j < alpha2.length(); j++) {
			if (alpha2[j] >= 'a' && alpha2[j] <= 'z') {
				
			}
		}
		*/
	
	   
		
	    
		
		
		
		
		
		
	    
	}
		
}
