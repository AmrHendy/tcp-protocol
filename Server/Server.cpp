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
    address.sin_family = AF_INET; //IPv$
    // Creating socket file descriptor for the server
    if ((server_socket_fd = socket(address.sin_family, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    int opt = 1;
    // Check if it is used and forcefully attaching socket to our desired address and port
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt Error");
        exit(EXIT_FAILURE);
    }
    /*
     * build the server's Internet address
     */
    //bzero((char *) &address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(server_port_number);
    int ret = bind(server_socket_fd, (struct sockaddr *)&address, sizeof(address));
    if (ret < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void Server::start_server() {
    init_server();
    printf("Server is waiting for clients\n");
    while(1) {
        /* server main loop */
        printf("Successfully Connected with a Client");
        struct sockaddr_in client_address;
        const int MAXSIZE = 5000;
        char * buffer = (char*) malloc(MAXSIZE);
        // receive the file name
        int n = recvfrom(server_socket_fd, buffer, sizeof(buffer),
                         0, (struct sockaddr*)&client_address, sizeof(client_address));
        // send ack with number of packets
        // send the file
        printf("Finished Client with fd = %d \n",client_socket_fd);
    }
}

// That thread will serve the single client
void Server::handle_client(int client_socket_fd) {

}