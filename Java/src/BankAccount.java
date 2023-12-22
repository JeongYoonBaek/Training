public class BankAccount {
    private int balance;   // 잔고

    private String name;   // 계좌주 성명

    // 클래스에 속해 있는 멤버 변수들과 메소드들.
    public BankAccount() { // 디폴트 생성자
    }

    public BankAccount(int balance, String name) {
        if (balance < 0) {
            System.out.println("마이너스 통장 불가");
            balance = 0;
        }
        this.name = name; // 고객명을 코드를 입금 코드보다 먼저 입력
        deposit(balance);
    }

    // 입금
    public void deposit(int amount) { // 입금
        this.balance += amount;
        System.out.println(amount + "원이 입금처리 되었습니다.");
        this.showBalance();
    }

    // public void deposit(String abc) { // 입금 (파라메터 명 다르게 하면 위에 메소드에 빨간줄이 안생김
    // }

    //출금
    public void withdraw(int amount) { // 출금
        if (this.balance < amount) {
            System.out.println("잔고가 부족합니다.");
            this.showBalance();
            return;
        }
        this.balance -= amount;
        System.out.println(amount + "원이 출금처리 되었습니다.");
        this.showBalance(); // 잔고 보여 주기
    }

    // 데이터셋
    public void showBalance() {
        System.out.println(this.name + "현재 잔고" + this.balance);
        // 고객의 이름과 함께 현재 잔고를 알려줌
    }
}
