#include "Interface.h"

void Interface::start()
{
	std::cout << "Registration - 1\n";
	std::cout << "Authentication - 2\n";
}

void Interface::main_choice()
{
	std::cout << "View users - 2\n";
	std::cout << "View messages - 3\n";
	std::cout << "View message from user - 4\n";
	std::cout << "Send message - 5\n";
	std::cout << "Dissconnect - 6\n";

	switch ((Protocol::Operations)request->code)
	{
	case Protocol::Operations::REGISTRATION:
		result = registration(request->entities);
		break;
	case Protocol::Operations::AUTH:
		result = auth(request->entities);
		break;
	case Protocol::Operations::MESSAGE_LIST:
		result = message_count(request->entities);
		break;
	case Protocol::Operations::USER_LIST:
		result = &users;
		break;
	case Protocol::Operations::USER_MESSAGE:
		result = get_user_msg(request->entities);
		break;
	case Protocol::Operations::SEND_MESSAGE:
		result = send_message(request->entities);
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
