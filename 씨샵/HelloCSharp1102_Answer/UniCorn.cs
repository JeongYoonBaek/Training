using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1102_Answer
{
    public class UniCorn : GameCharacter, IRiderable, IFlierable // 게임 캐릭터와 탈 것, 날 것 상속 
    {
        public override void fight()
        {
            MessageBox.Show("말발굽으로 때린다.");
        }

        public void fly()
        {
            MessageBox.Show("말처럼 울면서 새처럼 난다.");
        }

        public void run()
        {
            MessageBox.Show("말처럼 달린다.");
        }

        public void stop()
        {
            MessageBox.Show("말처럼 멈춘다.");
        }
    }
}
