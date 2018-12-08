//
// Created by Amr Hendy on 11/28/2018.
//

#include "Server.h"
#include "../File Handler/FileReader.h"
#include "../Stop and Wait/StopAndWait.h"

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

void Server::start_server(int strategy_option) {
    init_server();
    printf("Server is waiting for clients\n");
    while(1) {
        /* server main loop */
        printf("Successfully Connected with a Client");
        struct sockaddr *client_address;
        // receive the file name
        Packet packet = Receiver::receive_packet(server_socket_fd, client_address);
        // checking the file
        FileReader file_reader = FileReader((char*) packet.data, CHUNK_SIZE);
        int number_of_packets = ceil(file_reader.get_file_size() * 1.0 / CHUNK_SIZE);
        // sending the ack with the number of packets which will be sended
        Sender sender = Sender(client_address);
        Ack_Server_Packet server_ack_packet;
        server_ack_packet.packets_numbers = number_of_packets;
        sender.send_server_ack(server_ack_packet, server_socket_fd);
        // call the desired method to send the file
        if(strategy_option == 0){
            // stop and wait
            StopAndWait stopAndWait(server_socket_fd, packet.data);
            stopAndWait.sendFile(packet_loss_prob, random_seed);
        }
        else if(strategy_option == 1){
            // selective repeat
        }
        else{
            // GBN
        }
        printf("Finished Client\n");
    }
}