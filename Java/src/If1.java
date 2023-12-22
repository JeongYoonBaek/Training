public class If1 {
    public static void main(String[] args) {
        int n1 = 5;
        int n2 = 7;

        // 만약 n1 > n2라면
        // " n1 < n2 is true" 출력


        if (n1 < n2) {
            System.out.println(" n1 < n2 is true");
        }

    }
    if(n1 == n2)

    {
        // 만약 n1 == n2라면
        // "n1 == n2 is true" 출력

        System.out.println("n1 == n2 is true");
    }
    // 아니라면
    //"n1 == n2 is false" 출력
    else
    {
        System.out.println("n1 == n2 is false");
    }
    int num = 120;
    // num < 0이라면
    // 아니고 num < 100이라면

    if (num<0) {
        System.out.println("0 미만");
    }
   else ( num < 100) {
        System.out.println("100 이상");
    }


