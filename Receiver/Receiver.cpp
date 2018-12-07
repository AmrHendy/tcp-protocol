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
Ack_Packet Receiver::receive_ack_packet(int socket_fd, struct sockaddr *socket_address, int& status, int TIMEOUT) {
    clock_t begin = clock();
    while((clock() - begin)/ CLOCKS_PER_SEC < TIMEOUT){
        Ack_Packet ack_packet;
        int bytes = recvfrom(socket_fd, &ack_packet, sizeof(ack_packet),
                             0, (struct sockaddr*)socket_address, sizeof(socket_address));
        if(bytes > 0){
            status = 1;
            return ack_packet;
        }
    }
    status = 0;
    return Ack_Packet();
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
