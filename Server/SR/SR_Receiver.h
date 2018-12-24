//
// Created by Amr Hendy on 08/12/2018.
//

#ifndef TCP_PROTOCOL_SR_RECEIVER_H
#define TCP_PROTOCOL_SR_RECEIVER_H

using namespace std;

#include <vector>
#include <map>

#include "../File Handler/FileWriter.h"
#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../Utils/constants.h"
#include "../Packet/PacketHandler.h"


class SR_Receiver {

private:
    // socket fd
    int socket_fd;
    string file_path;
    // window
    int cwnd = 10;
    map<int, Packet> received;
    int start_window_packet;
    int end_window_packet;
    int total_packets;
    // helpers
    Sender sender;
    FileWriter writer;

public:
    explicit SR_Receiver(int socket_fd, string file_path, int total_packets);

    void recevFile();

};


#endif //TCP_PROTOCOL_SR_RECEIVER_H
