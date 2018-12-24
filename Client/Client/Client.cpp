//
// Created by Amr Hendy on 11/28/2018.
//

#include "Client.h"
#include "../Stop and Wait/StopAndWait.h"
#include "../SR/SR_Receiver.h"
#include "../GBN/GBN_receiver.h"

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

//Client::~Client() {
    //you don't need to free.
    // kindly read this https://stackoverflow.com/questions/4979681/how-to-properly-free-a-stdstring-from-memory
    /*if (!server_ip_address.empty()) {
        free(server_ip_address);
    }
    if (!requested_file_name.empty()) {
        free(requested_file_name);
    }*/
    //free(this);
//}

void Client::init_client_socket() {
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
}

void Client::connect_to_server() {
    init_client_socket();
    memset(&serv_address, 0, sizeof(serv_address));

    // Filling server information
    serv_address.sin_family = AF_INET;
    serv_address.sin_port = htons(3000);
    serv_address.sin_addr.s_addr = INADDR_ANY;
    printf("client is ready.\n");

}

uint32_t Client::send_request_to_server() {
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
    printf("Start sending req.\n");
    // send the file name packet
    Packet packet = PacketHandler::create_packet(strdup(requested_file_name.c_str()), 0 , requested_file_name.size());
    Sender sender = Sender(serv_address);
    sender.send_packet(packet, sock_fd);
    printf("req sent.\n");
    /*
     * wait until receive ack from server
     */
    Ack_Server_Packet server_ack_packet =  Receiver::receive_ack_server_packet(sock_fd, serv_address);
    printf("ack received.\n");
    return server_ack_packet.packets_numbers;
}

void Client::receive_file(int strategy_option) {
    uint32_t number_of_packets = send_request_to_server();
    cout << "must receive " << number_of_packets << " packet" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    if (strategy_option == 0) {
        StopAndWait stopAndWait(sock_fd, requested_file_name);
        stopAndWait.recevFile(number_of_packets, serv_address);
    } else if (strategy_option == 1) {
        // selective repeat
        SR_Receiver SR(sock_fd, requested_file_name, number_of_packets, serv_address);
        SR.recevFile();
    } else {
        // GBN
        GBN_receiver gbn(requested_file_name, sock_fd, serv_address, number_of_packets);
        gbn.start();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
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
