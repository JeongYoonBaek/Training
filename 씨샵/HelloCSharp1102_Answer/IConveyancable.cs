using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1102_Answer
{
    // Conveyance : 탈 것
    // 1. 인터페이스는 상속을 받을 수 있다. 
    // => IConveyancable 이거만 있으면 3개의 메서드를 구현해야 함
    // 2. 속성도 추가가 가능함 (자바의 인터페이스에서는 상수가 아닌 이상 속성은 추가 불가능함
    public interface IConveyancable : IRiderable, IFlierable
    {
        string Name { get; set; } // 인터페이스가 들어오면 get set이 줄어들기 때문에 메소드의 일종임. 
        
    }
}
