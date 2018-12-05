//
// Created by Amr Hendy on 12/5/2018.
//

#include "PacketHandler.h"

Packet PacketHandler::create_packet(char* data, int seqno, int len){
    Packet packet;
    strcpy(packet.data, data);
    packet.seqno = seqno;
    packet.len = len;
    packet.cksum = calculate_packet_checksum(packet)
    return packet;
}

uint16_t PacketHandler::calculate_packet_checksum(Packet packet){
    uint32_t sum = 0;
    for(int i = 0; i < packet.len; i++){
        sum += packet.data[i];
    }
    sum += htons(packet.len);
    // Add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    // Return the one's complement of sum
    return ( (uint16_t)(~sum)  );
}
