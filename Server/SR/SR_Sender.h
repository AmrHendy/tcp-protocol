//
// Created by Amr Hendy on 08/12/2018.
//

#ifndef TCP_PROTOCOL_SR_SENDER_H
#define TCP_PROTOCOL_SR_SENDER_H


#include <vector>
#include <thread>
#include <mutex>
#include <map>
#include <set>
#include <fstream>

#include "../File Handler/FileReader.h"
#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../Utils/constants.h"
#include "../Packet/PacketHandler.h"

using namespace std;

class SR_Sender {
private:
    // socket fd
    int socket_fd;
    string file_path;
    set<int> loss_packets_indices;
    vector<int> window_changes;
    // window
    int cwnd = 1;
    map<int, pair<Packet, clock_t>> window;
    map<int, Ack_Packet> acked;
    int start_window_packet;
    int end_window_packet;
    // window handling
    int threshold = 10;
    int additive_increase = 1;
    int multiplicative_decrease = 2;
    // helpers
    Sender sender;
    FileReader reader;
    // threads and mutex
    thread sender_thread;
    thread receiver_thread;
    mutex mtx;
    struct sockaddr_in client_socket;

public:
    explicit SR_Sender(int socket_fd, string file_name,
            double loss_prob, int seed_number, struct sockaddr_in client_socket);

    void sendFile();

private:
    void get_loss_packets(double loss_prob, int seed_number);
    void send_handling();
    void recev_ack_handling();
};


#endif //TCP_PROTOCOL_SR_SENDER_H
