using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1102_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // 사번이 문자열일 경우 : 09를 입력하면 레이블에서 09학번으로 출력이 됨 
           Sawon<string> dj = new Sawon<string>();
            dj.Number = textBox1.Text;
            label1.Text = "사번은 " + dj.Number + " 입니다. "; 
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // 사번이 숫자일 경우  : 09를 입력하면 레이블에서 9학번으로 출력이 됨
            Sawon<int> sh = new Sawon<int>();
            int.TryParse(textBox2.Text, out int num);
            sh.Number = num;
            label2.Text = "사번은 " + sh.Number + " 입니다. ";
            // 학번이나 사번이 문자열로 출력하는 것이 좋은 이유.
        }

        // 비행기 움직이는 함수 
        // 이 함수가 실행되면서 
        // out 키워드가 붙은건
        // 함수 바깥에 있는 변수인데, 그 것의 값이 바뀐다
        // 마치 C언어의 포인터나 C#의 ref랑 마찬가지로 말이다.
        // ref : 참조자이고, 함수에서 값이 바뀌면 바깥에서도 바뀐다.  반드시 대입문이 필요함
        // 즉 여기선 rx = 0; ry = 0; 이런 거라도 넣어줘야 된다.
        // 할당이 의무 !!! (=) <<<< 이거
        void NextPosition(int x, int y, int vx, int vy, out int rx, out int ry)
        {
            // 다음 위치 = 현재 위치 + 현재 속도
            rx = x + vx;
            ry = y + vy;
        }

        
        private void button3_Click(object sender, EventArgs e)
        {
            // Environment.NewLine = \n이랑 똑같음 (윈도우 기준)
            int x = 0, y = 0 ; // x와 y 모두 0
            string nowPos = $"현재 위치 : ({x},{y})" + Environment.NewLine;
            int movePos = int.Parse(textBox3.Text); // 속도에 영향 주는 변수 
            NextPosition(x, y, movePos + 10, movePos + 20, out x, out y); // x y와 10, 20은 그대로 들어감. 
            nowPos += $"이동 후 위치  : ({x},{y})" + Environment.NewLine;
            label3.Text = nowPos;
        }

        // 멤버변수
       List<Product> products = new List<Product>();    
        // 제품 추가 및 출력 버튼 
        private void button4_Click(object sender, EventArgs e)
        {
            products.Add(new Product() { Name = textBox4.Text});
            // 방금 추가한 것을 price로 바꾼것임
            products.Last().Price = int.Parse(textBox5.Text);
            // 배열 인덱스 접근 추가로 가능함
            //products[0].Price = int.Parse(textBox5.Text);

            string prices = "";
            foreach (var item in products)
                prices += item + "\n"; // 
                
            label4.Text = prices;   

        }

        // 제품을 가격 순으로 출력할 버튼
        private void button5_Click(object sender, EventArgs e)
        {
            label4.Text = "";
            products.Sort(); // Product에 IComparable의 CompareTo가 구현되어 있어야한다 그래야 오류가 실행안됨!
            foreach (var item in products)
                label4.Text += item + "\n";

            // 인터페이스도 다형성을 적용받음
            // 추상 클래스와 마찬가지로 단독으로 인스턴스 생성 불가능
            //IComparable ic = new IComparable();
            IComparable<Product> i = new Product();
        }
    }
}
