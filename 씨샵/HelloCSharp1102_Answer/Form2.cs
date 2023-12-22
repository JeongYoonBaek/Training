using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1102_Answer
{
    public partial class Form2 : Form
 
    {
        public Form2(string msg)
        {
            InitializeComponent();
            label1.Text = msg;  
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }
    }
}
