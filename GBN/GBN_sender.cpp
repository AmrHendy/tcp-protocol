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
    sentpkt.resize(fileReader.get_file_size() + 1);
    this->threshold = 5;
    this->next_seq_num = 0;
    std::ifstream infile("control.txt");
    int a;
    while(infile >> a){
        window_changes.push_back(a);
    }

    get_loss_packets(PLP, 0);
}

bool GBN::congestion_time(){
    if(next_seq_num == window_changes[i]){
        cout << "Congestion time" << endl;
        i++;
        window_changes[i] = window_changes[i - 1];
        return true;
    }
    return  false;
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
        if(congestion_time()){
            N = max((int)floor(1.0 * N / 2), 1);
        }
        //send.
        sent = gbn_send(pkt);
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
    if (status && PacketHandler::compare_ack_packet_checksum(pkt)) {
        base = pkt.ackno + 1;
        if(N < 10){
            N *= 2;
        }else{
            N++;
        }
        if (base == next_seq_num) {
            stop_timer();
        } else {
            start_timer();
        }
    }
}

void GBN::get_loss_packets(double loss_prob, int seed_number){
    srand(seed_number);
    int total_packets = fileReader.get_total_packet_number();
    int total_loss_packets = ceil(loss_prob * total_packets);
    set<int> loss_packets_indices;
    for(int i = 0; i < total_loss_packets; i++){
        int index = rand() % total_packets;
        if(loss_packets_indices.count(index) == 0){
            loss_packets_indices.insert(index);
        }
        else{
            // as that index is already exist
            i--;
        }
    }
    GBN::loss_packets_indices = loss_packets_indices;
}

