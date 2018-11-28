//
// Created by Amr Hendy on 11/28/2018.
//

#include "Client.h"

Client::Client(string client_conf_file_dir) {
    ifstream conf_file(client_conf_file_dir);
    if (conf_file) {
        conf_file >> server_ip_address >> server_port_number;
        conf_file >> client_port_number;
        conf_file >> requested_file_name;
        conf_file >> initial_window_size;
    } else {
        perror("\nConfiguration File not found !!\n");
        exit(EXIT_FAILURE);
    }
}

Client::~Client() {
    if (!server_ip_address.empty()) {
        delete server_ip_address;
    }
    if (!requested_file_name.empty()) {
        delete requested_file_name;
    }
    free(this);
}

void Client::init_client_socket() {

}

void Client::connect_to_server() {

}

void Client::send_request_to_server() {

}

void Client::receive_file() {

}
