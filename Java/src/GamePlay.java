import Com.Kb.BaseballGame;
import Com.Kb.Input;
import Com.Kb.Setting;

import java.util.Scanner;

import static Com.Kb.Constants.*;

public class GamePlay {
    public static void main
    (String[] args) {
        // 입력
        // 입력받기 위한 객체 선언
        Scanner scanner = new Scanner(System.in); //기본적으로 선언하는 객체를 외부에서 주입
        Input myInput = new Input();

        Setting setting = new Setting();
        String answerCount = myInput.inputFromUser(MSG_INPUT_ANSWER_COUNT, scanner);
        setting.setInputLimit(Integer.parseInt(answerCount)); // 입력 횟수가 나옴

        String inputLimit = myInput.inputFromUser(MSG_INPUT_LIMIT, scanner);
        setting.setInputLimit(Integer.parseInt(inputLimit));


        boolean gameComplete = false; // 처음에는 펄스가 맞지만 완료 됐나 안됐나 확인

        BaseballGame data = new BaseballGame();
        data.initSetting(setting); // 초기화 같이 해주면 됨 위에 입력한 ans과 input limit이
        // 데이터 안에 다 들어감

        //빨간색 밑줄 뜨면 alt+엔터 누르고 빨간줄 사라지게 하면 됨

        //  정답 3개
        data.setAnswers(setting.getInputLimit() i++);


        // 9번 반복
        for (int i = 0; i < setting.getInputLimit(); i++) {
            // 처음에 게임셋팅 게임 스타트 화면이 나옴.
            //  getInputLimit(); 횟수까지 실행함
            // 카운트 판단을 위한 변수 초기화

            // 입력 3개
            // int question1을 선언하고 입력 받아 저장
            data.setQues1(Integer.parseInt(myInput.inputFromUser(MSG_FIRST_INPUT, scanner)));

            // int question2을 선언하고 입력 받아 저장
            int question2 = Integer.parseInt(myInput.inputFromUser(MSG_SECOND_INPUT, scanner));
            data.setQues2(question2);
            // int question3을 선언하고 입력 받아 저장
            int question3 = Integer.parseInt(myInput.inputFromUser(MSG_THIRD_INPUT, scanner));
            data.setQues3(question3);

            gameComplete = data.isValidAnswer(); //
            if (data.isValidAnswer()) {
                break;
            }
        }

        // 결과 출력
        // strike, ball 출력

        if (gameComplete) { // 플래그 : 있거나 없거나. 플래그는 적절히 킬링포인트로 써야함.
            System.out.println("정답입니다.");
        } else {
            System.out.println("정답 : " + data.getAns1() + ", " + data.getAns2() + ", " + data.getAns3());
        }
    }
}








