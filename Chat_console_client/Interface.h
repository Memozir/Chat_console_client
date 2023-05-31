#pragma once
#include <iostream>
#include <string>

#include "RequestParser.h"
#include "Protocol.h"
#include "User.h"

class Interface
{
private:
	void display_registration(std::vector<std::string> data);
	void display_auth(std::vector<std::string> data);
	void display_send_message(std::vector<std::string> data);
	void display_user_list(std::vector<std::string> data);
	void display_message_from(std::vector<std::string> data);
	void display_message_count(std::vector<std::string> data);
public:
	std::string start();
	std::string main_choice(int choice = NULL, User *user=nullptr, bool enter_mode = false);
	void display(std::string response);
	void error();

	std::vector<std::string> send_message(User* user);
	std::vector<std::string> registration();
	std::vector<std::string> auth(User* user);
	std::vector<std::string> user_list(User* user);
	std::vector<std::string> message_from(User* user);
	std::vector<std::string> message_count(User* user);
};

