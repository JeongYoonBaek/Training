public class IfEx1 {
    public static void main(String[] args) {
        int num = 120; // int형 변수 num에 120 값을 저장한다
        if (num > 0 && (num % 2) == 0) { // 만약 num이 양수이거나 짝수인 조건문을 작성한다
            System.out.println("양수이면서 짝수"); // 출력
        }
    }
}