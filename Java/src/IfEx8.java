public class IfEx8 {
    public static void main(String[] args) {
        // 두 개의 양의 정수와 사칙 연산 기호 (+,-,*,/) 중 하나를 입력 받아 계산 결과를 출력하는
        // 계산 프로그램을 작성 하시오
        int num1 = 10;
        int num2 = 5;
        int result = 0;
        String oper = "-";

        if (oper.equals("+")) {
            System.out.println(num1 + num2);// +의 연산 기호를 입력 받는 조건문을 출력
        } else if (oper.equals("-")) {
            System.out.println(num1 - num2); // -의 연산 기호를 입력 받는 조건문을 출력
        } else if (oper.equals("*")) {
            System.out.println(num1 * num2); //  *의 연산 기호를 입력 받는 조건문을 출력
        } else if (oper.equals("/"))
            System.out.println(num1 / num2);  // /의 연산 기호를 입력 받는 조건문을 출력
    }
}







