#include "Interface.h"

std::string Interface::start()
{
	std::cout << "Registration - 1\n";
	std::cout << "Authentication - 2\n";

	int choice;

	std::cin >> choice;

	return main_choice(choice, nullptr, false);
}

std::vector<std::string> Interface::send_message(User* user)
{

}

std::vector<std::string> Interface::registration()
{
	std::string username, password;

	std::cout << "Enter username: \n";
	std::cin >> username;

	std::cout << "Enter password: \n";
	std::cin >> password;

	std::vector<std::string> result;
	result.push_back("0");
	result.push_back(username);
	result.push_back(password);

	return result;
}

std::vector<std::string> Interface::auth(User* user)
{
	std::string username, password;

	std::cout << "Enter username: \n";
	std::cin >> username;

	std::cout << "Enter password: \n";
	std::cin >> password;

	std::vector<std::string> result;
	result.push_back("1");
	result.push_back(username);
	result.push_back(password);

	return result;
}

std::vector<std::string> Interface::user_list(User* user)
{

}

std::vector<std::string> Interface::message_from(User* user)
{

}

std::string Interface::main_choice(int choice = NULL, User* user = nullptr, bool enter_mode = false)
{
	if (enter_mode)
	{
		std::cout << "View users - 2\n";
		std::cout << "View messages - 3\n";
		std::cout << "View message from user - 4\n";
		std::cout << "Send message - 5\n";
		std::cout << "Dissconnect - 6\n";

		std::cin >> choice;
	}

	std::vector<std::string> result;

	switch ((Protocol::Operations)choice)
	{
	case Protocol::Operations::REGISTRATION:
		result = registration();
		break;
	case Protocol::Operations::AUTH:
		result = auth(user);
		break;
	case Protocol::Operations::MESSAGE_LIST:
		result = message_count(user);
		break;
	case Protocol::Operations::USER_LIST:
		result = user_list(user);
		break;
	case Protocol::Operations::USER_MESSAGE:
		result = get_user_msg();
		break;
	case Protocol::Operations::SEND_MESSAGE:
		result = send_message(user);
		break;
	case Protocol::Operations::DISCONNECT:
		std::string dissconnect = "0";
		return dissconnect;
		break;
	}

}

void Interface::error()
{
	std::cout << "Operation failed\n";
}
