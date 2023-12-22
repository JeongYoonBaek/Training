using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exam4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // 내가 원하는 규칙으로 로또 번호 생성해보기 

            #region 정윤   
            if (false)
            {
                int[] lotto = new int[6];
                int bns = -1;
                Random r = new Random();        // 랜덤 객체 생성 (랜덤 값 뽑아주는 기능)
                for (int i = 0; i < 6; i++)
                {
                    int n = r.Next(1, 46);                       // 1부터 45까지의 숫자를 삽입한 것 
                    bool isDuplicate = false;           // 중복체크 (bool 변수)
                    for (int j = 0; j < i; j++)                  // 중복 여부를 검증
                    {
                        if (n == lotto[j])
                        {
                            Console.WriteLine("n=" + n + "j=" + j);
                            Console.WriteLine("중복!");
                            foreach (var item in lotto)
                            {
                                if (item == 0)
                                    break;
                                Console.Write(item + " ");
                            }
                            isDuplicate = true;
                            i--;
                            break;
                        }
                    }
                    if (isDuplicate)        // 중복이 아니면 값을 새로 넣어줌 
                        continue;
                    lotto[i] = n;
                }
                Console.WriteLine(Environment.NewLine + "로또");
                //Array.Sort(lotto); // 오름 차순 정렬 (가장 쉬운방법)

                // 버블 정렬 
                for (int i = 0; i < lotto.Length; i++)
                {
                    for (int j = 0; j < lotto.Length - 1; j++)
                    {
                        if (lotto[j] > lotto[j + 1])
                        {
                            int temp = lotto[j];
                            lotto[j] = lotto[j + 1];
                            lotto[j + 1] = temp;
                        }
                    }
                }
                foreach (var item in lotto)
                    Console.Write(item + " ");
                // Environment.NewLine = \n
                // Environment.NewLine : OS별로 개행문자가 다르므로
                // OS 마다 다른 개행 문자를 씀 (개행, CR)
                Console.WriteLine(Environment.NewLine + "보너스");
                bns = r.Next(1, 46);
                for (int i = 0; i < 6; i++)       // 겹치는게 있으면 i에 마이너스 해주고 보너스 번호를 뽑아줌 
                {
                    if (bns == lotto[i])
                    {
                        i = -1;
                        bns = r.Next(1, 46);
                    }
                }
                Console.WriteLine("보너스 번호 :" + bns);
                #endregion
            }
            #region 정윤 다이아
            if (false)
            {
                Console.WriteLine("몇 층인가요?");
                int f = int.Parse(Console.ReadLine());
                for (int i = 1; i <= f; i++) // floor =3, 3층 다이아
                {
                    // 3층인 경우라면 띄어쓰기가 2,1,0번 일 것이다.
                    for (int j = 0; j < f - i; j++)
                        Console.Write(" "); // Console.Write는 한 줄 띄지 않음 
                                            // 별의 개수는 1,3,5개가 될 것
                    for (int j = 0; j < 2 * i - 1; j++) // 짝수가 되면 홀수로 만들어주기 위해 -1을 선언함 
                        Console.Write("*");
                    Console.WriteLine(); // 한 줄 띄어쓰기
                }
                // 밑에다가 거꾸로 된 다이아몬드를 추가해야 함
                //    *
                //  ***
                //*****
                //  ***
                //    *
                for (int i = 1; i <= f - 1; i++)
                {
                    for (int j = 0; j < /*floor-*/ i; j++)       //공백 늘어남
                        Console.Write(" ");

                    for (int j = 0; j < 2 * (f - i) - 1; j++)     // 별 줄어듦 
                        Console.Write("*");
                    Console.WriteLine();
                }
            }


            #region 정윤 갑을병정
            if (false)
            {
                int year = DateTime.Now.Year;
                string jisin = "";
                switch (year % 10)
                {
                    case 0:
                        jisin += "경";
                        break;
                    case 1:
                        jisin += "신";
                        break;
                    case 2:
                        jisin += "임";
                        break;
                    case 3:
                        jisin += "계";
                        break;
                    case 4:
                        jisin += "갑";
                        break;
                    case 5:
                        jisin += "을";
                        break;
                    case 6:
                        jisin += "병";
                        break;
                    case 7:
                        jisin += "정";
                        break;
                    case 8:
                        jisin += "무";
                        break;
                    case 9:
                        jisin += "기";
                        break;
                    default:
                        break;
                }
                switch (year % 12)
                {
                    case 0:
                        jisin += "신";
                        break;
                    case 1:
                        jisin += "유";
                        break;
                    case 2:
                        jisin += "술";
                        break;
                    case 3:
                        jisin += "해";
                        break;
                    case 4:
                        jisin += "자";
                        break;
                    case 5:
                        jisin += "축";
                        break;
                    case 6:
                        jisin += "인";
                        break;
                    case 7:
                        jisin += "묘";
                        break;
                    case 8:
                        jisin += "진";
                        break;
                    case 9:
                        jisin += "사";
                        break;
                    case 10:
                        jisin += "오";
                        break;
                    case 11:
                        jisin += "미";
                        break;
                    default:
                        break;
                }
                Console.WriteLine(jisin);
            }
            #endregion
        }
    }
}
