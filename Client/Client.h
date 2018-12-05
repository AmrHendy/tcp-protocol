//
// Created by Amr Hendy on 11/28/2018.
//

#ifndef TCP_PROTOCOL_CLIENT_H
#define TCP_PROTOCOL_CLIENT_H

using namespace std;

#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory>
#include <ctime>


#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../File Handler/FileReader.h"
#include "../Utils/constants.h"
#include "../Packet/PacketHandler.h"

class Client {

private:
    string server_ip_address;
    int server_port_number;
    int client_port_number;
    string requested_file_name;
    int initial_window_size;
    int sock_fd;

public:
    explicit Client(string client_conf_file_dir);
    ~Client();

    void connect_to_server();
    void receive_file(int strategy_option);

private:
    void init_client_socket();
    void send_request_to_server();
};


#endif //TCP_PROTOCOL_CLIENT_H
