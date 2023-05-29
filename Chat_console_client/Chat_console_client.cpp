// Chat_console_client.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "string"

#include "Client.h"
#include "Interface.h"
#include "User.h"

int __cdecl main(int argc, const char* argv[])
{
    Client client;
  
    client.init(argc, argv);
    client.socket_init(argc, argv);
    std::string response;
    client.recv_responce();

    Interface inter;

    std::string result = inter.start();
    client.send_request(result);
    client.recv_responce();

    while (true)
    {
        getline(std::cin, response);

        if (response.compare("0") == 0)
        {
            break;
        }

        client.send_request(response);
        client.recv_responce();
    }

    
    client.shutdown_connection(SD_BOTH);
    client.clean();
}
