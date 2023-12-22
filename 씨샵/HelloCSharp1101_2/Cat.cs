using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1101_2
{
    public abstract class Cat : Animal
    {
        public abstract void grooming();    // 털정리
        public abstract void hunt();        // 사냥 
    }
}
