#pragma once
#include <iostream>
#include <vector>

int get_str_size(std::string str);

class RequestParser
{
private:
	std::string request;
	std::vector<std::string> entities;

	int get_code();

	//Request* request_entity;

public:
	RequestParser(std::string request);
	//~RequestParser();

	int size = 0;

	struct Request {
		int code;
		std::vector<std::string> entities;
	};

	Request parse();
	void print_parsed();
};

