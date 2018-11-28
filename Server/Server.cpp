//
// Created by Amr Hendy on 11/28/2018.
//

#include "Server.h"

Server::Server(string server_conf_file_dir) {
    freopen(server_conf_file_dir.c_str(), "r", stdin);
    cin >> server_port_number >> maximum_window_size >> random_seed >> packet_loss_prob;
    active_clients = 0;
}

void Server::init_server() {
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    // Creating socket file descriptor for the server
    if ((server_socket_fd = socket(address.sin_family, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    int opt = 1;
    // Check if it is used and forcefully attaching socket to our desired address and port
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt Error");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(server_port_number);
    int ret = bind(server_socket_fd, (struct sockaddr *)&address, sizeof(address));
    if (ret < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}
