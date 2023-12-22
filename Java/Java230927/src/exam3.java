import java.util.Scanner;

public class exam3 {


	// getHour(int s) :: 초 정보를 받고, 시 정보를 반환
	public static int getHour(int s) {
		// 1시간 :: 3600초 , 2시간 7200초, ... 
		return s / 3600;
	}
	// getMin(int s) :: 초 정보를 받고, 분 정보를 반환
	public static int getMin(int s) {
		// 이때 분 정보가 60분을 넘어서면 안된다. 
		// 1시간 = 60분 = 3600초
		return (s % 3600) / 60; // s 나머지 3600은 시간만 출력할 수 있는 문자만 배제했고, /60으로하면 분단위까지 나옴
	}
	// getSec(int s) :: 분으로 환산 불가능한 초 정보 반환 
	public static int getSec(int s) {
		return s % 60; 	// (s % 3600) % 60;과 동일함
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		// main에서 입력받은 Sec(초) 정보를 h시 m분 s초로 출력하게끔 코드를 작성하여라.
		// 다만, 아래의 함수를 용도에 맞게 구현하고 적절히 사용하라. 
		// 입력과 출력 모두 main에서 수행하도록 하라. 
		// 86400초 (24시간) 이상의 값에 대해선 오류 메시지 출력)
		// /, %, 60, 3600 잘 사용 해야함 

		// 입력값 :: 86399 -> 23시 59분 59초
		// 23시 => getHour() 통해 23 반환
		// 59분 => getMin() 통해 59 반환
		// 59초 => getSec() 통해 59 반환 

		// 1. sec 정보 입력받기 
	    System.out.print("초 입력 : ");
	    int s =scan.nextInt();

		// 2. sec 정보 -> h시 m분 s초로 출력
		// 단, 86400초 이상의 값에 대해선 오류 메시지 출력 
	    if (s < 86400) {
	    	System.out.println(getHour(s) + "시" + getMin(s) + "분" + getSec(s) + "초");
	    }
	    else if (s >= 86400) {
	    	System.out.println("Error!!!");
		}
	}
}
