package com.kb;

public class BusinessMan extends Man {

    public BusinessMan(String company, String position, String name) {
        super(name); // 상속받은 상위 클래스 생성자는 제일 위에서 선언 해야함
        this.company = company; // alt+ insert 후 constructor 선택후 클릭
        this.position = position;
    }

    private String company;
    private String position;

   @Override // 이 메소드는 Override가 되어 있다. (어노테이션이라고도 부름)
    public void tellYourInfo() {
        System.out.println("My company is" + this.company);
        System.out.println("My position is" + this.position);
        super.tellYourInfo(); // com.kb.Man 클래스를 상속했기 때문에 호출 가능!
        // super : 상위 클래스의 생성 호출자
    }
}
