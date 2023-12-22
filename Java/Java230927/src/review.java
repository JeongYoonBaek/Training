import java.util.Scanner;

public class review {
        public static void main(String[] args) { // main 작성후 ctrl+스페이스 엔터 
        	Scanner scan = new Scanner(System.in);    	
        	 		// scan을 통해서 입력문 함수를 불러올 수 있다. 
        	
			// 출력문 :: 3가지 (println, printf, print)
        	System.out.println("연휴 전날입니다ㅎㅎ");   // sysout 작성 후 ctrl+스페이스 엔터 
        		 // "연휴 전날입니다" + "\n" 
        	System.out.printf("이번해 추석은 %d월 %d일입니다.\n", 9, 29);
        	System.out.print("즐거운 연휴 되세요!!");
        	  	  // "즐거운 연휴 되세요!!"만 출력 
        	
        	// 입력문 :: Scanner 사용 
        	int i = scan.nextInt();  // 자바가 대소문자 구분에 엄격함. 철자 틀린거 없는데 오류가 있는거 보면 대소문자 확인 잘할것
        	double d = scan.nextDouble();
        	String s1 = scan.next();  	 	// " "을 만나면 실행 종료
        	String s2 = scan.nextLine();	// "\n(Enter)"을 만나면 실행 종료가 안되고 줄바꿈이 됨.
        	char c = scan.next().charAt(0);
        		// scan.next()롱 ㅣㅂ력받은 것 중, 0번째 문자만 뽑아와서 c에 저장한다.
        	
        	// 아스키코드 :: 컴퓨터는 2진법으로 모든 정보를 파악한다, 컴퓨터가 문자 정보를 이해할 수 있도록
        	// 		특정 숫자-문자를 일대일 대응 시킨 약속 
        	//  A :: 65, a :: 97, '0' :: 48
        	
        	// String 관련된 함수 
        	// equals() :: 2개의 문자열을 비교하는 함수 
        	//       (같으면 참 반환,다르면 거짓 반환)
        	// length() :: 문자열 길이 반환 
        	// 	 	"coffee" => length() 값 :: 6, 인덱스 :: 0~5번
        	// charAt() :: String형에 대해서 특장 위치의 문자 접근할 때 사용
        	//      "coffee" => "coffee".charAt(1);
        	// toCharArray() :: String형 -> cahr[]형 변환하는 함수 
        	// 		String str = "SmartPhone";      // str에 대해서는 타입이 변환하지 않음 
        	// 		char ch[] = str.toCharArray();  
        	
        	// 배열 :: 동일한 타입에 대해 여러 공간을 갖는 변수
        	// 배열 선언하는 방법 
        	// 1. 초기화 하면서 선언 
        	// (자료형) (배열명)[] = {(초기화해줄 값)};
        	int number[] = {11, 22, 33, 44, 55}; 		// 자동으로 크기가 5로 지정 
        	String st[] = {"Hello", "Java"}; 			// 크기가 2로 지정 
        	double dnum[][] = {{11.1, 12.2,},{21.1, 22.2, 32.2}}; 	// 2차원 배열 선언하는 방식 
        	
        	// 2. 크기만 할당하여 선언 
        	// (자료형) (배열명)[] = new (자료형) [배열크기];
        	int n[] = new int[5];
            double d[][] = new double [2][3]; // 2*3=6개의 원소 최대한 넣을 수 있음   
            		// 우측에 있는 대괄호와 좌측에 있는 대괄호 크기가 같아야함. 
            		//그리고 크기 지정은 오른쪽에서 해줌 
            
		}
}
