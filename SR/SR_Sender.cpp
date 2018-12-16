//
// Created by Amr Hendy on 08/12/2018.
//

#include "SR_Sender.h"

SR_Sender::SR_Sender(int socket_fd, string file_name, double loss_prob, int seed_number,
         struct sockaddr_in client_socket): sender(client_socket), reader(file_name){
    SR_Sender::socket_fd = socket_fd;
    SR_Sender::file_path = file_name;
    std::ifstream infile("control.txt");
    int a;
    while(infile >> a){
        window_changes.push_back(a);
    }
    get_loss_packets(loss_prob, seed_number);
    cwnd = 1;
    threshold = 10;
    additive_increase = 1;
    multiplicative_decrease = 2;
    window.clear();
    acked.clear();
    start_window_packet = 0;
    end_window_packet = 0;
    SR_Sender::client_socket = client_socket;
}

void SR_Sender::sendFile(){
    sender_thread = std::thread (&SR_Sender::send_handling, this);
    receiver_thread  = std::thread (&SR_Sender::recev_ack_handling, this);
    sender_thread.join();
    printf("sender thread finished in selective repeat.\n");
    receiver_thread.join();
    printf("receiver thread finished in selective repeat.\n");
}

void SR_Sender::send_handling(){
    //mtx.lock();
    int total_packets = reader.get_total_packet_number();
    int sended = 0;
    int window_congestion_index = 0;
    while(start_window_packet < total_packets){
        for(int index = start_window_packet; index <= end_window_packet; index++){
            mtx.lock();
            if(window.find(index) != window.end()){
                Packet packet = reader.get_chunk_data(index);
                // loss
                if(loss_packets_indices.count(index)){
                    loss_packets_indices.erase(index);
                    clock_t start_time = clock();
                    window[index] = {packet, start_time};
                } else if(window_congestion_index < window_changes.size() && sended == window_changes[window_congestion_index]){
                    window.clear();
                    //acked.clear();
                    sended = 0;
                    window_congestion_index++;
                    cwnd = max((int)floor(1.0 * cwnd / multiplicative_decrease), 1);
                    start_window_packet = start_window_packet;
                    end_window_packet = min(start_window_packet + cwnd - 1, total_packets - 1);
                    mtx.unlock();
                    break;
                } else{
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
                    mtx.unlock();
                    break;
                }
            }
            mtx.unlock();
        }
    }
}


void SR_Sender::recev_ack_handling(){
    //mtx.lock();
    int total_packets = reader.get_total_packet_number();
    while(start_window_packet < total_packets){
        int status;
        Ack_Packet ack_packet = Receiver::receive_ack_packet(socket_fd, client_socket, status);
        if(status == 1){
            mtx.lock();
            if(PacketHandler::compare_ack_packet_checksum(ack_packet) && window.find(ack_packet.ackno) != window.end()){
                cout << "packet " << ack_packet.ackno << " ack." << endl;
                acked[ack_packet.ackno] = ack_packet;
                while(start_window_packet <= end_window_packet && acked.find(start_window_packet) != acked.end()){
                    start_window_packet++;
                }
                if(cwnd < threshold){
                    //exp
                    cout << "window size duplicated." << endl;
                    cwnd *= 2;
                }else if(cwnd < total_packets){
                    cout << "window size increased by " << additive_increase << endl;
                    cwnd += additive_increase;
                }
                end_window_packet = min(start_window_packet + cwnd - 1, total_packets - 1);
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
    return;
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
