public class IfEx6 {
    public static void main(String[] args) {
        // 코드는 가로로 작성하는 것보다 가독성을 위해 세로로 작성하는 것이 보기 좋음

        int num1 = 21; // int형 변수 num1에 21의 값을 저장
        int num2 = 20; // int형 변수 num2에 20의 값을 저장
        int result = num1 - num2; // int형 변수 결과값에 num1과 num2를 뺀 값을 저장

        if (result >= 0) { // 결과값이 0과 같거나 0보다 큰 조건문을 만들어라
            System.out.println("+입니다"); // 조건문이 일치하면 +를 출력하라
        } else {
            System.out.println("-입니다"); // 조건문이 일치하지 않으면 -를 출력하라
        }
    }
}
