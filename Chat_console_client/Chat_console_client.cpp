// Chat_console_client.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "string"

#include "Client.h"
#include "Interface.h"

int __cdecl main(int argc, const char* argv[])
{
    Client client;
  
    client.init(argc, argv);
    client.socket_init(argc, argv);
    //std::string response;

    Interface inter;

    std::string result = inter.start(client.user);
    std::cout << "\n-------\n" << result << "\n-------\n";
    client.send_request(result);
    client.recv_responce();

    while (true)
    {
        //getline(std::cin, response);
        std::string request = inter.main_choice(client.user, NULL, true);
        client.send_request(request);

        //if (response.compare("0") == 0)
        //{
        //    break;
        //}

        client.recv_responce();
    }

    
    client.shutdown_connection(SD_BOTH);
    client.clean();
}
