//
// Created by lenovo pc on 03/12/2018.
//

#ifndef TCP_PROTOCOL_ACK_PACKET_H
#define TCP_PROTOCOL_ACK_PACKET_H

struct ack_packet {
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t ackno;
};

#endif //TCP_PROTOCOL_ACK_PACKET_H
