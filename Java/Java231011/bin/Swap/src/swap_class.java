
// Java로 swap 구현해보기 
// hint : class 이용하기 
// class 아니더라도 참조변수 속성을 이용하면 됨
// 참고로 자바에는 포인터와 ref가 없음
// 글로벌 변수 쓰지말 것(전역변수)

class Swap{
	public int swap = 1000;
	public int swap2 = 500;
}

public class swap_class {
	public static void swap(Value v1, Value v2)
	{
		int temp = v1.value;
		v1.value = v2.value;
		v2.value = temp;
	}
	
	public static void main(String[] args) {
		Value v1 = new Value();
		Value v2 = new Value();
		v1.value = 3;
		v2.value = 5;
		swap(v1,v2);
		System.out.println(v1.value);
		System.out.println(v2.value);
	}
}
