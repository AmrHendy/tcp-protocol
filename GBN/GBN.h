//
// Created by arsanuos on 12/2/18.
//

#ifndef TCP_PROTOCOL_GBN_H
#define TCP_PROTOCOL_GBN_H

#include "../File Handler/FileHandler.h"
#include "helper.h"

#include <bits/stdc++.h>
#include <stdint.h>
#include <ctime>
#include <string>
#include <vector>

#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

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

class GBN {

    private:
        int base = 1;
        int next_seq_num = 1;
        clock_t timer = 0;
        double threshold = 10;/* threshold of timeout 10 seconds.*/
        FileHandler file_handler;
        int N;
        int sentPackets;
        vector<packet> sentpkt;
        int client_fd;

        bool is_corrupt(uint16_t cksum);
        clock_t start_timer();
        bool check_timeout();
        void time_out();
        void resend_all();
        void stop_timer();

    public:
        GBN(FileHandler file_handler, int client_fd);
        bool gbn_send(packet pkt);
        void gbn_recv(ack_packet pkt);
        void data_listener();


};


#endif //TCP_PROTOCOL_GBN_H
