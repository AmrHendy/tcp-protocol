//
// Created by Amr Hendy on 08/12/2018.
//

#include "SR_Sender.h"

SR_Sender::SR_Sender(int socket_fd, string file_name, double loss_prob, int seed_number, vector<int> window_changes): sender(), reader(file_path){
    SR_Sender::socket_fd = socket_fd;
    SR_Sender::file_path = file_name;
    SR_Sender::window_changes = window_changes;
    get_loss_packets(loss_prob, seed_number);
    cwnd = 1;
    threshold = 10;
    additive_increase = 1;
    multiplicative_decrease = 2;
    window.clear();
    acked.clear();
    start_window_packet = 0;
    end_window_packet = 0;
}

void SR_Sender::sendFile(){
    sender_thread = std::thread (&SR_Sender::send_handling, this);
    receiver_thread  = std::thread (&SR_Sender::recev_ack_handling, this);
}

void SR_Sender::send_handling(){
    int total_packets = reader.get_total_packet_number();
    int sended = 0;
    int window_congestion_index = 0;
    while(start_window_packet < total_packets){
        for(int index = start_window_packet; index <= end_window_packet; index++){
            mtx.lock();
            if(window.find(index) == window.end()){
                Packet packet = reader.get_chunk_data(index);
                // loss
                if(loss_packets_indices.count(index)){
                    loss_packets_indices.erase(index);
                    clock_t start_time = clock();
                    window[index] = {packet, start_time};
                }
                else if(window_congestion_index < window_changes.size() && sended == window_changes[window_congestion_index]){
                    // TODO handle congestion control loss
                    sended = 0;
                    window_congestion_index++;
                    cwnd = max((int)floor(1.0 * cwnd / multiplicative_decrease), 1);
                    start_window_packet = start_window_packet;
                    end_window_packet = start_window_packet + cwnd - 1;
                    break;
                }
                else{
                    sender.send_packet(packet, socket_fd);
                    clock_t start_time = clock();
                    window[index] = {packet, start_time};
                    sended++;
                }
            }
            if(acked.find(index) == acked.end()){
                clock_t time_now = clock();
                if((time_now - window[index].second)/ CLOCKS_PER_SEC >= SR_TIMEOUT){
                    // TODO handle timeout
                    window.clear();
                    acked.clear();
                    cwnd = 1;
                    start_window_packet = start_window_packet;
                    end_window_packet = start_window_packet;
                    break;
                }
            }
            mtx.unlock();
        }
    }
}


void SR_Sender::recev_ack_handling(){
    int total_packets = reader.get_total_packet_number();
    while(start_window_packet < total_packets){
        struct sockaddr_in socket_address;
        int status;
        Ack_Packet ack_packet = Receiver::receive_ack_packet(socket_fd, socket_address, status);
        if(status == 1){
            mtx.lock();
            if(PacketHandler::compare_ack_packet_checksum(ack_packet) && window.find(ack_packet.ackno) != window.end()){
                acked[ack_packet.ackno] = ack_packet;
                int idx = start_window_packet;
                while(idx <= end_window_packet && acked.find(idx) != acked.end()){
                    start_window_packet++;
                }
                // TODO what is threshold ,, how it works with cwnd ??
                cwnd = cwnd + additive_increase;
                end_window_packet = min(start_window_packet + cwnd - 1, total_packets);
            }
            else{
                // ignore the ack packet
            }
            mtx.unlock();
        }
        else{
            // not recev for long time
        }
    }
}

void SR_Sender::get_loss_packets(double loss_prob, int seed_number){
    srand(seed_number);
    int total_packets = reader.get_total_packet_number();
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
    SR_Sender::loss_packets_indices = loss_packets_indices;
}
