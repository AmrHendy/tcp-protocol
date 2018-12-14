//
// Created by arsanuos on 12/2/18.
//
#include "GBN_sender.h"


GBN::GBN(string file_name, int client_fd, int N, double PLP, struct sockaddr_in client_socket)
        : fileReader(file_name.c_str()), sender(client_socket) {
    this->client_fd = client_fd;
    this->N = N;
    this->PLP = PLP;
    this->client_socket = client_socket;
    sentpkt.resize(N);
    this->threshold = 5;
    this->next_seq_num = 0;
}


void GBN::start() {
    int total_packets = fileReader.get_total_packet_number();
    bool sent = true;
    Packet pkt;
    while (1) {
        if (fileReader.is_finished()) {
            break;
        }
        if (sent) {
            pkt = fileReader.get_current_chunk_data();
            if(pkt.len != -1){
                sender.send_packet(pkt, client_fd);
            }
        }
        //send.
        gbn_send(pkt);
        //check timeout
        time_out();
        //recv ack pkt
        gbn_recv();
    }
}


clock_t GBN::start_timer() {
    timer = clock();
}

void GBN::stop_timer() {
    timer = -1;
}

bool GBN::check_timeout() {
    if (timer == -1) {
        return false;
    }
    clock_t now = clock();
    return ((now - timer) / (double) CLOCKS_PER_SEC) >= this->threshold;
}


bool GBN::gbn_send(Packet pkt) {
    if (next_seq_num < base + N) {
        sentpkt[next_seq_num] = pkt;
        sender.send_packet(pkt, client_fd);
        if (base == next_seq_num) {
            start_timer();
        }
        next_seq_num++;
        return true;
    }
    return false;
}

void GBN::time_out() {
    if (check_timeout()) {
        N = 1;
        resend_all();
    }
}


void GBN::resend_all() {
    start_timer();
    for (auto pkt : sentpkt) {
        sender.send_packet(pkt, client_fd);
    }
}

void GBN::gbn_recv() {
    int status;
    Ack_Packet pkt = Receiver::receive_ack_packet(client_fd, client_socket, status);
    if (!status || !PacketHandler::compare_ack_packet_checksum(pkt)) {
        base = pkt.ackno + 1;
        cout << pkt.ackno << endl;
        if (base == next_seq_num) {
            stop_timer();
        } else {
            start_timer();
        }
    }
}

