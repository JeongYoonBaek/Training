
// 오버로딩 :: "매개변수 구성이 다르면, 함수명이 같아도 함께 사용할 수 있다."
// 오버라이딩 :: "부모 클래스에 정의되어있는 메소드를 자식 클래스에서 재정의 / 덮어쓰기"

// Clock 클래스
class Clock {
	// 멤버 변수 :: hour, minute, second
	private int hour;
	private int minute;
	private int second;

	public int getHour() {
		return hour;
	}

	public void setHour(int hour) {
		this.hour = hour;
	}

	public int getMinute() {
		return minute;
	}
	
	public void setMinute(int minute) {
		this.minute = minute;
	}

	public int getSecond() {
		return second;
	}

	public void setSecond(int second) {
		this.second = second;
	}

	// 멤버 함수 :: Setting(int, int, int) :: 시간 설정
	public void Setting(int h, int m, int s) {
		this.hour = h;
		this.minute = m;
		this.second = s;
	}
}

// Watch 클래스
class Watch extends Clock { // hour, minute, second 멤버 상속
	// "Clock 클래스는 부모 클래스, Watch 클래스는 자식 클래스"
	// 멤버 변수 :: hour, minute, second, StrapColor

	private String StrapColor;

	public String getStrapColor() {
		return StrapColor;
	}

	public void setStrapColor(String strapColor) {
		StrapColor = strapColor;
	}

	// 멤버 함수 :: Setting(int, int, int) :: 시간설정, StrapColor = "Black"
	public void Setting(int h, int m, int s) { // 함수의 선언 자체로는 충돌 및 에러가 발생하지 않음
		// Watch 객체는, 부모 클래스보다 자기 자신의 내용을 우선시 함
		this.setHour(h);
		this.setMinute(m);
		this.setSecond(s);
		this.StrapColor = "Blue";
	}

	// Setting(int, int, int, String) :: 시간 및 시계줄 색상설정 StrapColor = "Black", os =
	// "null"
	public void Setting(int h, int m, int s, String st) {
		// this.setHour(h);
		// this.setMinute(m);
		// this.setSecond(s);
		this.Setting(h, m, s); // 오버로딩 개념이기에 위에 있는 함수 참조
		this.StrapColor = st;
	}
}

// SmartWatch 클래스
class SmartWatch extends Watch {
	// "Watch 클래스는 부모 클래스, SmartWatch 클래스는 자식 클래스"
	// 멤버 변수 :: hour, minute, second, StrapColor, os
	private String os;

	// 메소드 :: Setting(int, int, int) :: 시간설정, StrapColor = "Black", os = "null"
	public void Setting(int h, int m, int s) {
		this.setHour(h);
		this.setMinute(m);
		this.setSecond(s);
		this.setStrapColor("Blue");
		this.os = "IOS";
	}

	// 메소드 :: Setting(int, int, int, String) :: 시간 및 시계줄 색상설정 StrapColor = "Black",
	// os = "null"
	public void Setting(int h, int m, int s, String st) {
		this.Setting(h, m, s); // 오버로딩 개념이기에 위에 있는 함수 참조
		this.setStrapColor(st);
	}

	// 메소드 :: Setting(int, int, int) :: 시간 및 시계줄 색상, os 설정 StrapColor = "Black", os
	// = "null"
	public void Setting(int h, int m, int s, String st, String o) {
		this.Setting(h, m, s, st);
		this.os = o;
	}
}

public class Overriding {
	public static void main(String[] args) {
		// 객체 생성
		// Clock의 메소드 1개
		Clock c = new Clock();
		c.Setting(10, 10, 10);

		// Watch의 메소드 2개
		Watch w = new Watch();
		w.Setting(15, 20, 30);
		w.Setting(15, 30, 30, "Blue");

		// SmartWatch의 메소드 3개 
		SmartWatch sw = new SmartWatch();
		sw.Setting(20, 30, 40);
		sw.Setting(22, 25, 35, "Blue");
		sw.Setting(23, 59, 59, "Blue", "IOS");

		System.out.println("Clock의" + "현재 시각은 " + c.getHour() + "시 " + c.getMinute() + "분 " + c.getSecond() + "초 입니다. ");
		System.out.println("Watch1의" + "현재 시각은 " + w.getHour() + "시 " + w.getMinute() + "분 " + w.getSecond() + "초 입니다. ");
		System.out.println("Watch2의" + "현재 시각은 " + w.getHour() + "시 " + w.getMinute() + "분 " + w.getSecond() + "초 입니다. ");
		System.out.println("Watch2의" + "시계줄 색상 : " + w.getStrapColor());
		System.out.println("Smart Watch1의" + "현재 시각은 " + sw.getHour() + "시 " + sw.getMinute() + "분 " + sw.getSecond() + "초 입니다. ");
		System.out.println("Smart Watch2의" + "현재 시각은 " + sw.getHour() + "시 " + sw.getMinute() + "분 " + sw.getSecond() + "초 입니다. ");
		System.out.println("Smart Watch3의" + "현재 시각은 " + sw.getHour() + "시 " + sw.getMinute() + "분 " + sw.getSecond() + "초 입니다. ");
		System.out.println("Smart Watch의" + "시계줄 색상 : " + sw.getStrapColor());
		//System.out.println("Smart Watch의" + "운영 체재 : " + sw.os());
	}
}
