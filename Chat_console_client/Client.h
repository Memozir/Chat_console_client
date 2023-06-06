#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

//#include "RequestParser.h"
#include "Protocol.h"
#include "Interface.h"

#pragma comment(lib, "Ws2_32.lib")
class Client
{
public:

	User user;

	Client(){};
	//~Client();

	void init(int argc, const char* argv[]);
	void socket_init(int argc, const char* argv[]);
	void shutdown_connection(int type);
	void send_request(std::string request);
	int recv_responce();
	void clean();

private:
	WSADATA ws;
	SOCKET sock;
	addrinfo addr, *result, *ptr;
	
	std::string send_buf;
	const int send_len = 512;

	std::string recv_buf;
	const int recv_len = 512;
};

