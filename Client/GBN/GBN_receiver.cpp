//
// Created by arsanuos on 12/3/18.
//

#include "GBN_receiver.h"



GBN_receiver::GBN_receiver(string file_name, int socket_fd, struct sockaddr_in server_addr, int total_packets): fileWriter(file_name){
    expected_seq = 0;
    fd = socket_fd;
    this->server_addr = server_addr;
    recvd = 0;
    this->total_packets = total_packets;

}


void GBN_receiver::start(){
    Sender sender(server_addr);
    while(1){
        Packet pkt = Receiver::receive_packet(fd, server_addr);
        if(!is_corrupt(pkt) && is_expected(pkt)){
            Ack_Packet ackPacket = PacketHandler::create_ack_packet(expected_seq, sizeof(int));
            sender.send_ack(ackPacket, fd);
            expected_seq++;
            fileWriter.write_chunk(string(pkt.data, pkt.len));
            recvd++;
        }
        if(recvd == total_packets){
            break;
        }
    }
}

bool GBN_receiver::is_corrupt(Packet pkt){
    return !PacketHandler::compare_packet_checksum(pkt);
}

bool GBN_receiver::is_expected(Packet pkt){
    return pkt.seqno == expected_seq;
}
