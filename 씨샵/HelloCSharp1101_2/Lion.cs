using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1101_2
{
    public class Lion : Cat
    {
        // 나이랑 이름 정보가 있고
        // 먹고 자고 털정리하고 사냥하는 기능이 있는 객체 
        public override void Eat()
        {
            Console.WriteLine("뇸뇸쩝쩝");
        }
        public override void Sleep()
        {
            Console.WriteLine("쿨쿨쿨쿨쿨쿨쿨쿨");
        }
        public override void grooming()
        {
            Console.WriteLine("귀찮아서 안해...");
        }

        public override void hunt()
        {
            Console.WriteLine("건들면 물어버린다...");
        }
    }
}