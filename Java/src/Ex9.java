import java.util.Scanner; // C언어 include와 동일한 형태임

public class Ex9 {
    public static void main(String[] args) {
        // 임의의 정수를 입력 받아 입력 받은 정수의 모든 약수를 출력하는 프로그램을 작성하라
        // ex) 12 약수 ) 12 % 1 == 0 (12 나누기 1은 12니까 나머지 0)
        // 이런 식으로 출력하는 프로그램을 설계
        // 반복문 작성은 i가 0~12까지 반복

        // 입력 받기 위한 객체 선언
        // Scanner scanner = new Scanner(System.in); // in은 scanner에서 입력 받을 수 있는 객체임
        // 입력 받으면 무조건 String으로 넘어옴. 숫자가 int형태인데 String으로 넘어옴

        // int input을 선언하고 입력받아 저장한다.
        System.out.println("숫자 입력 : ");
        String str = scanner.nextLine();
        int input = Integer.parseInt(str);
        // Double.parseDouble()

        int num = 12; // int num 변수에 임의의 값을 저장
        for (int i = 0; i <= input; i++) {// i가 0부터 12까지 반복하는 반복문을 작성  // i는 1부터 input까지 반복
            if (input % 1 == 0) { // 12의 약수를 구하는 조건문을 출력  // - 만약 input % i == 0이면
                System.out.println(i); // 12의 약수를 출력  // -- 출력 i
            }
        }
    }
}

