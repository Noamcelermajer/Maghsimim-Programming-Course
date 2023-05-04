using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Threading;
using System.ComponentModel;

namespace BackgroundWorkerSample
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private BackgroundWorker background_worker = new BackgroundWorker();

        public MainWindow()
        {
            InitializeComponent();
            background_worker.WorkerSupportsCancellation = true;
            background_worker.WorkerReportsProgress = true;

            background_worker.DoWork += background_worker_DoWork;
            background_worker.ProgressChanged += background_worker_ProgressChanged;
            background_worker.RunWorkerCompleted += background_worker_RunWorkerCompleted;
        }

        

       

        void background_worker_DoWork(object sender, DoWorkEventArgs e)
        {
            for (int i = 0; i < (int)e.Argument; i++)
            {
                if (background_worker.CancellationPending)
                {
                    e.Cancel = true;
                    break;
                }
                Parameters parameter = Paint();
                background_worker.ReportProgress((100 * i) / (int)e.Argument + 1, parameter);
                Thread.Sleep(10);
            }
        }

        void background_worker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            if (e.Cancelled)
            {
                MessageBox.Show("BackgroundWorker canceled");
            }
            else
            {
                MessageBox.Show("BackgroundWorker ended successfully");
            }
        }
        void background_worker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            Parameters parameter = e.UserState as Parameters;
            Ellipse ellipse = new Ellipse();
            ellipse.Width = parameter.Size.Width;
            ellipse.Height = parameter.Size.Height;
            ellipse.Fill = new SolidColorBrush(parameter.Color);
            Canvas.SetTop(ellipse, parameter.Location.Y);
            Canvas.SetLeft(ellipse, parameter.Location.X);
            canvas.Children.Add(ellipse);

            txtInterationCounter.Text = e.ProgressPercentage.ToString() + " %";
        }
        private Parameters Paint()
        {
            Parameters parameter;
            Random rnd = new Random();
            parameter = new Parameters();
            parameter.Size = new Size(rnd.Next(10, 100), rnd.Next(10, 100));
            parameter.Color = Color.FromRgb((byte)rnd.Next(256), (byte)rnd.Next(256), (byte)rnd.Next(256));
            parameter.Location = new Point(rnd.Next(300), rnd.Next(300));
            return parameter;
        }
        
        private void btnDoSomething_Click(object sender, RoutedEventArgs e)
        {
            background_worker.RunWorkerAsync(1000);
        }

        private void btnStop_Click(object sender, RoutedEventArgs e)
        {
            background_worker.CancelAsync();
        }

        //public static decimal Fibonacci(int n)
        //{
        //    if (n == 0 || n == 1)
        //        return n;
        //    else
        //        return (Fibonacci(n - 1) + Fibonacci(n - 2));
        //}


    }
    class Parameters
    {
        public Size Size { get; set; }
        public Point Location { get; set; }
        public Color Color { get; set; }
    }
}
