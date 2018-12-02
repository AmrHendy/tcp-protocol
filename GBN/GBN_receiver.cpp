//
// Created by arsanuos on 12/3/18.
//

#include "GBN_receiver.h"



GBN_receiver::GBN_receiver(FileHandler file_handler): file_handler(file_handler){
    expected_seq = 0;
}


void GBN_receiver::start(){

    while(1){
        packet pkt = recv_pkt(fd);
        if(!is_corrupt(pkt) && is_expected(pkt)){
            ack_packet ackPacket;
            ackPacket.len = 2 + 4;
            ackPacket.ackno = pkt.seqno;
            send_ack(fd, ackPacket);
            expected_seq++;
            file_hander.write_data(pkt.data);
        }

    }
}

bool GBN_receiver::is_corrupt(packet pkt){
    //TODO:: implement this.
    return false;
}

bool GBN_receiver::is_expected(packet pkt){
    return pkt.seqno == expected_seq;
}
