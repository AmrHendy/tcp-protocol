//
// Created by arsanuos on 12/3/18.
//

#ifndef TCP_PROTOCOL_GBN_RECEIVER_H
#define TCP_PROTOCOL_GBN_RECEIVER_H

#include "helper.h"
#include "../File Handler/FileHandler.h"

class GBN_receiver {

    private:
        int fd;
        int expected_seq;
        FileHandler file_handler;

    public:
        GBN_receiver(FileHandler file_handler);
        void start();
        bool is_corrupt(packet pkt);
        bool is_expected(packet pkt);
};


#endif //TCP_PROTOCOL_GBN_RECEIVER_H
