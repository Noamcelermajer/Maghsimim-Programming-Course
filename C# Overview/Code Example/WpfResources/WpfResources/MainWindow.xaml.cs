using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfResources
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void btn_Click(object sender, RoutedEventArgs e)
        {
            TextBlock txt = new TextBlock();
            txt.Text = "Israel in 3D";
            txt.FontSize = 30;
            txt.Foreground = new SolidColorBrush(Colors.Red);
            mainPnl.Children.Add(txt);
            Image img = new Image();
            img.Width = 400;
            img.Height = 300;
            img.Source = new BitmapImage(new Uri("/Images/Israel3D.jpg", UriKind.Relative));
            mainPnl.Children.Add(img);


        }
    }
}
