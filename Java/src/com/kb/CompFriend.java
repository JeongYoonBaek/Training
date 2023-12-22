package com.kb;

public class CompFriend extends Friend {
    // 멤버변수
    // String형 부서
    private String department;

    // 생성자 - params : 이름, 부서, 전화번호

    public CompFriend(String name, String department, String phoneNo) {
        super(name, phoneNo);
        this.department = department;
    }


    // 메소드명 : showInfo()
    // 기능 : 이름, 부서, 전화번호 출력
    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("부서 : " + this.department);
    }
}