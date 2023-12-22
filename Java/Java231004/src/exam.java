import java.util.Scanner;

public class exam {
	// 오늘 날짜 (월, 일)를 입력 받고 이번 해가 끝나기까지 몇 일이 남았는지 출력하기.
	// - main에서 입출력 수행하기 
	// - getDaily 함수 -> 월, 일 정보를 통해 연말까지 몇 일 남았는지 (반환하는) 함수 구현
	// - 출력 형식은 자유롭게, 결과값만 잘 나오면 됨 

	// 2월 :: 28일
	// 1, 3, 5, 7, 8, 10, 12 :: 31일
	// 4, 6, 9, 11월 :: 30일 
	public static int getDaily(int mon, int day) {

		// 위에 변수 초기화 시켜주고 반복문 안에서 조건을 걸어 카운트로 누적 시키는 원리  
		int count = 0; // 1월 1일부터 현재 날짜까지 측정하는 변수 
		for (int i= 1; i < mon; i++) { // 1월부터 n월 이전까지 루프 
			if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) { // 31일까지인 달 조건문 적용
				count += 31;  // 해당 달은 31일까지 있으므로 카운트 변수로 누적 시켜줌 
			}
			else if(i == 4 || i == 6 || i == 9 || i == 11) { // 그렇지 않은 경우 30일까지인 달 조건문 적용
				count += 30;  // 해당 달은 30일까지 있으므로 카운트 변수로 누적 시켜줌 
			}
			else {  		// 위 조건문에 해당하지 않는 2월달은 else로 적용시켜도 됨 
				count += 28; 		// 2월은 28일까지이므로 카운트 변수로 누적 시켜줌
			}
		}
		return 365 - count- day; // 연말까지 몇 일 남았는지 반환 
		// 365 - (1/1부터 현재 날짜까지의 일수) 반환 
	}
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		System.out.println("월을 입력하세요"); 
		int mon = scan.nextInt();		// 월 정보 입력 
		System.out.println("일을 입력하세요");
		int day = scan.nextInt();	    // 일 정보 입력 
       
		// 2. 연말까지 남은 일수 측정 및 출력 -> getDaily 함수 호출
		System.out.println("새해까지" + getDaily(mon, day) + "일 남음"); 
	}
}
