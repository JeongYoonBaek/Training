using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1031_exam2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Test1 t1 = new Test1();
            string result = "";
            result += t1.Power(10) + "\n";
            result += t1.Power(3,3) + "\n";
            result += t1.Power(100) + "\n";
            result += t1.Power(50, 100) + "\n";
            MessageBox.Show(result);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string result = "";
            result += Test2.Power(10) + "\n";
            result += Test2.Power(3, 3) + "\n";
            result += Test2.Power(100) + "\n";
            result += Test2.Power(50, 100) + "\n";
            MessageBox.Show(result);

        }

        private void button4_Click(object sender, EventArgs e)
        {
            Hide();
            new Form2().ShowDialog();
            Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Hide();
            new Form3().ShowDialog();
            Show();
        }
    }
}
