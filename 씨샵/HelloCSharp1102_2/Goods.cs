﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloCSharp1102_2
{
  public class Goods
    {
        public string Name { get; set; }
        public int Price { get; set; }
        public string Description { get; set; }

        public string InfluencerName;  // DataGridView에 표시 안 됨 
    }
}
