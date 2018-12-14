//
// Created by arsanuos on 12/2/18.
//

#ifndef TCP_PROTOCOL_GBN_H
#define TCP_PROTOCOL_GBN_H

#include "../File Handler/FileReader.h"
#include "../File Handler/FileWriter.h"
#include "../Packet/PacketHandler.h"
#include "../Packet/Packet.h"

#include "../Packet/PacketHandler.h"
#include "../Packet/Packet.h"
#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../Utils/constants.h"

#include <bits/stdc++.h>
#include <stdint.h>
#include <ctime>
#include <string>
#include <vector>

#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <set>

using namespace std;

class GBN {

private:
    int base = 0;
    int next_seq_num = 0;
    clock_t timer = 0;
    double threshold = 10;/* threshold of timeout 10 seconds.*/
    //FileHandler file_handler;
    FileReader fileReader;
    int N;
    int sentPackets;
    vector<Packet> sentpkt;
    int client_fd;
    double PLP;
    struct sockaddr_in client_socket;
    Sender sender;
    set<int> loss_packets_indices;
    vector<int> window_changes;
    int i = 0;


    bool is_corrupt(uint16_t cksum);

    clock_t start_timer();

    bool check_timeout();

    void time_out();

    void resend_all();

    void stop_timer();

public:
    GBN(string file_name, int client_fd, int N, double PLP, struct sockaddr_in client_socket);

    void start();

    void gbn_recv(Ack_Packet pkt);

    void data_listener();

    void gbn_recv();

    bool gbn_send(Packet pkt);

    void get_loss_packets(double loss_prob, int seed_number);

    bool congestion_time();


};


#endif //TCP_PROTOCOL_GBN_H
