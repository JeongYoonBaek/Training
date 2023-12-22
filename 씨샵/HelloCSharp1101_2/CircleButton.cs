using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace HelloCSharp1101_2
{

    // Button을 상속받아서
    // 그리는 메소드를 오버라이드 하여서
    // 새로운 컨트롤(=컴포넌트)을 만들어냈다.
    public class CircleButton : Button
    {
        // circle이라는 클래스를 만들었는데 기존 button 클래스 상속받음
        protected override void OnPaint(PaintEventArgs pevent)   
        {
            // OnPaint를 오버라이드 하여서 타원형 버튼 만드는 것이 가능하다!
            GraphicsPath g = new GraphicsPath();
            g.AddEllipse(0,0,ClientSize.Width,ClientSize.Height);
            this.Region = new System.Drawing.Region(g);
            base.OnPaint(pevent);
        }
    }
}
