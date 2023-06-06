#pragma once

#include "RequestParser.h"

std::string generate_response(std::vector<std::string> db_result);

class Protocol
{
private:
	RequestParser::Request* request;

	std::string generate_response(std::vector<std::string> db_result);

public:
	Protocol(std::string request);

	enum class Operations
	{
		REGISTRATION,
		AUTH,
		USER_LIST,
		MESSAGE_LIST,
		USER_MESSAGE,
		SEND_MESSAGE,
		DISCONNECT
	};

};

