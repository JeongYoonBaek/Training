package com.kb;

public class UnivFriend extends Friend {
    // 멤버변수
    // String형 전공
    private String major;

    // 생성자 - params : 이름, 전공, 전화번호

    public UnivFriend(String name, String major, String phoneNo) {
        super(name, phoneNo);
        this.major = major;
    }

    /**
     * method name : showInfo
     * access : public
     * params : none
     * return : void
     * description : 객체의 이름, 전공, 전화번호 출력
     * author : mwJung
     * make date : 2023. 09. 17
     */

    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("전공 : " + this.major);
    }
}
