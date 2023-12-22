using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1101_2
{
   public abstract class Animal
    {
        public string  name{ get;  set; }     
        public int age { get; set; }    

        // 메서드의 구현은 자손 클래스에게 맡긴다.
        // 즉 자손클래스는 의무적으로 오버라이딩을 해야 함 
        public abstract void Sleep();
        public abstract void Eat();

    }
}
