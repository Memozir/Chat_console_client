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
    int resp_status = 0;
    do
    {
        std::string result = inter.start(client.user);
        //std::cout << "\n-------\n" << result << "\n-------\n";
        client.send_request(result);
        resp_status = client.recv_responce();
    } while ( resp_status == 0 || resp_status == 2 );

    while (true)
    {
        do
        {
            std::string request = inter.main_choice(client.user, NULL, true);
            client.send_request(request);
        } while (client.recv_responce() == 0);
      
    }
    
    client.shutdown_connection(SD_BOTH);
    client.clean();
}
