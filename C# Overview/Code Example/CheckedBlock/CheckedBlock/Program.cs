using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CheckedBlock
{
    class Program
    {
        static void Main(string[] args)
        {
            byte Num = byte.MaxValue;
            try
            {
                checked
                {
                    Num++;
                    Console.WriteLine("Num = {0}", Num);
                }
            }
            catch (OverflowException e)
            {
                Console.WriteLine(e.Message);
            }
            int Num2 = 10;
            int Num3 = 0;
            int Div;
            try
            {
                Div = Num2 / Num3;
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine(e.Message);
            }

        }
    }
}
