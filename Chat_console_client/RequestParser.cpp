#include "RequestParser.h"

int get_str_size(std::string str)
{
	int i = 0;
	const char* buf = str.c_str();

	while (buf[i] != '\0' && (int)buf[i] >= 0)
	{
		i++;
	}

	return i;
}

RequestParser::RequestParser(std::string request)
{
	std::cout << request.c_str();
	size = get_str_size(request);
	//std::cout << "\n--SIZE--\n" << this->size << "\n--SIZE--\n";
	//this->request.copy(&request[0], size);
	for (int i = 0; i < size; i++)
	{
		this->request.push_back(request.c_str()[i]);
	}

	//std::cout << "\n--RequestParser--\n" << this->request << "\n--RequestParser--\n";
}

int RequestParser::get_code()
{
	std::string str_code = entities.at(0);
	entities.erase(entities.begin());

	int code = atoi(str_code.c_str());

	return code;
}

void RequestParser::print_parsed()
{
	int size = entities.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << entities.at(i) << std::endl;
	}
}

RequestParser::Request RequestParser::parse()
{
	//int request_len = this->request.size();
	//int request_len = get_str_size(this->request);
	std::string buf;

	for (int i = 0; i < size; i++)
	{
		if (request[i] == '/')
		{
			entities.push_back(buf);
			buf.clear();
		}
		else
		{
			buf += request[i];
		}
	}
	entities.push_back(buf);
	int code = get_code();
	Request request_result = {
		code,
		entities
	};

	return request_result;
}
