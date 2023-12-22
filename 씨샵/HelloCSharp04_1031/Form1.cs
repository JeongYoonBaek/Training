using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp04
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            Product p  = new Product();
            p.price = 100;
            //p.name =??? 왜냐 기본 접근자가 private로 되어있어서 private로 간주됨 그래서 사용하려면 public을 붙여줘야함
            if (false)
            {
                // 학생의 정보를 넣음
                Dictionary<string, string> student = new Dictionary<string, string>();
                student["학번"] = "2009038033";
                student["이름"] = "이동준";
                student["성별"] = "남성";
                student["탈모여부"] = "약간 진행중인가...ㅠ";

                // 클래스를 이용해서 학번 결혼여부 탈모여부를 출력할 수 있지만 나중에 속성 추가하면 코드의 구조가 많이 바뀔 수 있다.
                // 딕셔너리 한줄만 추가하면 해결이 됨!!! 구조가 유연해진다.
                MessageBox.Show(student["학번"]);
                MessageBox.Show(student.ContainsKey("결혼여부") + " ");
                MessageBox.Show(student.ContainsKey("탈모여부") + " ");

                // List 같은 경우엔 "인덱스"라는게 있다.
                // 따지고 보면 키가 숫자인 Dictnoary라고 볼 수도 있다.
                List<string> numbers = new List<string>();
                numbers.Add("이현오");
                numbers.Add("장광수");
                numbers.Add("이동준");
                MessageBox.Show(numbers[0]);
                MessageBox.Show(numbers[1]);
                MessageBox.Show(numbers[2]);


                // ArrayList 같은 경우에도 "인덱스"가 있다.
                // 다만 안에 들어가는 데이터의 형태를 제한하지 않는다. 
                ArrayList objectList = new ArrayList();
                objectList.Add("백정윤");
                objectList.Add(100);
                objectList.Add(3.14);
                objectList.Add(new Form1());    // 타입 자체가 오브젝트 
                MessageBox.Show(objectList[0] + " ");
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        void change(int num)
        {
            num = 1000; // a의 값을 복사만 해왔을 뿐
            // a랑 위치도 다르고 완전 별개의 존재
         
        }

        // change는 오버로딩이 됨 매개변수가 다름.
        void change(Product p)
        {
            p.price = 0;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int a = 10;
            int b = a;
            b = 200;
            // b가 값이 바뀌었다고 해서 a의 값이 바뀌지 않음
            label1.Text = "a=" + a + Environment.NewLine;
            label1.Text += "b=" + b + Environment.NewLine;
            change(a);     // 이 메소드는 a의 값을 복사만 한 것. 원본이랑 관계없음
            label1.Text += "a=" + a + Environment.NewLine;

        }

        // Product라는 친구는 위치값을 가지고 있음 (heap이라는 메모리 영역의 한 위치를 가리킴)
        // 여기에는 price가 100원이 있음 product p2가 product가 선언된 것은 똑같은 곳을 가리키고 있는 뜻임.
        // 그래서 a값은 여전히 똑같음
        private void button3_Click(object sender, EventArgs e)
        {
            Product product = new Product();
            product.price = 100;
            Product p2 = product;   // Product
            p2.price = 999;
            label2.Text = "product의 price  : " + product.price + "\n";
            change(product);    // product 값을 바꿈
            label2.Text += "product의 price  : " + product.price + "\n";
            product.price = 10000;
            change(product.price);  // 안 바뀌는 이유 change(int)를 호출한 것
            label2.Text += "product의 price : " + product.price + "\n";
           
        }
        
        // ref 키워드 = 참조자
        // 해당 변수의 값뿐 아니라 그 변수의 위치도 같이 가져오는 것
        // 따라서 swap에서 값이 바뀌면 swap 바깥에 있는 원본의 값이 바뀐다. 
        // ref는 C#에서만 사용가능함!!!
        void swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }


        private void button_swap_Click(object sender, EventArgs e)
        {
            int a = int.Parse(textBox_1.Text);  // 3
            int b = int.Parse(textBox_2.Text);   // 5
            MessageBox.Show("a= " +a +" b= "+b);
            swap(ref a, ref b);
            label_1.Text = a + " "; // 5
            label_2.Text = b + " "; // 3
            
        }
    }
}
