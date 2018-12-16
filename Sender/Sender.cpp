//
// Created by Amr Hendy on 12/5/2018.
//

#include "Sender.h"

Sender::Sender(sockaddr_in socket_addres) {
    Sender::socket_address = socket_addres;
}

Sender::Sender() {

}

void Sender::send_packet(Packet packet, int socket_fd) {
    cout << "sending packet " << packet.seqno << endl;
    sendto(socket_fd, &packet, sizeof(packet),
            MSG_CONFIRM,
            (const struct sockaddr*)&socket_address,
                    sizeof(socket_address));
}

void Sender::send_ack(Ack_Packet ack_packet, int socket_fd) {
    sendto(socket_fd, &ack_packet, sizeof(ack_packet), MSG_CONFIRM, (const struct sockaddr*)&socket_address, sizeof(socket_address));
}

void Sender::send_server_ack(Ack_Server_Packet ack_server_packet, int socket_fd) {
    sendto(socket_fd, &ack_server_packet,
            sizeof(ack_server_packet), MSG_CONFIRM,
            (const struct sockaddr*)&socket_address,
                    sizeof(socket_address));
}
