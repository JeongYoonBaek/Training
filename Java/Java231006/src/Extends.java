
// 예제 :: 휴대폰, 스마트폰 클래스 생성 및 관계 구성 
// 상속 :: 부모 클래스의 형식을 자식 클래스에 복사/붙여넣기 하여 자신의 것마냥 사용한다. 
//        "멤버를 상속 받아도, 부모 <-> 자식 간 값이 공유되진 않는다."

class Phone{
	// 멤버 변수 :: 전화번호, 폴더 여부 
	public String tel;
	public boolean foldable;
}

class SmartPhone extends Phone{
	// 멤버 변수 :: 전화번호, 폴더 여부, 운영체재, 네트워크(4G/5G)
	// tel과 foldable가 상속받았기 때문에 스마트폰 클래스에서도 멤버변수로 저장됨.
	public String os;   
	public String network;
}

public class Extends {
	public static void main(String[] args) {
        // 상속 :: "부모로부터 자식이 상속받는다."
		//        부모, 자식 -> "상하관계 구성"
		
		// 2개의 객체 생성 
		Phone p = new Phone();
		SmartPhone sp = new SmartPhone();
		
		p.tel = "010-6489-7505";   // 에러 X 자기 자신의 멤버 접근 
//		p.os = "Apple IOS 17";     // 에러 O 다른 클래스의 멤버 접근 
                 // 부모 클래스의 객체 -> 자식 클래스 멤버 접근 X
		
		sp.network = "5G";         // 에러 X 자기 자신의 멤버 접근
	    sp.foldable = true;        // 에러 X, 부모 클래스의 멤버 접근 
		          // 자식 클래스 객체 -> 부모 클래스 멤버 접근 O
	}
}
