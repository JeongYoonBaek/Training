using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ParkingCarManager
{
    public class DataManager
    {
        public static List<ParkingCar> Cars = new List<ParkingCar>();
        static DataManager()
        {
            Load();
        }
        public static void Load()
        {
            try
            {
                //select * from parkingCarManager;
                DBHelper.selectQuery();//전체 조회를 한다.
                Cars.Clear();
                foreach (DataRow item in DBHelper.dt.Rows)
                {
                    ParkingCar car = new ParkingCar();
                    car.parkingSpot = item["parkingSpot"].ToString();
                    car.carNumber = item["carNumber"].ToString();
                    car.driverName = item["driverName"].ToString();
                    car.phoneNumber = item["phoneNumber"].ToString();
                    car.parkingTime = item["parkingTime"].ToString() == "" ?
                        new DateTime() : DateTime.Parse(item["parkingTime"].ToString());
                    Cars.Add(car);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                Console.WriteLine(e.StackTrace);
            }
        }
       public static void Save(String ps, string carnumber , string driverName, string phoneNumber,
           bool isRemove = false) 
        {

        }
        // 주차 공간 추가 삭제용 Save
        public static bool Save(string cmd, string ps, out string contents)
        {
            contents = "";
            return DBInsert(null, ref contents);
        }
        private static bool DBInsert(string ps, ref string contents)
        {
            return true;
        }
        private static bool DBDelete(string ps, ref string contents)
        {
            return true;
        }
        // 실행 프로그램이랑 같은 경로에 LogFolder라는 폴더 정보
        public static void printLog(string contents)
        {
            DirectoryInfo di = new DirectoryInfo("LogFolder");
            if (di.Exists == false) // 그 폴더가 없다면
                di.Create();

            // @"LofFolder\ParkingHistory.txt"
            //"LofFolder\\ParkingHistory.txt"
            // true : append 옵션, false를 적거나 이 부분을 아예 안 적으면
            // 새로운 내용이 나올때마다 ParkingHistory.txt에 덮어쓰기를 함
            // 즉 내용이 누적되지 않음
            using (StreamWriter w = new StreamWriter
                (@"LofFolder\ParkingHistory.txt", true))
            {
                w.WriteLine(contents);
            }
        }
    }
}
