public class Opperation {
    public static void main(String[] args) {
        BankAccount ba1 = new BankAccount(10000, "a"); // 첫 번째 계좌

        BankAccount ba2 = new BankAccount(5000, "b"); // 두 번째 계좌

        ba1.deposit(10000);
       // System.out.println(ba1.getBalance()); // 잔고 볼 수 있음

        ba2.withdraw(10000);

        ba1.withdraw(10001);


    }
}
