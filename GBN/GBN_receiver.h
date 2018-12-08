//
// Created by arsanuos on 12/3/18.
//

#ifndef TCP_PROTOCOL_GBN_RECEIVER_H
#define TCP_PROTOCOL_GBN_RECEIVER_H

#include "helper.h"
#include "../File Handler/FileReader.h"
#include "../File Handler/FileWriter.h"

class GBN_receiver {

    private:
        int fd;
        int expected_seq;
        FileReader fileReader;
        FileWriter fileWriter;

    public:
        GBN_receiver(FileWriter fileWriter, FileReader fileReader);
        void start();
        bool is_corrupt(Packet pkt);
        bool is_expected(Packet pkt);
};


#endif //TCP_PROTOCOL_GBN_RECEIVER_H
