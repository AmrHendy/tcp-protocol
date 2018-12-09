//
// Created by Amr Hendy on 08/12/2018.
//

#include "SR_Receiver.h"

int cwnd = 10;
map<int, Packet> received;
int start_window_packet;
int end_window_packet;

SR_Receiver::SR_Receiver(int socket_fd, string file_path, int total_packets): writer(file_path), sender(NULL){
    SR_Receiver::socket_fd = socket_fd;
    SR_Receiver::file_path = file_path;
    received.clear();
    start_window_packet = 0;
    end_window_packet = min(cwnd - 1, total_packets - 1);
    SR_Receiver::total_packets = total_packets;
}

void SR_Receiver::recevFile(){
    while(start_window_packet < total_packets){
        struct sockaddr_in socket_address;
        Packet packet = Receiver::receive_packet(socket_fd, socket_address);
        if(PacketHandler::compare_packet_checksum(packet) && packet.seqno >= start_window_packet && packet.seqno <= end_window_packet && received.find(packet.seqno) == received.end()){
            // accept the packet and send ack
            received[packet.seqno] = packet;
            Ack_Packet ack_packet = PacketHandler::create_ack_packet(packet.seqno, sizeof(int));
            sender.send_ack(ack_packet, socket_fd);
            // update the window
            int idx = start_window_packet;
            while(idx < total_packets && received.find(idx) != received.end()) idx++;
            start_window_packet = idx;
            end_window_packet = min(start_window_packet + cwnd - 1, total_packets - 1);
        }
        else{
            // ignore it
        }
    }
    // received all the packets, then sort them and write them to the file
    int current_packet = 0;
    while(current_packet < total_packets){
        Packet packet = received[current_packet];
        writer.write_chunk_data(current_packet, packet.data);
    }
}
