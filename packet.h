//
// Created by lenovo pc on 03/12/2018.
//

#ifndef TCP_PROTOCOL_PACKET_H
#define TCP_PROTOCOL_PACKET_H

struct packet {
    /* Header */
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t seqno;
    /* Data */
    string data; /* Not always 500 bytes, can be less */
};

#endif //TCP_PROTOCOL_PACKET_H
