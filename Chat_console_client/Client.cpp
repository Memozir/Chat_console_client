#include "Client.h"

void Client::init(int argc, const char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << std::endl;
		exit(1);
	}

	int res = WSAStartup(MAKEWORD(2, 2), &ws);

	if (res != 0)
	{
		int error = WSAGetLastError();
		std::cout << "WSA START ERROR: " << error << "\n";
		exit(1);
	}
}

void Client::socket_init(int argc, const char* argv[])
{
	ZeroMemory(&addr, sizeof(addr));
	addr.ai_family = AF_UNSPEC;
	addr.ai_socktype = SOCK_STREAM;
	addr.ai_protocol = IPPROTO_TCP;

	int res = getaddrinfo(argv[1], "27015", &addr, &result);

	if (res != 0)
	{
		std::cout << "Gettaddrinfo failed: " << res << std::endl;
		WSACleanup();
		exit(1);
	}

	for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
	{
		sock = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

		if (sock == INVALID_SOCKET)
		{
			std::cout << "Socket failed: " << WSAGetLastError() << std::endl;
			WSACleanup();
			exit(1);
		}

		int res = connect(sock, ptr->ai_addr, (int)ptr->ai_addrlen);
		if (res == SOCKET_ERROR) {
			//closesocket(sock);
			//sock = INVALID_SOCKET;
			continue;
		}
		break;
	}

	freeaddrinfo(result);

	if (sock == INVALID_SOCKET) {
		std::cout << "Unable to connect";
		WSACleanup();
		exit(1);
	}
}

void Client::shutdown_connection(int type)
{
	int res = shutdown(sock, type);
	if (res == SOCKET_ERROR) {
		std::cout << "shutdow failed: " << WSAGetLastError() << std::endl;
		closesocket(sock);
		WSACleanup();
		exit(1);
	}
}

void Client::send_request(std::string request)
{
	int res = send(sock, request.c_str(), request.size(), 0);
	if (res == SOCKET_ERROR)
	{
		std::cout << "Send failed: " << WSAGetLastError();
		closesocket(sock);
		WSACleanup();
		exit(1);
	}
}

int Client::recv_responce()
{
	int res = 0;
	std::cout << "Process receiving...\n" << std::endl;
	res = recv(sock, &recv_buf[0], recv_len, 0);
	if (res > 0)
	{
		printf("Bytes received: %d\n\n", res);
		Interface inter;
		inter.display(recv_buf);
		recv_buf.clear();
	}
	else if (res == 0)
		printf("Connection closed\n");
	else
	{
		std::cout << "Recieve failed: " << WSAGetLastError() << std::endl;
		return 0;
	}
}

void Client::clean()
{
	closesocket(sock);
	WSACleanup();
}
