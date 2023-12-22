package Com.Kb;

// 설정을 해주는 프로그램 (게임 횟수, 정답 횟수 메소드)
public class Setting {
    private int inputLimit;

    private int answerCount;

    public int getInputLimit() {
        return inputLimit;
    }

    public void setInputLimit(int inputLimit) {
        this.inputLimit = inputLimit;
    }

    public int getAnswerCount() {
        return answerCount;
    }

    public void setAnswerCount(int answerCount) {
        this.answerCount = answerCount;
    }
}
