public class IfEx4 {
    // 자바에서는 꼭 클래스 내부에 메쏘드와 함수를 선언가능함
    //  int a = 10; 클래스 내부에서 선언한 멤버 변수 (메쏘드 안에서 선언한 변수는 멤버 변수가 아님)
    public static void main(String[] args) {

        String str = "+";
        // 문자열 비교할때는 str.equals("a")을 사용함
        if (str.equals("a") || (str.equals("b") || (str.equals("c")) { // 만약 str이 "a"이거나 "b"이거나 "c" 조건문을 출력
            System.out.println("영문입니다."); // 영문입니다 출력
        } else if (str.equals("1") || (str.equals("2") || (str.equals("3")) { // 만약 str이 1,2,3일때 조건문을 출력
            System.out.println("숫자입니다"); // 숫자입니다 출력
        } else if (str.equals("+") || (str.equals("-") || (str.equals("*") || (str.equals("/"))
        { // 만약 str이 +,-,*,/일때 조건문을 출력
            System.out.println("연산자입니다"); // 연산자입니다 출력
        }
    }
}


