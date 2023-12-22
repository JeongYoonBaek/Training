package com.kb;

public class Friend {
    // 멤버변수
    // String 이름
    private String name;
    // String 전화번호
    private String phone;

    // 생성자 params : 이름, 전화번호
    public void Friend(String name, String phone) { // alt+insert constructor 클릭 후 모두 선택
        this.name = name;
        this.phone = phone;
    }

    // method : showInfo()
    public void showInfo() {
        System.out.println("이름 : " + this.name);
        System.out.println("전화 : " + this.phone);
    }
}