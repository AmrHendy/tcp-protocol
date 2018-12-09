//
// Created by Amr Hendy on 12/5/2018.
//

#include "Sender.h"

Sender::Sender(sockaddr *socket_addres) {
    Sender::socket_address = socket_addres;
}

void Sender::send_packet(Packet packet, int socket_fd) {
    sendto(socket_fd, (void*) &packet, sizeof(packet), 0, (struct sockaddr*)&socket_address, sizeof(socket_address));
}

void Sender::send_ack(Ack_Packet ack_packet, int socket_fd) {
    sendto(socket_fd, (void*) &ack_packet, sizeof(ack_packet), 0, (struct sockaddr*)&socket_address, sizeof(socket_address));
}

void Sender::send_server_ack(Ack_Server_Packet ack_server_packet, int socket_fd) {
    sendto(socket_fd, (void*) &ack_server_packet, sizeof(ack_server_packet), 0, (struct sockaddr*)&socket_address, sizeof(socket_address));
}
