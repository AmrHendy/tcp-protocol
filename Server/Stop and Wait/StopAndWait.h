//
// Created by Amr Hendy on 12/7/2018.
//

#ifndef TCP_PROTOCOL_STOPANDWAIT_H
#define TCP_PROTOCOL_STOPANDWAIT_H

using namespace std;

#include <string>
#include <set>
#include <unistd.h>

#include "../File Handler/FileReader.h"
#include "../File Handler/FileWriter.h"
#include "../Sender/Sender.h"
#include "../Receiver/Receiver.h"
#include "../Utils/constants.h"
#include "../Packet/PacketHandler.h"


class StopAndWait {

public:
    explicit StopAndWait(int socket_fd, string file_name);

    void sendFile(double loss_prob, int seed_number, struct sockaddr_in client_address);
    void recevFile(int total_packets);

private:
    int socket_fd;
    string file_path;
    set<int> loss_packets_indices;
    FileReader fileReader;
    //FileWriter fileWriter;

    void get_loss_packets(double loss_prob, int seed_number);
    void sendPacket(int packet_index, sockaddr_in client_address);
    int recevAck(struct sockaddr_in socket_address);

    Packet receivePacket(int packet_index);
    void sendAck(int packet_index);

};


#endif //TCP_PROTOCOL_STOPANDWAIT_H
