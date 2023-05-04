
#pragma comment (lib, "ws2_32.lib")

#include <WinSock2.h>
#include <Windows.h>
#include "WSAInitializer.h"
#include "Client.h"
#include <exception>
#include <iostream>

int main()
{
	try
	{
		WSAInitializer wsaInit;
		Client c1;
		c1.connectToServer("127.0.0.1", 8876);
		c1.startConversation();

	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}