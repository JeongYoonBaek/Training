using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace HelloCSharp1030_01
{
    public partial class Form1 : Form
    {
        String randomText = "백정윤입니다.";

        // Java의 ArrayList 
        // C#의 List가 Java의 ArrayList랑 사실상 똑같음 
        List<String> nameList = new List<string> { "이동준", "이유나", "박명회" };
        List<int> ageList = new List<int> { 15, 20, 25 };
        List<int>ageList2 = new List<int>();

        // TMI+참고 C#에 있는 ArrayList는
        // 자바의 ArrayList<Object>랑 동일함
        // 즉 아무거나 다 들어가는 리스트이다. 
        ArrayList TmiList = new ArrayList();
        

        public Form1() // 생성자 
        {
            InitializeComponent();

            // 코드로 버튼을 만들 수 있음 
            Button b = new Button();
            b.Text = "코드로 만든 버튼";
            b.AutoSize = true; // 글자가 길 경우 그에 따라 길이 늘어나는거
            b.Location = new Point(10, 10);
            // Controls : Form1 안에 있는 모든 구성요소들 (Button들 등)
            Controls.Add(b);  // Add 코드가 없으면 b는 화면에 안보임!!!
        }

        //  btn_test 클릭시 수행할 함수 
        private void btn_test_Click(object sender, EventArgs e)
        {
         
            // 1. 버튼 클릭하면 checkBox1의 텍스트가 바뀌게 하시오.
            checkBox1.Text = "추워";
            Random r = new Random();

            //  이 두 코드는 똑같은 거임. char를 String으로 변환한 것 
            //checkBox2.Text = randomText[r.Next(randomText.Length)] + "";
            checkBox2.Text = randomText[r.Next(randomText.Length)].ToString();


            // 2.  체크 박스가 체크된 상태일 때 버튼 클릭하는 거랑 체크 박스가 체크 해제된 상태일 때 버튼 클릭하는 거랑
            // 출력되는 메시지가 다르게 해보시오.
            if (checkBox1.Checked == true)
            {
                MessageBox.Show("ㅎㅇ");
            }
            else if (checkBox1.Checked == false)
            {
                MessageBox.Show("잘못된 클릭");
            }

            // 3. 체크 박스가 체크가 되어 있으면 1번을 수행 (텍스트 변환)
            // 체크 박스가 체크 안 되어 있으면 아~~무 것도 수행하지 않는다.

            
            if (checkBox1.Checked == true)
            {
                MessageBox.Show("ㅎㅇ");
            }
            else if (checkBox1.Checked == false)
            {
                return;
            }

        }
    }
}
