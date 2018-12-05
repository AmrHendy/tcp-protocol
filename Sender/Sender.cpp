//
// Created by Amr Hendy on 12/5/2018.
//

#include "Sender.h"

Sender::Sender(sockaddr *socket_addres) {
    Sender::socket_address = socket_addres;
}

Sender::~Sender() {
    delete(socket_address);
    free(this);
}

int Sender::send_packet(Packet packet, int socket_fd) {
    sendto(socket_fd, (void*) &packet, sizeof(packet), 0, (struct sockaddr*)&socket_address, sizeof(socket_address));
}
