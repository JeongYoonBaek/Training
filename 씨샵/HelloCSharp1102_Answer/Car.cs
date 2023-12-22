using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1102_Answer
{
    public class Car : IRiderable
    {
        public void run()
        {
            System.Windows.Forms.MessageBox.Show("부릉부릉 씽씽");
        }

        public void stop()
        {
            System.Windows.Forms.MessageBox.Show("브레이크 끼이이익~");
        }
    }
}
