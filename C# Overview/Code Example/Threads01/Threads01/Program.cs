using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Threads01
{
    class Program
    {
        static void WorkerMethod1()
        {
            int counter = 0;

            for (uint i = 0; i < 1000; i++)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                counter++;
                Console.WriteLine("WorkerMethod1 :  counter : " + counter);
            }
        }
        static void WorkerMethod2()
        {
            int counter = 0;

            for (uint i = 0; i < 1000; i++)
            {
                Console.ForegroundColor = ConsoleColor.Blue;
                counter++;
                Console.WriteLine("WorkerMethod2 :  counter : " + counter);
            }
        }
        static void WorkerMethod3()
        {
            int counter = 0;

            for (uint i = 0; i < 1000; i++)
            {
                Console.ForegroundColor = ConsoleColor.Yellow;
                counter++;
                Console.WriteLine("WorkerMethod3 :  counter : " + counter);
            }
        }
        static void Main(string[] args)
        {
            ThreadStart ts1 = new ThreadStart(WorkerMethod1);
            Thread t1 = new Thread(ts1);
            t1.Start();
            ThreadStart ts2 = new ThreadStart(WorkerMethod2);
            Thread t2 = new Thread(ts2);
            t2.Start();
            ThreadStart ts3 = new ThreadStart(WorkerMethod3);
            Thread t3 = new Thread(ts3);
            t3.Start();
        }

        

    }

}

