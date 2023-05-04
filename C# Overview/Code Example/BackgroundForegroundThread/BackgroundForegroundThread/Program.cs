using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace BackgroundForegroundThread
{
    class Program
    {
        static void WorkerMethod()
        {
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("WorkerMethod :  counter : " + i);
            }
            Console.WriteLine("End Of WorkerMethod");
        }
        /// <summary>
        /// Foreground Thread
        /// </summary>
        /// <param name="args"></param>
        //static void Main(string[] args)
        //{
        //    ThreadStart ts = new ThreadStart(WorkerMethod);
        //    Thread t = new Thread(ts);
        //    t.Start();
        //    Console.WriteLine("End Of Main");
        //}

        /// <summary>
        /// Background Thread
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            ThreadStart ts = new ThreadStart(WorkerMethod);
            Thread t = new Thread(ts);
            t.IsBackground = true;
            t.Start();
            Console.WriteLine("End Of Main");
        }

    }
}
