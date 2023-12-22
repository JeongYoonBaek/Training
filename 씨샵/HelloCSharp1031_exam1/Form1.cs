using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1031_exam1
{
    public partial class Form1 : Form
    {
        int number = 0;
        int time = 5;
        public Form1()
        {
            InitializeComponent();
            number = new Random().Next(1, 11); // 프로그램 시작하자마자 정답을 알려줌 
            Console.WriteLine(number);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int mynum = int.Parse(textBox1.Text);
            if (number < mynum)
                MessageBox.Show("정답보다 더 큰 값을 골랐습니다.");
            else if (number > mynum)
                MessageBox.Show("정답보다 더 작은 값을 골랐습니다.");
            else
            {
                MessageBox.Show("정답!!!");
                number = new Random().Next(1, 11);
                Console.WriteLine(number);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (time > 0)
            {
                label1.Text = time.ToString();
                time--;
            }
            else if (time ==0)
            {
                label1.Text = "Time Over";
            }
            }
        }
    }



