using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1101_1
{
    public class Animal
    {
        public static int count = 0;
        public int Age { get; set; }    // 나이
        protected void Born()         // 출생    Animal을 상속받은 객체만 호출해서 쓸 수 있다. 
        {
            // ctrl+h 후 바꾸고 싶은 코드 변경 가능!
           Console.WriteLine("응애응애.");
        }
        public void Sleep()               // 취침
        {
           Console.WriteLine("잠을 잔다.");
        }
        public void Eat()                // 식사 
        {
           Console.WriteLine("먹는다.");
        }

        // 자손 클래스에서 오버라이드를 할 메서드라면
        // virtual이라는 키워드를 써야 함 
        // 오버로딩은 매개변수에 따라 다르고 오버라이드는 상속관계에서 나타남
        public virtual void Wash() 
        {
            Console.WriteLine("물로 씻깁니다.");
        }


    }
}
