
// 클래스 :: 객체 / 인스턴스를 찍어내는 틀 
class Americano{
	// 멤버 변수 :: 물양, 원액양, 얼음 유무
	private int water;
	private int coffee;
	private String ice; // 얼음 유무

	public int getWater() {
		return water;
	}

	public void setWater(int water) {
		this.water = water;
	}

	public int getCoffee() {
		return coffee;
	}

	public void setCoffee(int coffee) {
		this.coffee = coffee;
	}

	public String getIce() {
		return ice;
	}

	public void setIce(String ice) {
		this.ice = ice;
	}

	// 생성자 :: "객체를 생성하는 메소드 중 일부" 
	// 일반 메소드와의 차이점 :: 1. 반환형이 없다 2. 생성자명 = 클래스명 
	public Americano() { // 매개변수 없는 형태의 생성자
		// 3개의 멤버 변수 초기화
		this.water = 500;
		this.coffee = 250;
		this.ice = "있음";
		// 객체를 생성했음을 알림
		//		System.out.println("객체가 성공적으로 생성되었습니다!!!");
	}

	// 생성자 추가 구현 3개의 매개변수 값으로 멤버 초기화 
	public Americano(int w, int c, String i) {
		this.water = w;
		this.coffee = c;
		this.ice = i;
	}

	// 메소드 구현 :: 1. GoodAme()
	public void GoodAme() {
		// - 물: 커피 비율이 2:1이라면, 황금 비율임을 출력 
		// 2커피 = 1물 
		// if(this.water/this.coffee == 2 && this.water%this.coffee == 0) {
		if(this.coffee*2 == this.water) {
			System.out.println("황금 비율입니다 !!! ");
		}
		// - 물이 많다면 연한 아메리카노임을 출력 
		else if(this.coffee*2 < this.water) {
			System.out.println("연한 아메리카노입니다 !!!");
		}
		// - 물이 적다면 진한 아메리카노임을 출력 
		else {
			System.out.println("진한 아메리카노 입니다!!! ");
		}
	}

	// 2. Amount()  
	public void Amount() {
		int ame = this.water+this.coffee; // 물과 커피의 양을 더한 값을 정수형 ame 변수에 저장한다.
		// 적당량(750ml)이라면, 적당하다고 출력
		if(ame == 750) {
			System.out.println("양이 적당합니다!!!");
		}
		//아메리카노 양이 너무 많다면, 많다고 출력
		else if(ame > 750) {
			System.out.println("양이 많습니다!!!");
		}
		// 아메리카노 양이 너무 적다면, 적다고 출력 
		else  {
			System.out.println("양이 적습니다!!! ");
		}
	}
}

public class Review {
	public static void main(String[] args) {
		// 객체 배열	
		// 1. 배열로 공간 할당 -> 객체 생성
		Americano ame[] = new Americano[2];
//		for(int i = 0; i < 2; i++) {
//			// 객체명 = new [생성자 호출];
//			ame[i] = new Americano();
//			
//		}	
		
		ame[0] = new Americano();		// 비율이 딱 맞고 양이 적당 
		ame[1] = new Americano(1000, 10, "있음");			// 연하고 양이 많은 

		for(int i = 0; i < 2; i++) {
			ame[i].Amount();
			ame[i].GoodAme();
			System.out.println();
		}
	}
}

