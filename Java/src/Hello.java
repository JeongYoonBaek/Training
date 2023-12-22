// 데이터 형식이 달라도 main문에서 적으면 동일 하게 처리 가능
// 자바에서는 double, int unsigned을 안씀 float을 자주 씀
// char대신에 String으로 문자열 처리 가능
// ctrl + alt + l 전체 코드 정리 가능. 대괄호 지울땐 꼭 쌍으로 지울것!!

public class Hello {
    public static void main(String[] args) {
        long c = 999999999999L; // L붙어주면 큰 숫자 방지
        int b = (int) c;

        System.out.println(b);
         }
}