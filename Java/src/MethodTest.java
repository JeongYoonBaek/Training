public class MethodTest {
    public static void main(String[] args) {
        int age = getMyAge(age:20, name:"백정윤");
        System.out.println(age); // 메소드, 멤버변수 전부 클래스 안에서 작성
    }

    public static int getMyAge(int age, String name) { // 소괄호 사이에 파라메터가 들어감, 메소드는 동사로 작성
        String name1 = "백정윤"; // 지역변수기 때문에 다른 함수에 호출 불가 (스코프 개념)
        return age; // 중괄호 사이에 자바 코드가 들어감
    }

    public static int getMyAge(int age) { // 소괄호 사이에 파라메터가 들어감, 메소드는 동사로 작성
        return age; // 중괄호 사이에 자바 코드가 들어감
    }
}
