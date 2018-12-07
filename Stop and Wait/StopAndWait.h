//
// Created by Amr Hendy on 12/7/2018.
//

#ifndef TCP_PROTOCOL_STOPANDWAIT_H
#define TCP_PROTOCOL_STOPANDWAIT_H

using namespace std;

#include <string>
#include <set>

#include "../File Handler/FileReader.h"
#include "../File Handler/FileWriter.h"
#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../Utils/constants.h"
#include "../Packet/PacketHandler.h"


class StopAndWait {

public:
    explicit StopAndWait(int socket_fd, string file_name);
    ~StopAndWait();

    void sendFile(double loss_prob, int seed_number);
    void recevFile(int total_packets);

private:
    int socket_fd;
    string file_path;
    set<int> loss_packets_indices;
    FileReader fileReader;
    FileWriter fileWriter;

    void get_loss_packets(double loss_prob, int seed_number);
    void sendPacket(int packet_index);
    int recevAck();

    Packet receivePacket(int packet_index);
    void sendAck(int packet_index);

};


#endif //TCP_PROTOCOL_STOPANDWAIT_H
