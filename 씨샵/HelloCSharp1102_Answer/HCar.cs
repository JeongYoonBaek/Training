using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Schema;

namespace HelloCSharp1102_Answer
{
    public class HCar : IConveyancable
    {
        private string brandName;
        // get set 구현 하라고 함

        public string Name
        { 
         get{ return  "현대의 자랑 : " + brandName;}
    set => brandName = value; }

        public void fly()
        {
            throw new NotImplementedException();
        }

        public void run()
        {
            throw new NotImplementedException();
        }

        public void stop()
        {
            throw new NotImplementedException();
        }
    }
        //public string Name
        //{
        //    get { return brandName; }
        //    set { brandName = value; }

       
}
