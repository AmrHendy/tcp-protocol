//
// Created by arsanuos on 12/2/18.
//

#include "helper.h"


Packet recv_pkt(int client_fd) {
    Packet pkt;
    pkt.len = get_len(client_fd);
    pkt.seqno = get_seq_num(client_fd);
    pkt.data = get_data(client_fd, pkt.len);
    return pkt;
}

Ack_Packet recv_ack_pkt(int client_fd) {
    Ack_Packet pkt;
    pkt.len = get_len(client_fd);
    pkt.ackno = get_seq_num(client_fd);
    return pkt;
}


uint16_t get_len(int client_fd) {
    uint16_t size;
    int val_read = 0;
    while (val_read < sizeof(size)) {
        int i = recv(client_fd, &size, sizeof(size), MSG_PEEK);
        if (i == -1) {
            return -1;
        }
        val_read += i;
    }
    //gurantee to read sizeof(size) here.
    int i = recv(client_fd, &size, sizeof(size), 0);
    if (i == -1) {
        return -1;
    }
    return size;
}

uint32_t get_seq_num(int client_fd) {
    uint32_t seq_no;
    int val_read = 0;
    while (val_read < sizeof(seq_no)) {
        int i = recv(client_fd, &seq_no, sizeof(seq_no), MSG_PEEK);
        if (i == -1) {
            return -1;
        }
        val_read += i;
    }
    //gurantee to read sizeof(size) here.
    int i = recv(client_fd, &seq_no, sizeof(seq_no), 0);
    if (i == -1) {
        return -1;
    }
    return seq_no;
}

string get_data(int client_fd, uint16_t size) {
    char *buffer = (char *) malloc(size);
    int val_read = 0;
    while (val_read < size) {
        int i = recv(client_fd, buffer + val_read, sizeof(size), 0);
        if (i == -1) {
            return "";
        }
        val_read += i;
    }
    if (!buffer) {
        free(buffer);
    }
    string s(buffer);
    return s;
}

bool send_pkt(int fd, Packet pkt) {
    uint16_t len = pkt.len;
    //send length.
    //send seq number.
    //send data.
    return send_all(fd, (void *) pkt.len, 2) && send_all(fd, (void *) pkt.seqno, 4) &&
           send_all(fd, (void *) pkt.data.c_str(), pkt.len - 6);
}

bool send_all(int fd, void *data, uint16_t len) {
    char *ptr = (char *) data.data.c_str();
    while (len > 0) {
        int i = send(fd, ptr + i, len, 0);
        if (i == -1) {
            return false;
        }
        ptr += i;
        len -= i;
    }
    return true;
}


bool send_ack(int fd, Ack_Packet pkt) {
    return send_all(fd, (void *) pkt.len, 2) && send_all(fd, (void *) pkt.ackno, 4);
}