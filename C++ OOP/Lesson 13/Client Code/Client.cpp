#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "Client.h"
#include <exception>
#include <string>
#include <iostream>

Client::Client()
{
	// we connect to server that uses TCP. thats why SOCK_STREAM & IPPROTO_TCP
	_clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_clientSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");

}

Client::~Client()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_clientSocket);
	}
	catch (...) {}
}


void Client::connectToServer(std::string serverIP, int port)
{

	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(port); // port that server will listen to
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr =  inet_addr(serverIP.c_str());    // the IP of the server

	// the process will not continue until the server accepts the client
	int status = connect(_clientSocket, (struct sockaddr*)&sa, sizeof(sa));

	if (status == INVALID_SOCKET)
		throw std::exception("Cant connect to server");
}

void Client::startConversation()
{

	char m[39];
	recv(_clientSocket, m, 38, 0);
	m[38] = 0;
	std::cout << "Message from server: " << m << std::endl;

	std::string s;
	std::cout << "enter name (4 bytes): " << std::endl;
	std::cin >> s;
	send(_clientSocket, s.c_str(), s.size(), 0);  // last parameter: flag. for us will be 0.
	std::cout << "Message send to server: " << std::endl;


	recv(_clientSocket, m, 3, 0);
	m[3] = 0;
	std::cout << "Message from server: " << m << std::endl;
}