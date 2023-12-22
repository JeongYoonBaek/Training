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
    public partial class Form4 : Form
    {
        List<string> texts = new List<string>();
        public Form4()
        {
            InitializeComponent();
            label1.Text = "";
            texts.Add("안녕하세요.");
            texts.Add("반갑습니다.");
            texts.Add("좋은하루 되세요.");
            texts.Add("맛있는 점심식사 되세요.");
            texts.Add("감사합니다.");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Text = "";
            label1.Text = texts[new Random().Next(texts.Count)];
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
