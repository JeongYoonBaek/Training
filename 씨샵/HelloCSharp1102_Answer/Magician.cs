using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1102_Answer
{
public  class Magician : GameCharacter
    {
        // Die() 오버라이딩 
        public override string Die()
        {
            return "연기처럼 사라진다";
        }
        public override void fight()  // 무조건 오버라이드 (덧붙여쓰기) 해야함
        {
            System.Windows.Forms.MessageBox.Show("마법공격!!!");
        }
    }
}
