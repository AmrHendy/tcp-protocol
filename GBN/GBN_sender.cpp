//
// Created by arsanuos on 12/2/18.
//

#include "GBN_sender.h"


GBN::GBN(FileHandler file_handler, int client_fd) : file_handler(file_handler) {
    this.client_fd = client_fd;
    sentpkt.resize(N);
}


void GBN::start() {
    bool sent = true;
    packet pkt;
    while (1) {
        if (!file_handler.can_read()) {
            break;
        }
        if (sent) {
            pkt.data = file_handler.get_current_chunk_data();
            pkt.len = pkt.data.length() + 2 + 4; /* len = 2 , seqno = 4*/
            pkt.seqno = this.next_seq_num;
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
    this.timer = -1;
}

bool GBN::check_timeout() {
    if (this.timer == -1) {
        return false;
    }
    clock_t now = clock();
    return ((now - this.timer) / (double) CLOCKS_PER_SEC) >= this.threshold;
}


bool GBN::gbn_send(packet pkt) {
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
    ack_packet pkt = recv_ack_pkt(client_fd);
    if (!is_corrupt(pkt.cksum)) {
        base = pkt.ackno + 1;
        if (base == next_seq_num) {
            stop_timer();
        } else {
            start_timer();
        }
    }
}

