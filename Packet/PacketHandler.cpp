//
// Created by Amr Hendy on 12/5/2018.
//

#include "PacketHandler.h"

Packet PacketHandler::create_packet(char* data, int seqno, int len){
    Packet packet;
    for(int i = 0 ;i < len; i++){
        packet.data[i] = data[i];
    }
    packet.seqno = seqno;
    packet.len = len;
    packet.cksum = calculate_packet_checksum(packet);
    return packet;
}

uint16_t PacketHandler::calculate_packet_checksum(Packet packet){
    uint32_t sum = 0;
    for(int i = 0; i < packet.len; i++){
        sum += packet.data[i];
    }
    sum += packet.len;
    sum += packet.seqno;
    // Add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    // Return the one's complement of sum
    return ( (uint16_t)(~sum)  );
}

bool PacketHandler::compare_packet_checksum(Packet packet){
    return packet.cksum == calculate_packet_checksum(packet);
}

Ack_Packet PacketHandler::create_ack_packet(uint32_t ackno, uint16_t len){
    Ack_Packet packet;
    packet.len = len;
    packet.ackno = ackno;
    packet.cksum = calculate_ack_packet_checksum(packet);
    return packet;
}

uint16_t PacketHandler::calculate_ack_packet_checksum(Ack_Packet packet){
    uint32_t sum = 0;
    sum += packet.len;
    sum += packet.ackno;
    // Add the carries
    while (sum >> 16)
        sum = (sum & 0xFFFF) + (sum >> 16);
    // Return the one's complement of sum
    return ( (uint16_t)(~sum)  );
}

bool PacketHandler::compare_ack_packet_checksum(Ack_Packet packet){
    return packet.cksum == calculate_ack_packet_checksum(packet);
}