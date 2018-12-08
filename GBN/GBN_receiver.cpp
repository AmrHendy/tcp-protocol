//
// Created by arsanuos on 12/3/18.
//

#include "GBN_receiver.h"



GBN_receiver::GBN_receiver(FileWriter fileWriter, FileReader fileReader): fileWriter(fileWriter), fileReader(fileReader){
    expected_seq = 0;
}


void GBN_receiver::start(){

    while(1){
        Packet pkt = recv_pkt(fd);
        if(!is_corrupt(pkt) && is_expected(pkt)){
            Ack_Packet ackPacket;
            ackPacket.len = 2 + 4;
            ackPacket.ackno = pkt.seqno;
            send_ack(fd, ackPacket);
            expected_seq++;
            fileWriter.write_chunk(pkt.data);
        }

    }
}

bool GBN_receiver::is_corrupt(Packet pkt){
    //TODO:: implement this.
    return false;
}

bool GBN_receiver::is_expected(Packet pkt){
    return pkt.seqno == expected_seq;
}
