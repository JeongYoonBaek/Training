using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BookManager
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            dataGridView1.Columns[0].HeaderText = "번호";
            dataGridView1.Columns[1].HeaderText = "책 이름";
            dataGridView1.Columns[2].HeaderText = "출판사";
            dataGridView1.Columns[3].HeaderText = "페이지";
            dataGridView1.Columns[4].HeaderText = "회원ID";
            dataGridView1.Columns[5].HeaderText = "회원명";
            dataGridView1.Columns[6].HeaderText = "대여 여부";
            dataGridView1.Columns[7].HeaderText = "대여 시점";
            label5.Text =
              DateTime.Now.ToString("yyyy년 MM월 dd일 HH시 mm분 ss초");
            label1.Text = "전체도서수:" + DataManager.books.Count();
            label1.Text = "전체회원수:" + DataManager.users.Count();
        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label5.Text = 
                DateTime.Now.ToString("yyyy년 MM월 dd일 HH시 mm분 ss초");
        }

        private void 도서관리ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            new Form2().ShowDialog(); // Form2 불러오기
        }
    }
}
