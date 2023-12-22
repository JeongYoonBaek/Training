using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1102_Answer
{
    public class Dragon : GameCharacter, IFlierable, IRiderable
    {
        public override string Die()
        {
            return "용은 죽지 않는다...";
        }
        public override void fight()
        {
            MessageBox.Show("버프를 걸어줍니다.");
        }

        public void fly()
        {
            MessageBox.Show("마나를 이용해서 뜹니다.");
        }

        public void run() // 용은 달리지 않는다! 그래서 해당 기능 미구현
        {
            return;
        }

        public void stop()
        {
            MessageBox.Show("조용히 멈춥니다.");
        }
    }
}
