package com.kb;

public class Man {
    private String name;

    public Man(String name) {
        this.name = name; // 상속받은 상위 클래스 변수가 여기에 들어감
    }

    public void tellYourInfo() {
        System.out.println("My name is " + this.name);
    }
}
