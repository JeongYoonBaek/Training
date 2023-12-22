using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1101_1
{
    public class Dog : Animal
    {
        public Dog() { Born(); }
        public string Color { get; set; }   // 털 색깔 정보 추가 
        public void Bark() {Console.WriteLine("멍멍");}
    }
}
