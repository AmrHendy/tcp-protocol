//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_RECEIVER_H
#define TCP_PROTOCOL_RECEIVER_H

#include "../Packet/Packet.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>

class Receiver {

public:
    explicit Receiver();
    ~Receiver();

    Packet receive_packet(int socket_fd, struct sockaddr *socket_address);
    Ack_Packet receive_ack_packet(int socket_fd, struct sockaddr *socket_address);
    Ack_Server_Packet receive_ack_server_packet(int socket_fd, struct sockaddr *socket_address);
};

#endif //TCP_PROTOCOL_RECEIVER_H
