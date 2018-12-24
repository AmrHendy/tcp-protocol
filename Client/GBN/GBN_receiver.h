//
// Created by arsanuos on 12/3/18.
//

#ifndef TCP_PROTOCOL_GBN_RECEIVER_H
#define TCP_PROTOCOL_GBN_RECEIVER_H

#include "../Packet/PacketHandler.h"
#include "../Packet/Packet.h"
#include "../File Handler/FileWriter.h"
#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../Utils/constants.h"

class GBN_receiver {

    private:
        int fd;
        int expected_seq;
        FileWriter fileWriter;
        struct sockaddr_in server_addr;
        int recvd;
        int total_packets;

    public:
        GBN_receiver(string file_name, int socket_fd, struct sockaddr_in server_addr, int total_packets);
        void start();
        bool is_corrupt(Packet pkt);
        bool is_expected(Packet pkt);
};


#endif //TCP_PROTOCOL_GBN_RECEIVER_H
