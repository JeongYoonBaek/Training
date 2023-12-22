package Com.Kb;

import java.util.List;

public class BaseballGame {
   // private int ques1; // 질문 데이터
   // private int ques2;
   // private int ques3;

    private List<Integer> questions;
    private List<Integer> answers;

    private Setting setting; // 게임 내부에서 세팅을 해야하기 때문에 셋팅 호출

    // private int ans1; // 정답 데이터
    // private int ans2;
    // private int ans3;


    private int strike; // 스트라이크 데이터
    private int ball; // 볼 데이터

    public void initSetting(Setting setting) { // 셋팅 메소드 생성
        this.setting = setting;
    }
    public void setAnswers(int count) { // integer형으로 넘겨줌
        for(int i = 0; i < this.setting.getAnswerCount(); i++) {
         // 3입력하면 3들어오고 5입력하면 5들어옴
            int answer = ((int) (Math.random() * 8)) + 1; // int count 미만 만큼 반복함
            if (i != 0) { // 0이 아닐 때 중복 검사 하면 된다.
                while(true) {
                    for (Integer setAnswer : this.answers) {
                        if (setAnswer != answer) {
                            // ?????
                        }
                    }
                }
            }
            answers.add(answer); // 중복 검사 어떻게 해야 할까?
        }

    }

    public boolean isValidAnswer() { // 내부 데이터가지고 해결할거기 때문에 파라메터 필요없음
        // 안되면 디버깅 꼭 할것
        // 스트라이크, 볼 판별
        // 만약 this.ques1 == this.ans1이라면
        // - strike++
        // 아니라면
        // - 만약 this.ques1 == this.ans2 || this.ques1 == this.ans3 이라면
        // -- ball++
        if (this.ques1 == this.ans1) {
            strike++;
        } else if (this.ques1 == this.ans2 || this.ques1 == this.ans3) {
            ball++; // 키워드 클릭후 ctrl + r 하면 키워드 전체변경 가능
        }

        // 만약 this.ques2 == this.ans2이라면
        // - strike++
        // 아니라면
        // - 만약 this.ques2 == this.ans1 || this.ques2 == this.ans3 이라면
        // -- ball++
        if (this.ques2 == this.ans2) {
            strike++;
        } else if (this.ques2 == this.ans1 || this.ques2 == this.ans3) {
            ball++;
        }

        // 만약 this.ques3 == this.ans3이라면
        // - strike++
        // 아니라면
        // - 만약 this.ques3 == this.ans1 || this.ques3 == this.ans2 이라면
        // -- ball++
        if (this.ques3 == this.ans3) {
            strike++;
        } else if (this.ques3 == this.ans1 || this.ques3 == this.ans2) {
            ball++;
        }

        System.out.println("스트라이크 : " + strike);
        System.out.println("볼 : " + ball);

        //return strike == 3;
        return strike == 3 ? true : false; // 삼항 연산자 사용함. 스트라이크가 3이면 트루 아니면 펄스
    }


}
