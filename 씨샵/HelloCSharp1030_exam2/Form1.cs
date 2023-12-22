using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HelloCSharp1030_exam2
{
    public partial class Form1 : Form
    {

        class Student
        {
            public string name;
            public int grade;
        }
        public Form1()
        {
            InitializeComponent();
            List<Student> students = new List<Student>();
            students.Add(new Student() { name = "이동준", grade = 1 });
            students.Add(new Student() { name = "백정윤", grade = 2 });
            students.Add(new Student() { name = "최효정", grade = 3 });
            students.Add(new Student() { name = "신예원", grade = 4 });
            students.Add(new Student() { name = "이현오", grade = 3 });
            students.Add(new Student() { name = "장광수", grade = 2 });
            
            for (int i = 0; i < students.Count; i++)
            {
                Label label = new Label();
                label.Text = $"(students[i].grade)학년  {students[i].name} 학생";
                label.AutoSize = true;
                label.Location = new Point(13, 13 + (23 + 3) + i);
                Controls.Add(label);
            }

            /* 
             * List<Students> students = new List<Students>();
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
                Label.label = new Label();
                label.Text = $"이름:{students[i].name}, 학년:{students[i].grade}";
                label.AutoSize = true // 글자 길어도 늘어남
                label.Location = new Point(130, 10 + 25 * i);
                Controls.Add(label); */

            for (int i = students.Count - 1; i >= 0; i--)
            {
                if (students[i].grade > 1) // 학년이 1헉뇬 
                {
                    students.RemoveAt(i);
                }
            }
                for (int i = 0; i < students.Count; i++)
                {
                    Label label = new Label();
                    label.Text = $"{students[i].grade} 학년 {students[i].name} 학생";
                    label.AutoSize = true;
                    label.Location = new Point(130, 13 + (23 + 3) * i);
                    Controls.Add(label);
                }
            }
        
        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}