// Chat_console_client.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Client.h"
#include "string"

int __cdecl main(int argc, const char* argv[])
{
    Client client;
  
    client.init(argc, argv);
    client.socket_init(argc, argv);
    std::string response;
    while (true)
    {
        getline(std::cin, response);

        if (response.compare("exit") == 0)
        {
            break;
        }

        client.send_request(response);
        client.recv_responce();
    }

    
    client.shutdown_connection(SD_BOTH);
    client.clean();
}
