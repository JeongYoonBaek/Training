using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1102_Answer
{
    public class BattleCruiser : IConveyancable
    {
        private string brandName;
        public string Name { get => brandName;
            set => brandName = value;
        }

        public void fly()
        {
            throw new NotImplementedException();
        }

        public void run()
        {
            throw new NotImplementedException();
        }

        public void stop()
        {
            throw new NotImplementedException();
        }
    }
}
