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
    public partial class frmStudents : Form
    {
        private string _userName;

        public frmStudents()
        {
            InitializeComponent();
        }

        public string Username
        {
            get { return _userName; }
            set { _userName = value; lblUsername.Text = value; }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Environment.Exit(100);
        }
        private void frmStudents_FormClosed(object sender, FormClosedEventArgs e)
        {
            MessageBox.Show("BYE BYE");
        }
    }
}
