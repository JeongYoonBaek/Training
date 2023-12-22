public class IfEx3 {
    public static void main(String[] args) {
        // 임의의 양의 정수가 3의 배수이면 3의 배수
        // 4의 배수이면 4의 배수
        // 둘다 아니면 알수없음
        int num = 6; // int num을 선언하고 임의의 정수를 저장한다

        if (num % 3 == 0) { // 3의 배수이면 3의 배수입니다 조건문 입력
            System.out.println("3의 배수입니다");
        } else if (num % 4 == 0) { // 4의 배수이면 4의 배수입니다 조건문 입력
            System.out.println("4의 배수입니다"); // 4의 배수입니다를 출력
        } else {
            System.out.println("알수 없음"); // 알수없음을 출력
        }
    }
}