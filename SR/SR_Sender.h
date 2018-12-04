//
// Created by lenovo pc on 04/12/2018.
//

#ifndef TCP_PROTOCOL_SR_SENDER_H
#define TCP_PROTOCOL_SR_SENDER_H

#include <vector>
#include "../packet.h"
#include "../ack_packet.h"
#include "../File Handler/FileHandler.h"

class SR_Sender {
private:
    int base = 0;
    int next_seq_num = 0;
    int threshold = 10;
    int cwnd = 1;
    double fraction = 0;
    int received;
    FileHandler file_handler;
    vector<packet> window;
    vector<bool> acked;
    int client_fd;
public:
    SR_Sender(FileHandler file_handler, int client_fd);
    void start();
    void rcv_ack(int seq_num);
};


#endif //TCP_PROTOCOL_SR_SENDER_H
