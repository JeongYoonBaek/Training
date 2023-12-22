using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace exam3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // 아래의 규칙을 따르는 수열의 20번째 숫자를 프로그램을 만들어 찾으시오 (개미수열)
            // 1, 11, 12, 1121, 122111, 112213
            // 첫 번째 수열 : 1
            // 두 번째 수열 : 1이 1개 = 11
            // 세 번째 수열 : 1이 2개 = 12
            // 네 번째 수열 1이 1개, 2가 1개 = 1121
            // 다섯 번째 수열 : 1이 2개 2가 1개, 1이 1개 = 122111
            // 여섯 번째 수열 : 1이 1개 2가 2개 1이 3개 122333

            // 처음에 주어지는 값
            string start = "1";
            for (int i = 0; i < 20; i++)
            {
                int count = 0; // 읽고 말하기에서 해당 숫자의 개수 
                char num = start[0]; // 읽을 숫자 
                string end = ""; //중간 누적 ex 1, 11, 12, 1121
                Console.WriteLine(i + 1 + "번째: " + start); // 1부터 시작함
                Console.WriteLine();
                for (int j = 0; j < start.Length; j++) // start의 길이만큼 수행 
                {
                    if (num != start[j])
                    {
                        end = end + num + count;
                        num = start[j];
                        count = 1;
                    }
                    else
                        count++;
                }
                    end = end + num + count;
                    start = end;
                }
            }
        }
    }
