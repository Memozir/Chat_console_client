#pragma once
#include <iostream>

#include "RequestParser.h"
#include "Protocol.h"

class Interface
{
public:
	void start();
	void main_choice();
	void error();

	void send_message(std::vector<std::string> entities);
	void registration(std::vector<std::string> entities);
	void auth(std::vector<std::string> entities);
	void user_list(std::vector<std::string> entities);
	void message_from(std::vector<std::string> entities);
};

