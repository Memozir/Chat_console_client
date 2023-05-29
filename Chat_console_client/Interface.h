#pragma once
#include <iostream>

#include "RequestParser.h"
#include "Protocol.h"
#include <string>

class Interface
{
public:
	void start();
	void main_choice(int choice);
	void error();

	std::vector<std::string> send_message();
	std::vector<std::string> registration();
	std::vector<std::string> auth();
	std::vector<std::string> user_list();
	std::vector<std::string> message_from();
};

