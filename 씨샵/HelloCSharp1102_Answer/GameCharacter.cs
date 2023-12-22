using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1102_Answer
{
    public abstract class GameCharacter
    {
        // Id,와 Lv 속성
        public string Id { get; set; }
        public int Lv { get; set; }

        public abstract void fight(); // 오버라이딩 필수!!!

        //세이 헬로우에 오버라이딩을 하고 싶은 여지가 있으면 virtual 붙여도 됨
        public virtual string Die() // 오버라이딩이 가능함 (오버라이딩 필수X)
        {
            return "으악!";
        }
        public string SayHello()// 오버라이딩 안 됨 Protected는 개인적으로 복습 권장함
        {
            string introduce = "만나서 반갑습니다. 제 소개를 할게요!\n";
            introduce += "Id" + Id + "\n";
            introduce += "Lv" + Lv + "\n";
            return introduce;
        }
    }
}
