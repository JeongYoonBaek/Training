using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1031_exam2
{
    public class Test2
    {
   
        public  static int Power(int input)
        {
            return input * input;
        }
        public static  int Power(int input, int count)
        {
            int answer = 1;
            for (int i = 0; i < count; i++)
            {
                answer *= input;
                // answer = answer*input 는 3이 됨. 그럼 answer에 또 3을 곱하면 9가 되고 거기에 또 3을 곱하면 3에 3제곱이 됨
            }
            return answer;
        }
        public static  int SumAll(int end)
        {
            int result = 0;
            for (int i = 0; i <= end; i++)
            {
                result += i;
            }
            return result;
        }
    }
}
