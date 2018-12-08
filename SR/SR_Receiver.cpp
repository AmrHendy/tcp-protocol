//
// Created by Amr Hendy on 08/12/2018.
//

#include "SR_Receiver.h"

int cwnd = 10;
map<int, Packet> received;
int start_window_packet;
int end_window_packet;

SR_Receiver::SR_Receiver(int socket_fd, string file_path, int total_packets) {
    SR_Receiver::socket_fd = socket_fd;
    SR_Receiver::file_path = file_path;
    writer = FileWriter(file_path);
    sender = Sender(NULL);
    received.clear();
    start_window_packet = 0;
    end_window_packet = min(cwnd - 1, total_packets - 1);
}

SR_Receiver::~SR_Receiver(){
    ~Sender(sender);
    ~FileWriter(writer);
    free(this);
}

void SR_Receiver::recevFile(){

}
