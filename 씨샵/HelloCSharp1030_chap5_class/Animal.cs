using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1030_chap5_class
{
    public class Animal
    {
        public string name { get; set; }
        public int age { get; set; }
        private int id;     // 소문자
        public int Id { get { return id; } set { id=value; } }   //대문자
        private string species;
        public string Species
        { get => species; set =>species=value; }  // a.species = "걔"; 이 걔가 value에 속함
      

       private string masterName;
       public string  getMasterName() 
    {
        return masterName;
    }
    public void setMasterName(string masterName)
    {
        this.masterName = masterName;
    }
    }
}
