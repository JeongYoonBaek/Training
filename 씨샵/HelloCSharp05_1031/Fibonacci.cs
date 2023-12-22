using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Schema;

namespace HelloCSharp05
{
    public class Fibonacci
    {
        private static Dictionary<int, long> memo = new Dictionary<int, long>();
        public static long Get(int i)
        {

            // 기본 값
            if (i < 0) { return 0; }
            if (i == 1) { return 1; }

            // 이미 계산했던 값인지 확인합니다.
            if (memo.ContainsKey(i))
            {
                return memo[i];
            }
            else
            {
                // 계산하지 않았다면 계산합니다.
                long value = Get(i - 2) + Get(i - 1);
                memo[i] = value;
                return value;
            }
        }
    }
    class program
    {
        static void main(String[] args)
        {
            Console.WriteLine(Fibonacci.Get(40));
            Console.WriteLine( Fibonacci.Get(100));
        }
    }
}
