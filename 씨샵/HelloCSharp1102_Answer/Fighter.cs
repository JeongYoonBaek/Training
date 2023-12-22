using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1102_Answer
{
    public class Fighter : GameCharacter
    {
        public override void fight()
        {
            System.Windows.Forms.MessageBox.Show("주먹으로 때려요");
        }
    }
}
