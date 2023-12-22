import com.kb.CompFriend;
import com.kb.Friend;
import com.kb.UnivFriend;

public class MyFriends {
    public static void main(String[] args) {
        // UnivFriend 배열 객체 ufrns 생성 (크기 5)
        Friend[] friends = new Friend[10];

        // int ucnt를 선언하고 0 저장
        int cnt = 0;

        // ufrns[ucnt]에 UnivFriend 객체 생성(lee, computer, 01011112222) 후 저장
        friends[cnt] = new UnivFriend("lee", "computer", "01011112222");

        // ucnt 1 증가
        cnt++;

        // ufrns[ucnt]에 UnivFriend 객체 생성(seo, electronics, 01011113333) 후 저장
        friends[cnt] = new UnivFriend("seo", "electronics", "01011113333");

        // ucnt 1 증가
        cnt++;

        // cfrns[ccnt]에 CompFriend 객체 생성(yoon, r&d 1, 01011114444) 후 저장
        friends[cnt] = new CompFriend("yoon", "r&d 1", "01011114444");

        // ccnt 1 증가
        cnt++;

        // cfrns[ccnt]에 CompFriend 객체 생성(ha, r&d 2, 01011115555) 후 저장
        friends[cnt] = new CompFriend("ha", "r&d 2", "01011115555");

        // ccnt 1 증가
        cnt++;

        // 반복 i 0부터 ucnt - 1 까지
        // - ufrns[i]의 showInfo() 실행
        for (int i = 0; i < cnt; i++) {
            friends[i].showInfo();
        }

    }
}
