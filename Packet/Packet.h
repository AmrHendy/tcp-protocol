//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_PACKET_H
#define TCP_PROTOCOL_PACKET_H

#include <cstdint >

#define CHUNK_SIZE 500

/* Data-only packets */
struct packet {
    /* Header */
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t seqno;
    /* Data */
    char data[CHUNK_SIZE]; /* Not always 500 bytes, can be less */
};

/* Ack-only packets are only 8 bytes */
struct ack_packet {
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t ackno;
};


/* Ack from server including the number of packets of the desired file */
struct ack_server_packet {
    uint32_t packets_numbers;
};

#endif //TCP_PROTOCOL_PACKET_H
