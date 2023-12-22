
// 예제 :: 휴대폰 클래스 생성
// 클래스 구현은 
// class 클래스명 { 
// 멤버 선언 :: 멤버 변수(필드), 멤버 함수(메소드), 생성자  
// }
class Phone{
	// 멤버 변수 선언 
	private String os;	// 운영체재
	private int year;   // 출시년도
	private String color;  // 색상 
	private String Model; // 휴대폰 모델

	public String getOs() {
		return os;
	}

	public void setOs(String os) {
		this.os = os;
	}

	public String getModel() {
		return Model;
	}

	public void setModel(String model) {
		Model = model;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}

	// 메소드 선언 (메소드 오버로딩)
	// [접근제어자] [반환형] [함수명](매개변수구성){
	//        명령문
	// }
	public void print() {  	// 이 것은 출력하는 담당!
		System.out.println("운영체재 :: " + this.os);
		System.out.println("출시년도 :: " + this.year);
		System.out.println("색상 :: " + this.color);
		System.out.println("휴대폰 모델  :: " + this.Model);
	}

	public void print(String o, int y, String c, String m) { // 오버로딩 개념 적용함 
		// 멤버들의 정보를 갱신하면서 
		this.os = o;      // "이 객체의 os 값을 o 값으로 저장한다."
		this.year = y;    // 직접 접근이 가능하므로 set 함수를 쓸 필요가 없다
		this.color = c;
		this.Model = m;

		// 즉시 출력
		this.print();	  // Print(o,y,c,m)와 print()는 독립된 함수 
	}
}

public class Review {
	public static void main(String[] args) {
		// 객체 :: "클래스를 통해 만들어진 실체"
		// 인스턴스 :: "클래스를 통해 만들어진 것" 
		//           "객체가 인스턴스들을 포함하는 개념"
		// 클래스 ::  "객체를 찍어내는 틀"
         
		// 객체 생성 
		// [클래스명] [인스턴스명] = new [클래스명]();
		Phone p = new Phone();	// p 객체 생성 

		// 멤버 접근
		// [인스턴스명].[멤버명]
		p.setOs("Apple IOS");
		p.setYear(2023);
		p.setColor("Black");
		p.setModel("Iphone 15 Pro");
		
		//System.out.println("운영체재 :: " + p.getOs());
		//System.out.println("출시년도 :: " + p.getYear() + "년");
		//System.out.println("색상 :: " + p.getColor());
		//System.out.println("휴대폰 모델 :: " + p.getModel());

		p.print();
		System.out.println();
		p.print("Apple IOS", 2023, "Black", "Iphone 15 Pro");
	}
}
