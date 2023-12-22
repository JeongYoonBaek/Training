using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1102_Answer
{
    public class Dron : IFlierable
    {
        public void fly()
        {
            MessageBox.Show("위이잉~~");
        }
    }
}
