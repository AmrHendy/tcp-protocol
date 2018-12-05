//
// Created by Amr Hendy on 12/5/2018.
//

#include "Receiver.h"

// fill the socket address with the sender address
Packet Receiver::receive_packet(int socket_fd, struct sockaddr *socket_address) {
    Packet packet;
    int bytes = recvfrom(socket_fd, &packet, sizeof(packet),
                     0, (struct sockaddr*)socket_address, sizeof(socket_address));
    if(bytes != sizeof(Packet)){
        perror('Not received all the packet data');
    }
    return packet;
}

// fill the socket address with the sender address
Ack_Packet Receiver::receive_ack_packet(int socket_fd, struct sockaddr *socket_address) {
    Ack_Packet ack_packet;
    int bytes = recvfrom(socket_fd, &ack_packet, sizeof(ack_packet),
                         0, (struct sockaddr*)socket_address, sizeof(socket_address));
    if(bytes != sizeof(Ack_Packet)){
        perror('Not received all the packet data');
    }
    return ack_packet;
}

// fill the socket address with the sender address
Ack_Server_Packet Receiver::receive_ack_server_packet(int socket_fd, struct sockaddr *socket_address) {
    Ack_Server_Packet ack_server_packet;
    int bytes = recvfrom(socket_fd, &ack_server_packet, sizeof(ack_server_packet),
                         0, (struct sockaddr*)socket_address, sizeof(socket_address));
    if(bytes != sizeof(Ack_Server_Packet)){
        perror('Not received all the packet data');
    }
    return ack_server_packet;
}
