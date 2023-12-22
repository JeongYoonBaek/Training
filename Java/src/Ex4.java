public class Ex4 {
    public static void main(String[] args) {
        // 변수 n1, n2, n3가 다음과 같을 때 n1 > n2 > n3이면 true, 아니면 false를 출력하는 프로그램을 작성하라
        int n1 = ((25 + 5) + (36 / 4) - 72) * 5;   // 변수 n1을 선언하고 ((25 + 5) + (36 / 4) - 72) * 5 저장
        int n2 = ((25 * 5) + (36 - 4) + 71) / 4; // 변수 n2을 선언하고 ((25 + 5) + (36 - 4) - 72) / 4 저장
        int n3 = (128 / 4) * 2;  // 변수 n3을 선언하고 (128 / 4) * 2 저장
        System.out.println(n1 > n2 && n2 > n3);

        // n1 > n2 > n3 == n1 > n2 && n2 > n3 결과 출력
    }
}
