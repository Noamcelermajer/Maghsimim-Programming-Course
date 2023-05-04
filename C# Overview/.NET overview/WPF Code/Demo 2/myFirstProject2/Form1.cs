using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace myFirstProject2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Hello world!");
        }

        private void button1_MouseHover(object sender, EventArgs e)
        {
            MessageBox.Show("Hover!");
        }

            
        private void button1_MouseHover2(object sender, EventArgs e)
        {
            MessageBox.Show("Hover2!");
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            MessageBox.Show("Enter!");
        }

        private void erez_event(object sender, EventArgs e)
        {
            }

        private void inbar_event()
        {


        }

        private void erez_test(object sender, MouseEventArgs e)
        {
            MessageBox.Show("DBCLICK");
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            if ( txtPass.Text == "lee")
            {
                //MessageBox.Show("OK");
                frmStudents f = new frmStudents();
                this.Hide();

                f.Username = "erez";

                f.ShowDialog();

            //    MessageBox.Show(f.Username);
                this.Show();
            }
            else
            {
                MessageBox.Show("BAD");
            }
        }
    }
}
