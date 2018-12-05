//
// Created by Amr Hendy on 11/28/2018.
//

#ifndef TCP_PROTOCOL_SERVER_H
#define TCP_PROTOCOL_SERVER_H

using namespace std;

#include <string>
#include <cstdio>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../File Handler/FileReader.h"
#include "../Utils/constants.h"

class Server {

private:
    int server_port_number;
    int maximum_window_size;
    int random_seed;
    double packet_loss_prob;
    int active_clients;
    int server_socket_fd;
    const int MAX_ALLOWED_CONNECTIONS = 20;

public:
    Server(string server_conf_file_dir);

    ~Server();

    void start_server(int strategy_option);

private:
    void init_server();

    void handle_client(int client_socket_fd);

    void receive_request_from_client(int client_socket_fd);

    void send_file(int client_socket_fd);
};


#endif //TCP_PROTOCOL_SERVER_H
