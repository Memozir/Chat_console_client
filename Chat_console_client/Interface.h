#pragma once
#include <iostream>
#include <string>

#include "RequestParser.h"
#include "Protocol.h"
#include "User.h"

class Interface
{
public:
	std::string start();
	std::string main_choice(int choice = NULL, User *user=nullptr, bool enter_mode = false);
	void error();

	std::vector<std::string> send_message(User* user);
	std::vector<std::string> registration();
	std::vector<std::string> auth(User* user);
	std::vector<std::string> user_list(User* user);
	std::vector<std::string> message_from(User* user);
};

