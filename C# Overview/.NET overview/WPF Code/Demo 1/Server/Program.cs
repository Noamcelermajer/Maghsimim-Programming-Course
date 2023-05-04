using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Server
{
    class Program
    {
        static private TcpListener tcpListener;
        static private Thread listenThread;

        static void Main(string[] args)
        {
            tcpListener = new TcpListener(IPAddress.Any, 4242);
            listenThread = new Thread(new ThreadStart(ListenForClients));
            listenThread.Start();

        }

        static private void ListenForClients()
        {
            tcpListener.Start();

            while (true)
            {
                //blocks until a client has connected to the server
                TcpClient client = tcpListener.AcceptTcpClient();

                //create a thread to handle communication with connected client
                Thread clientThread = new Thread(new ParameterizedThreadStart(HandleClientComm));
                clientThread.Start(client);
            }
        }

        static private void HandleClientComm(object client)
        {
            TcpClient tcpClient = (TcpClient)client;
            NetworkStream clientStream = tcpClient.GetStream();

            byte[] message = new byte[4096];
            int bytesRead;

            while (true)
            {
                bytesRead = 0;

                try
                {
                    //blocks until a client sends a message
                    bytesRead = clientStream.Read(message, 0, 4096);
                }
                catch
                {
                    //a socket error has occured
                    break;
                }

                if (bytesRead == 0)
                {
                    //the client has disconnected from the server
                    break;
                }

                //message has successfully been received - show it in the log console
                Console.WriteLine(new ASCIIEncoding().GetString(message, 0, bytesRead));


                // send answer back to server
                byte[] buffer = new ASCIIEncoding().GetBytes("Hello to you as well, dear client!");
                clientStream.Write(buffer, 0, buffer.Length);
                clientStream.Flush();
            }

            

            tcpClient.Close();
        }

        // TODO: add try-catch

    }
}
