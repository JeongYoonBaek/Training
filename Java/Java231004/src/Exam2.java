import java.util.Scanner;

// Clock 클래스 구현 - 멤버변수 :: hour=0, minute=0, second=0 (private 선언)
//         		  - 멤버함수 :: printTime() -> 현재시간 출력
//                            AmPm() -> 오전인지 오후인지 출력  
class Clock { 
	// 3개의 멤버 변수들이 모두 0으로 초기화한다.
	private int hour = 0; // 시간 변수 초기화
	private int min = 0;  // 분 변수 초기화
	private int sec = 0;  // 초 변수 초기화 
	
	// 멤버 함수 선언 
	public void printTime() { // printTime() -> 현재시간 출력
		System.out.println("현재 시각은 " + this.hour + "시" + this.min + "분" + this.sec + "초입니다"); 
		// 멤버변수인데 해당 클래스 안에 참조를 하려면 this 사용
	}
	
	public void AmPm() { // AmPm() -> 오전인지 오후인지 출력  
		if(hour < 12) {
			System.out.println("현재는 오전입니다."); // 오전 :: 00시~11시
		}
		else {
			System.out.println("현재는 오후입니다."); // 오후 :: 12시~23시
		}
	}

	public int getHour() {
		return hour;
	}

	public void setHour(int hour) {
		this.hour = hour;
	}

	public int getMin() {
		return min;
	}

	public void setMin(int min) {
		this.min = min;
	}

	public int getSec() {
		return sec;
	}

	public void setSec(int sec) {
		this.sec = sec;
	}
}

public class Exam2 {
	// main 에서 수행할 것들 
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		// Clock 클래스를 통해 c1, c2 객체 각각 생성 
		Clock c1 = new Clock(); // main문에서 클래스를 2개로 생성 
		
		Clock c2 = new Clock(); // main문에서 클래스를 2개로 생성 
		
		// 3개의 입력을 받아 c2 객체 필드 (멤버 변수) 초기화 
		System.out.println("시간을 입력하세요 : ");
		c2.setHour(scan.nextInt()); // set을 사용하여 입력받고 위에 초기화된 값들을 업데이트 시켜줌
		System.out.println("분을 입력하세요 : ");
		c2.setMin(scan.nextInt());  // set을 사용하여 입력받고 위에 초기화된 값들을 업데이트 시켜줌
		System.out.println("초를 입력하세요 : ");
		c2.setSec(scan.nextInt());  // set을 사용하여 입력받고 위에 초기화된 값들을 업데이트 시켜줌
		
	    c1.printTime(); // c1, c2 객체에 대한, printTime() 및 AmPm() 실행
	    c1.AmPm();      // c1, c2 객체에 대한, printTime() 및 AmPm() 실행
	    c2.printTime(); // c1, c2 객체에 대한, printTime() 및 AmPm() 실행
	    c2.AmPm();      // c1, c2 객체에 대한, printTime() 및 AmPm() 실행		
		
	}
}


