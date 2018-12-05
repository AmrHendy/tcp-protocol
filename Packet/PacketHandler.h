//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_PACKETHANDLER_H
#define TCP_PROTOCOL_PACKETHANDLER_H

#include "Packet.h"
#include <cstring>

class PacketHandler {

public:
    static Packet create_packet(char* data, int seqno, int len);
    static uint16_t calculate_packet_checksum(Packet packet);
};


#endif //TCP_PROTOCOL_PACKETHANDLER_H
