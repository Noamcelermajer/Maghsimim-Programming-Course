using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Throw
{
    class MyMath
    {
        public static byte AddTen(byte num)
        {
            try
            {
                checked
                {
                    num += 10;
                }
            }
            catch
            {
                Console.WriteLine("Error in AddTen");
                throw;
            }
            return num;
        }
        public static float Divide(float n1, float n2)
        {
            if (n2 == 0)
                throw new DivideByZeroException();
            return n1 / n2;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            byte num = byte.MaxValue;
            try
            {
                Console.WriteLine(MyMath.AddTen(num));
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            try
            {
                Console.WriteLine(MyMath.Divide(12.34f, 0));
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}


