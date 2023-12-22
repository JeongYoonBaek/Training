using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1102_Answer
{
    // 인터페이스
    // C#은 첫글자가 I가 꼭 붙고 뒤는 able이 붙음 <= 권고사항!
    // Java는 뒤에 able이 붙음
    // 클래스 네이밍 규칙 (Java, C#공통) : 첫 글자가 무조건 대문자 
 public interface IRiderable
    {
        // 2개의 메소드 
        void run();
        void stop();
    }
}
