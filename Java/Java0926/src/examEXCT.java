import java.util.Scanner;

public class examEXCT {
	public static void main(String_fun[] args) {
		Scanner scan = new Scanner(System.in);
		// 아래의 입력값을 받고 출력을 수행
		// 이름, 나이, 혈액형(char), 키(double), 자기소개 
		
		String_fun name = scan.next();
		int age = scan.nextInt();
		char blood = scan.next().charAt(0);
		double tall = scan.nextDouble();
		String_fun buffer = scan.nextLine(); // 입력 간 충돌을 위해, 엔터값 먹어주는 입력값 작성 
		String_fun intro = scan.nextLine();
	  	
		
    	System.out.println("이름 : " + name);
    	System.out.println("나이 : " + age+ "세");
    	System.out.println("혈액형 : " + blood+ "형");
    	System.out.println("키 : " + tall+ "Cm");
    	System.out.println("자기소개 : " + intro);
    	
		}
}
