using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        bool isBlack = true;

        private void btnCngTxt_Click(object sender, EventArgs e)
        {
            Thread myThread = new Thread(myFunction);
            myThread.Start();


            if (isBlack)
            {
                picAce.Image = WindowsFormsApplication1.Properties.Resources.ace_red;
                isBlack = false;
            }
            else
            {
                picAce.Image = WindowsFormsApplication1.Properties.Resources.ace_black;
                isBlack = true;
            }


            /*if (txtMagshimim.Text.Equals("Magshimim"))
            {
                txtMagshimim.Text = "Button Clicked!";
            }
            else
            {
                txtMagshimim.Text = "Magshimim";
            }*/
        }

        private void myFunction(object obj)
        {
            Thread.Sleep(2000);
            /*MessageBox.Show("something something dark side");

            Invoke((MethodInvoker) delegate { txtMagshimim.Text = "some text from another thread"; });*/

            TcpClient client = new TcpClient();

            IPEndPoint serverEndPoint = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 4242);

            client.Connect(serverEndPoint);

            NetworkStream clientStream = client.GetStream();

            byte[] buffer = new ASCIIEncoding().GetBytes("Hello Server!");

            clientStream.Write(buffer, 0, buffer.Length);
            clientStream.Flush();

            buffer = new byte[4096];
            int bytesRead = clientStream.Read(buffer, 0, 4096);
            Invoke((MethodInvoker)delegate { txtMagshimim.Text = new ASCIIEncoding().GetString(buffer, 0, bytesRead); });

        }

        private void btnAddCards_Click(object sender, EventArgs e)
        {
            // set the location for where we start drawing the new cards (notice the location+height)
            Point nextLocation = new Point(btnAddCards.Location.X, picAce.Location.Y + picAce.Size.Height + 10);

            for (int i = 0; i < 6; i++)
            {
                // create the image object itself
                System.Windows.Forms.PictureBox currentPic = new PictureBox();
                currentPic.Name = "picDynamic" + i; // in our case, this is the only property that changes between the different images
                currentPic.Image = global::WindowsFormsApplication1.Properties.Resources.ace_black;
                currentPic.Location = nextLocation;
                currentPic.Size = new System.Drawing.Size(100, 114);
                currentPic.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;

                // assign an event to it
                currentPic.Click += delegate(object sender1, EventArgs e1) 
                                        {
                                            string currentIndex = currentPic.Name.Substring(currentPic.Name.Length-1);
                                            MessageBox.Show("You've clicked card #" + currentIndex);

                                            // use the delegate's params in order to remove the specific image which was clicked
                                            ((PictureBox)sender1).Hide();
                                            ((PictureBox)sender1).Dispose();
                                       };
                
                // add the picture object to the form (otherwise it won't be seen)
                this.Controls.Add(currentPic);

                // calculate the location point for the next card to be drawn/added
                nextLocation.X += currentPic.Size.Width + 10;
                if (nextLocation.X > this.Size.Width)
                {
                    // move to next line below
                    nextLocation.X = btnAddCards.Location.X;
                    nextLocation.Y += currentPic.Size.Height + 10;
                }
            }
        }

        private void btnOpenAnotherForm_Click(object sender, EventArgs e)
        {
            Form2 frm = new Form2();
            //frm.Show();
            frm.ShowDialog();
        }
    }
}
