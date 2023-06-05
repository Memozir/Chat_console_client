#include "Interface.h"

std::string Interface::start(User &user)
{
	std::cout << "Registration - 0\n";
	std::cout << "Authentication - 1\n";

	int choice;

	std::cin >> choice;

	return main_choice(user, choice, false);
}

std::vector<std::string> Interface::send_message(User& user)
{
	int user_count;
	std::vector<std::string> result, recievers;
	result.push_back("5");
	result.push_back(user.username);

	std::string message;
	std::cout << "Enter message (max 500 symbols): \n";
	std::cin >> message;

	result.push_back(message);

	std::cout << "Enter user count to send: \n";
	std::cin >> user_count;

	for (int i = 0; i < user_count; i++)
	{
		std::cout << "Enter user " + std::to_string(i++) << " : \n";
		std::string reciever;
		std::cin >> reciever;
		result.push_back(reciever);
	}

	return result;
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

std::vector<std::string> Interface::auth(User& user)
{
	std::string username, password;

	std::cout << "Enter username: \n";
	std::cin >> username;

	std::cout << "Enter password: \n";
	std::cin >> password;

	user.username = username;
	user.pass = password;

	std::vector<std::string> result;
	result.push_back("1");
	result.push_back(username);
	result.push_back(password);

	return result;
}

std::vector<std::string> Interface::user_list(User& user)
{
	std::vector<std::string> result;
	result.push_back("2");
	result.push_back(user.username);

	return result;
}

std::vector<std::string> Interface::message_from(User& user)
{
	std::vector<std::string> result;
	result.push_back("4");
	result.push_back(user.username);

	std::string user_from;
	std::cout << "Enter whose messages to read: \n";
	std::cin >> user_from;
	result.push_back(user_from);

	return result;
}

std::vector<std::string> Interface::message_count(User& user)
{
	std::vector<std::string> result;
	result.push_back("3");
	result.push_back(user.username);

	return result;
}

std::string Interface::main_choice(User& user, int choice, bool enter_mode)
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
		result = message_from(user);
		break;
	case Protocol::Operations::SEND_MESSAGE:
		result = send_message(user);
		break;
	case Protocol::Operations::DISCONNECT:
		std::string dissconnect = "0";
		return dissconnect;
		break;
	}
	
	return generate_response(result);
}

void Interface::display_registration(std::vector<std::string> data)
{
	if (data.at(0).compare("1"))
	{
		std::cout << "Registration failed: username already exists\n";
		return;
	}

	std::cout << "Registration was success!\n";
}

void Interface::display_auth(std::vector<std::string> data)
{
	if (data.at(0).compare("1"))
	{
		std::cout << "Authentication failed\n";
		return;
	}

	std::cout << "Authentication was success!\n";
}

void Interface::display_send_message(std::vector<std::string> data)
{
	if (data.at(0).compare("1"))
	{
		std::cout << "Operation send message failed\n";
		return;
	}

	std::cout << "Message was successfully sended\n";
}
void Interface::display_user_list(std::vector<std::string> data)
{
	if (data.at(0).compare("1"))
	{
		std::cout << "User list display error\n";
		return;
	}

	if (data.empty() == 0)
	{
		std::cout << "No one is online\n";
		return;
	}

	std::cout << "Users online:\n";
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data.at(i) << std::endl;
	}

	std::cout << "\n";
}

void Interface::display_message_from(std::vector<std::string> data)
{
	if (data.at(0).compare("0") == 0)
	{
		std::cout << "No user with such username\n";
		return;
	}

	for (int i = 0; i < data.size(); i++)
	{
		std::cout << i << ". " << data.at(i) << "\n";
	}

	std::cout << "\n";
}
void Interface::display_message_count(std::vector<std::string> data)
{
	if (data.at(0).compare("0") == 0)
	{
		std::cout << "Message count error\n";
		return;
	}

	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data.at(i)<< "\n";
	}
}

void Interface::display(std::string response)
{
	RequestParser parser(response);
	RequestParser::Request response_entity = parser.parse();
	
	switch ((Protocol::Operations)response_entity.code)
	{
	case Protocol::Operations::REGISTRATION:
		display_registration(response_entity.entities);
		break;
	case Protocol::Operations::AUTH:
		display_auth(response_entity.entities);
		break;
	case Protocol::Operations::MESSAGE_LIST:
		display_message_count(response_entity.entities);
		break;
	case Protocol::Operations::USER_LIST:
		display_user_list(response_entity.entities);
		break;
	case Protocol::Operations::USER_MESSAGE:
		display_message_from(response_entity.entities);
		break;
	case Protocol::Operations::SEND_MESSAGE:
		display_send_message(response_entity.entities);
		break;
	//case Protocol::Operations::DISCONNECT:
	//	std::string dissconnect = "0";
	//	return dissconnect;
	//	break;
	}
}

void Interface::error()
{
	std::cout << "Operation failed\n";
}
