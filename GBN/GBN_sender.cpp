//
// Created by arsanuos on 12/2/18.
//
#include "GBN_sender.h"


GBN::GBN(FileWriter fileWriter, FileReader fileReader, int client_fd, int N, double PLP) : fileReader(fileReader), fileWriter(fileWriter) {
    this->client_fd = client_fd;
    this.N = N;
    this->PLP = PLP;
    sentpkt.resize(N);
}


void GBN::start() {
    bool sent = true;
    Packet pkt;
    while (1) {
        if (fileReader.is_finished()) {
            break;
        }
        if (sent) {
            //TODO:: how to know seq number.
            pkt.data = fileReader.get_current_chunk_data();
            pkt.len = pkt.data.length() + 2 + 4; /* len = 2 , seqno = 4*/
            pkt.seqno = this->next_seq_num;
        }
        //send.
        sent = gbn_send(pkt);
        if (!sent) {
            //check timeout
            time_out();
            //recv ack pkt
            gbn_recv();
        }
    }
}

bool GBN::is_corrupt(uint16_t pkt) {
    //TODO:: implement one of the algorithms here.
    return false;
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
        send_pkt(client_fd, pkt);
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
        send_pkt(client_fd, pkt);
    }
}

void GBN::gbn_recv() {
    Ack_Packet pkt = recv_ack_pkt(client_fd);
    if (!is_corrupt(pkt.cksum)) {
        base = pkt.ackno + 1;
        if (base == next_seq_num) {
            stop_timer();
        } else {
            start_timer();
        }
    }
}

