import java.util.Scanner;

// Account 클래스 생성 
// - 멤버 변수 :: acc_num(회원번호), id(아이디), password(비밀번호)
class Account {
	private String acc_num;
	private String id;
	private String password;

	// 3개 멤버변수 값 출력 
	public void Print() {
		
		System.out.println("사원번호 " + this.acc_num);
		System.out.println("ID : " + this.id);
		System.out.println("비밀번호 : " + this.password);
	}
	
	// 2. changePw(String) :: 매개변수 값으로 비번 변경 다만, 5자리를 넘기지 않으면 에러메시지 출력
	public void changePw(String p) {
           if(p.length() < 5 ) {
        	   System.out.println("Error!!! ");
           }
           else {
        	   System.out.println("변경되었습니다!!! "  );
        	   this.password = p;
           }
	}
	
	// 생성자 :: "0000", "ex", "0000"으로 초기화    
	public Account () {
		this.acc_num = "0000";
		this.id = "ex";
		this.password = "0000";
		
	}
	// 3개의 멤버 변수 매개 변수 통해 초기화 
	public Account (String n, String id, String p) { // 오버로딩 개념!!
		this.acc_num = n; 
		this.id = id;
		this.password = p;
	}
  
public String getAcc_num() {
		return acc_num;
	}

	public void setAcc_num(String acc_num) {
		this.acc_num = acc_num;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

public class Exam1 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		// main에서 실행할 내용 
		// - manager[3] 객체 생성 (임의의 값으로 설정하는 생성자)
		Account manager[] = new Account[3]; 

		// - manager[3] id, password 값 코드 상에서 임의로 수정 (set 사용..?)
		for(int i = 0; i < 3; i++) {
			// id 수정
		manager[i].setId("2222");
			// 비밀번호 수정
		manager[i].setPassword("2222");
		}
		
		// - manager[3] 순차적으로 정보 출력 
		for(int i = 0; i < 3; i++) {
			if(password.length() < 5)
		}
			manager[i].Print();
		}
		
		// user 객체 생성 (main에서 입력 받아서 초기화)
        Account user = new Account();
		// - user 정보 순차적으로 출력 
    	System.out.println("사원번호 " + user.getAcc_num());
        	 
         }
         user.Print();
		// - user 객체에 대해 changePw(String) 수행 

	}
}
