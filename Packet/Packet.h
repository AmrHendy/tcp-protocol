//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_PACKET_H
#define TCP_PROTOCOL_PACKET_H

#include <cstdint>
#include "../Utils/constants.h"

/* Data-only packets */
struct Packet {
    /* Header */
    uint16_t cksum; /* Optional bonus part */
    uint16_t len = -1;
    uint32_t seqno;
    /* Data */
    char data[CHUNK_SIZE]; /* Not always 500 bytes, can be less */
};

/* Ack-only packets are only 8 bytes */
struct Ack_Packet {
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t ackno;
};


/* Ack from server including the number of packets of the desired file */
struct Ack_Server_Packet {
    uint32_t packets_numbers;
};

#endif //TCP_PROTOCOL_PACKET_H
