﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1030exam4
{
    public partial class Form2 : Form
    {
        int number;
        public Form2()
        {
            InitializeComponent();
            // Random r = new Random():
            // number = r.Next(1, 11); 도 가능함 
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
                Console.WriteLine( number);
            }
        }
    }
}
