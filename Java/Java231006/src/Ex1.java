//
//// Clock 클래스 
//class Clock{
//	// 멤버 변수 :: hour, minute, second
//	public int hour;
//	public int minute;
//	public int second;
//
//	public int getHour() {
//		return hour;
//	}
//
//	public void setHour(int hour) {
//		this.hour = hour;
//	}
//
//	public int getMinute() {
//		return minute;
//	}
//
//	public void setMinute(int minute) {
//		this.minute = minute;
//	}
//
//	public int getSecond() {
//		return second;
//	}
//
//	public void setSecond(int second) {
//		this.second = second;
//	}
//
//	// 메소드 :: Setting(int, int, int) :: 시간 설정
//	public void Setting(int h, int m, int s) {
//		this.hour = h;
//		this.minute = m;
//		this.second = s;
//	}
//}
//
//// Watch 클래스 
//class Watch extends Clock {
//	// 멤버 변수 :: hour, minute, second, StrapColor 
//	this.hour = h;
//	this.minute = m;
//	this.second = s;
//	public String StrapColor; 
//
//	// Setting(int, int, int) :: 시간설정, StrapColor = "Black"
//	public void Setting(int h, int m, int s) {
//		this.hour = h;
//		this.minute = m;
//		this.second = s;
//	}
//	
//	//Setting(int, int, int, String) :: 시간 및 시계줄 색상 설정
//	public void Setting(int h, int m, int s, String c) {
//		this.sethour(h);
//		this.minute = m;
//		this.second = s;
//		this.StrapColor = "Blue";
//	}
//}
//
//// SmartWatch 클래스 
//class SmartWatch{
//	// 멤버 변수 :: hour, minute, Second, StrapColor, os 
//	public int hour;
//	public int minute;
//	public int Second;
//	public String StrapColor;
//	public String os;
//
//	// 메소드 :: Setting(int, int, int) :: 시간설정, StrapColor = "Black", os = "null"
//	public void Setting(int h, int m, int s) {
//		this.hour = h;
//		this.minute = m;
//		this.Second = s;
//		this.StrapColor = "Blue";
//		this.os = "IOS";
//	}
//	
//	// 메소드 :: Setting(int, int, int, String) :: 시간 및 시계줄 색상설정 StrapColor = "Black", os = "null"
//	public void Setting(int h, int m, int s, String c) {
//		this.hour = h;
//		this.minute = m;
//		this.Second = s;
//		this.StrapColor = "Blue";
//		this.os = "IOS";
//	}
//	
//	// 메소드 :: Setting(int, int, int) :: 시간 및 시계줄 색상, os 설정  StrapColor = "Black", os = "null"
//	public void Setting(int h, int m, int s, String c, String o) {
//		this.hour = h;
//		this.minute = m;
//		this.Second = s;
//		this.StrapColor = "Blue";
//		this.os = "IOS";
//	}
//}
//
//public class Ex1 {
//	public static void main(String[] args) {
//		Clock c = new Clock();
//		Watch w = new Watch();
//		SmartWatch sw = new SmartWatch();
//		
//	}
//}
//
//
//
