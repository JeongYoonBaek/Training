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

namespace HelloCSharp1030_exam3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            List<Students> students = new List<Students>();
            students.Add(new Students() { name = "이동준", grade = 1 });
            Students student = new Students();
            student.grade = 2;
            student.name = "백정윤";
            students.Add(student);
            students.Add(new Students() { name = "정용억", grade = 3 });
            students.Add(new Students() { name = "이상하", grade = 4 });
            students.Add(new Students() { name = "최효정", grade = 2 });
            students.Add(new Students() { name = "신예원", grade = 1  });

            for (int i = 0; i < students.Count; i++)
            {
                Label label = new Label();
                label.Text = $"이름:{students[i].name}, 학년:{students[i].grade}";
                label.AutoSize = true // 글자 길어도 늘어남
                label.Location = new Point(130, 10 + 25 * i);
                Controls.Add(label);
            }
            // 뭔가를 삭제할 땐 역for문을 써야 한다.
            // 그래야 IndexBoundError나 IndexOverFlow 에러가 나지 않는다.
            for(int i = students.Count - 1; i>=0; i--)
            {
                if (students[i].grade > 1) // 학년이 1학년
                    students.RemoveAt(i); // i번째 날려버림
            }
            for (int i = 0; i < students.Count; i++)
            {
                Label label = new Label();
                label.Text = $"이름:{students[i].name}, 학년:{students[i].grade}";
                label.AutoSize = true // 글자 길어도 늘어남
                label.Location = new Point(230, 10 + 25 * i);
                Controls.Add(label);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Random 함수를 이용하여 숫자 맞추기 프로그램을 Form 형태로 만들어보시오 
        }
    }
}
