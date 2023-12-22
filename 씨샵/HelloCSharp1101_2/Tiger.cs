using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1101_2
{
    public class Tiger : Cat
    {
        public override void Eat()
        {
            Console.WriteLine("떡하나 주면 안잡아먹지");
        }
        public override void Sleep()
        {
            Console.WriteLine("호랑이 자는 중");
        }
        public override void grooming()
        {
            Console.WriteLine("귀찮아서 안함 ");
        }

        public override void hunt()
        {
            Console.WriteLine("어흥");
        }
    }
}
