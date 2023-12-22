using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1101_2
{
    public class Domestic_Cat : Cat
    {

        public string MasterName { get; set; }

        public override void Eat()
        {
            Console.WriteLine(MasterName + "가 먹여줘요");
            System.Windows.Forms.MessageBox.Show("쩝쩌ㅃ쩌ㅃ쩌ㅃ쩌ㅃ쩌");
        }

        public override void grooming()
        {
            Console.WriteLine(MasterName + "가 정리 해줘요");
            System.Windows.Forms.MessageBox.Show("샤아아아아아아ㅏㄱ");
        }

        public override void hunt()
        {
            Console.WriteLine(MasterName + "가 잡아줘요");
            System.Windows.Forms.MessageBox.Show("야옹 건들이면 잡아먹는다옹");
        }

        public override void Sleep()
        {
            Console.WriteLine(MasterName + "가 재워줘요");
            System.Windows.Forms.MessageBox.Show("쿨쿨쿨쿨쿨쿨쿨");
        }
    }
}
