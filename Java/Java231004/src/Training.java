import java.util.Scanner;

//Clock 클래스 구현 - 멤버변수 :: hour=0, minute=0, second=0 (private 선언)
// - 멤버함수 :: printTime() -> 현재시간 출력
//          AmPm() -> 오전인지 오후인지 출력  

class Clock {
	private int hour = 0; // 멤버 변수는 웬만하면 private를 사용. 
	private int min = 0;
	private int sec = 0;

	public int getHour() {
		return hour;
	}
	public void setHour(int hour) {
		this.hour = hour; // 이 클래스 안에 있는 멤버변수를 쓰기 위해 this 사용
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
	public void printTime() {
		System.out.println("현재시간은 " + this.hour + "시" + this.min + "분" + this.sec + "초입니다.");
	}
	public void AmPm() { // 메소드
		if(hour < 12) {
			System.out.println("오전입니다.");
		}
		else {
			System.out.println("오후입니다.");
		}
	}
}

public class Training {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		Clock c1 = new Clock(); // 객체 생성 
		Clock c2 = new Clock(); 

		System.out.println("시간을 입력하세요 : ");
		c2.setHour(scan.nextInt());
		System.out.println("분을 입력하세요 : ");
		c2.setMin(scan.nextInt());
		System.out.println("초를 입력하세요 : ");
		c2.setSec(scan.nextInt());

		c1.printTime();
		c1.AmPm();
		c2.printTime();
		c2.AmPm();
	}
}
