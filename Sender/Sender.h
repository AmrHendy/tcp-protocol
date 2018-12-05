//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_SENDER_H
#define TCP_PROTOCOL_SENDER_H

#include "../Packet/Packet.h"
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include<netinet/in.h>

class Sender {

private:
    struct sockaddr *socket_address;

public:
    explicit Sender(struct sockaddr *socket_addres);
    ~Sender();

    int send_packet(Packet packet, int socket_fd);
};


#endif //TCP_PROTOCOL_SENDER_H
