using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeyLotto
{
    // Lotto API의 데이터를 Lotto 클래스에 담아서
    // 리스트에 담은 다음 dataGridView에 뿌릴 것
    
public  class Lotto
    {
        public string drwtNo1 { get; set; } 
        public string drwtNo2 { get; set; } 
        public string drwtNo3{ get; set; } 
        public string drwtNo4 { get; set; } 
        public string drwtNo5{ get; set; } 
        public string drwtNo6 { get; set; } 
        public string bnusNo {  get; set; } 
        public string drwNo { get; set; }

        // alt+enter 생성자 생성 
        public Lotto(string drwtNo1, string drwtNo2, string drwtNo3, string drwtNo4, string drwtNo5, string drwtNo6, string bnusNo, string drwNo)
        {
            this.drwtNo1 = drwtNo1;
            this.drwtNo2 = drwtNo2;
            this.drwtNo3 = drwtNo3;
            this.drwtNo4 = drwtNo4;
            this.drwtNo5 = drwtNo5;
            this.drwtNo6 = drwtNo6;
            this.bnusNo = bnusNo;
            this.drwNo = drwNo;
        }
    }
}
