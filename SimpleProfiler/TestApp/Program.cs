using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.ReadLine();
            ProfiledMethod();
        }

        static void ProfiledMethod()
        {
            Console.WriteLine("Hello, Simple Profiler!");
        }
    }
}
