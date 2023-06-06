#pragma once
#include <iostream>
#include <string>

#include "RequestParser.h"
#include "Protocol.h"
#include "User.cpp"

class Interface
{
private:
	//Interface() {};

	int display_registration(std::vector<std::string> data);
	int display_auth(std::vector<std::string> data);
	int display_send_message(std::vector<std::string> data);
	int display_user_list(std::vector<std::string> data);
	int display_message_from(std::vector<std::string> data);
	int display_message_count(std::vector<std::string> data);
public:
	std::string start(User &user);
	std::string main_choice(User& user, int choice = NULL, bool enter_mode = false);
	int display(std::string response);
	void error();

	std::vector<std::string> send_message(User& user);
	std::vector<std::string> registration();
	std::vector<std::string> auth(User& user);
	std::vector<std::string> user_list(User& user);
	std::vector<std::string> message_from(User& user);
	std::vector<std::string> message_count(User& user);
};

