//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_PACKETHANDLER_H
#define TCP_PROTOCOL_PACKETHANDLER_H

#include "Packet.h"
#include <cstring>

class PacketHandler {

public:
    /* for data packet */
    static Packet create_packet(char* data, int seqno, int len);
    static uint16_t calculate_packet_checksum(Packet packet);
    static bool compare_packet_checksum(Packet packet);

    /* for ack packet */
    static Ack_Packet create_ack_packet(uint32_t ackno, uint16_t len);
    static uint16_t calculate_ack_packet_checksum(Ack_Packet packet);
    static bool compare_ack_packet_checksum(Ack_Packet packet);
};


#endif //TCP_PROTOCOL_PACKETHANDLER_H
