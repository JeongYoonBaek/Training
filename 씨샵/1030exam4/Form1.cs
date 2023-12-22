using System;
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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Hide();     // 뒤에 창 숭김
            new Form2().ShowDialog();
            Show();   // 뒤에 창 다시 나타남 
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Hide();     // 뒤에 창 숭김
            new Form3().ShowDialog();
            Show();   // 뒤에 창 다시 나타남 
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Hide();     // 뒤에 창 숭김
            new Form4().ShowDialog();
            Show();   // 뒤에 창 다시 나타남 
        }
    }
}
