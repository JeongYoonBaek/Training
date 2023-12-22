import java.util.Scanner;

public class exam {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		// 1. 숫자 n을 입력받고
		// 1부터 n까지숫자 중 짝수만 추려내어 출력하고
		// 짝수들끼리의 합을 마지막에 출력하도록 하여라 

		int n = scan.nextInt();
		int hap = 0;
		for(int i = 1; i <= n; i++) {
			System.out.println("숫자를 입력하세요 :");
			System.out.println(i);
			hap += i;
		}
		System.out.println("짝수들의 합: " + hap);
	}
}
