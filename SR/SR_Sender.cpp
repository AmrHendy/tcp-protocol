//
// Created by lenovo pc on 04/12/2018.
//

#include "SR_Sender.h"

SR_Sender::SR_Sender(FileHandler file_handler, int client_fd) : file_handler(file_handler) {
    this->client_fd = client_fd;
}

void SR_Sender::start() {

}

void SR_Sender::rcv_ack(int seq_num) {
    int first_unack = -1;
    for (int i = 0; i < cwnd; i++) {
        if (window[i].seqno == seq_num) {
            acked[i] = true;
        }
        if(!acked[i] && first_unack == -1){
            first_unack = i;
        }
    }
    if (seq_num == base) {
        base = first_unack;
    }
}
