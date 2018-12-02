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

class GBN {

    private:
        int base = 0;
        int next_seq_num = 0;
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
        void start();
        void gbn_recv(ack_packet pkt);
        void data_listener();
        void gbn_recv();


};


#endif //TCP_PROTOCOL_GBN_H
