import com.kb.CompFriend;
import com.kb.Friend;
import com.kb.UnivFriend;

import java.util.ArrayList;
import java.util.List;

public class MyFriends1 {
    public static void main(String[] args) {
        // UnivFriend 배열 객체 ufrns 생성 (크기 5)
        List<Friend> friendList = new ArrayList<>();

        // ufrns[ucnt]에 UnivFriend 객체 생성(lee, computer, 01011112222) 후 저장
        friendList.add(new UnivFriend("lee", "computer", "01011112222"));
        friendList.add(new UnivFriend("seo", "electronics", "01011113333"));
        friendList.add(new CompFriend("yoon", "r&d 1", "01011114444"));
        friendList.add(new CompFriend("ha", "r&d 2", "01011115555"));

        // 반복 i 0부터 ucnt - 1 까지
        // - ufrns[i]의 showInfo() 실행
        for (int i = 0; i < friendList.size(); i++) {
            friendList.get(i).showInfo();
        }

        for (Friend friend : friendList) {
            friend.showInfo(); // 자바 for문 형식이고 안에 있는 객체를 하나씩 꺼집어내서
            //  아래쪽 friend.showInfo();에 전달해서 출력함
        }
    }
}
