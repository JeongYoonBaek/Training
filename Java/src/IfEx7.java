public class IfEx7 {
    public static void main(String[] args) {
        // 임의의 두 정수를 비교하여 첫 번째 정수가 두 번째 정수보다 크고 짝수이면 안녕하세요를 출력하는
        // 프로그램을 작성하라
        int num1 = 22; // int형 변수 num1에 22의 값을 저장하라
        int num2 = 20; // int형 변수 num2에 20의 값을 저장하라

        if (num1 > num2 && num1 % 2 == 0) { // 첫 번째 정수가 두 번째 정수보다 크고 짝수인 조건문 만들어라
            System.out.println("안녕하세요"); // 조건문에 성립하면 안녕하세요를 출력
        }
    }
}
