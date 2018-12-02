//
// Created by arsanuos on 12/2/18.
//

#ifndef TCP_PROTOCOL_HELPER_H
#define TCP_PROTOCOL_HELPER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <stdint.h>
#include <string>

using namespace std;

struct packet {
    /* Header */
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t seqno;
    /* Data */
    string data; /* Not always 500 bytes, can be less */
};

struct ack_packet {
    uint16_t cksum; /* Optional bonus part */
    uint16_t len;
    uint32_t ackno;
};

packet recv_pkt(int client_fd);
ack_packet recv_ack_pkt(int client_fd);
string get_data(int client_fd, uint16_t size);
uint16_t get_len(int client_fd);
string get_data(int client_fd, uint16_t size);
uint32_t get_seq_num(int client_fd);
bool send_pkt(int fd, packet pkt);
bool send_all(int fd, void* data, uint16_t len);
bool send_ack(int fd, ack_packet pkt);


#endif //TCP_PROTOCOL_HELPER_H
