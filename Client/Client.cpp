//
// Created by Amr Hendy on 11/28/2018.
//

#include "Client.h"

int sendBufferToSocket(char *buffer, int buffer_size, int sock_fd);

Client::Client(string client_conf_file_dir) {
    ifstream conf_file(client_conf_file_dir);
    if (conf_file) {
        conf_file >> server_ip_address >> server_port_number;
        conf_file >> client_port_number;
        conf_file >> requested_file_name;
        conf_file >> initial_window_size;
    } else {
        perror("Configuration File not found !!\n");
        exit(EXIT_FAILURE);
    }
}

Client::~Client() {
    //you don't need to free.
    // kindly read this https://stackoverflow.com/questions/4979681/how-to-properly-free-a-stdstring-from-memory
    /*if (!server_ip_address.empty()) {
        free(server_ip_address);
    }
    if (!requested_file_name.empty()) {
        free(requested_file_name);
    }*/
    free(this);
}

void Client::init_client_socket() {
    sock_fd = static_cast<int>(socket(AF_INET, SOCK_DGRAM, 0));
    //Need to check if it's < 0
}

void Client::connect_to_server() {
    struct sockaddr_in serv_address;
    char buffer[1024] = {0};

    memset(&serv_address, 0, sizeof(serv_address));

    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(client_port_number);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip_address.c_str(), &serv_address.sin_addr) <= 0){
        perror("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }
    if (connect(sock_fd, (struct sockaddr *) &serv_address, sizeof(serv_address)) < 0){
        perror("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }
}

void Client::send_request_to_server() {
    /*
    auto *request_buffer = (char *) malloc(1000);
    memset(request_buffer, '\0', sizeof(request_buffer));

    int length = sprintf(request_buffer, "GET /%s HTTP/1.1\r\nHOST: %s:%d\r\n\r\n", requested_file_name,
                         server_ip_address, server_port_number);

    //I think this won't help ?!!
    puts(request_buffer);

    if (length > 0) {
        int status = sendBufferToSocket(request_buffer, length, sock_fd);
        if (status == 0) {
            perror("Can't send GET Request from client");
        }
    }
    if (!request_buffer) {
        free(request_buffer);
    }
     */

    // send the file name packet
    Packet packet = PacketHandler::create_packet(strdup(requested_file_name.c_str()), 0 , requested_file_name.size());
    Sender sender = Sender(NULL);
    sender.send_packet(packet, sock_fd);
    /*
     * wait until receive ack from server
     */
}

void Client::receive_file(int strategy_option) {
    send_request_to_server();
    if (strategy_option == 0) {
        // stop and wait
    } else if (strategy_option == 1) {
        // selective repeat
    } else {
        // GBN
    }
    printf("Client finished\n");
}

/* sends buffer of chars over socket */
int sendBufferToSocket(char *buffer, int buffer_size, int sock_fd) {
    int sent = 0;
    const int TIMEOUT = 5;
    clock_t curTime = clock();
    // checking Timeout as socket may fail for many many times so we will stop trying to repeat.
    while (sent < buffer_size && (clock() - curTime) / CLOCKS_PER_SEC < TIMEOUT) {
        sent += send(sock_fd, (void *) (buffer + sent), buffer_size - sent, 0);
    }
    if (sent != buffer_size) {
        // then that means not all characters are sent because of timeout */
        return 0;
    }
    return 1;
}
