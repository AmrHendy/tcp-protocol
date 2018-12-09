//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_FILEREADER_H
#define TCP_PROTOCOL_FILEREADER_H

using namespace std;

#include <string>
#include <cmath>
#include <iostream>
#include <stdio.h>

#include "../Packet/Packet.h"
#include "../Packet/PacketHandler.h"

class FileReader {

private:
    FILE *file;
    int chunk_size;
    int current_chunk_index;

public:
    explicit FileReader(const char* file_path, int chunk_size=CHUNK_SIZE);
    explicit FileReader(string file_path, int chunk_size=CHUNK_SIZE);

    int get_file_size();
    bool is_finished();
    int get_current_chunk_index();
    Packet get_current_chunk_data();
    Packet get_chunk_data(int chunk_index);
    void advance_chunk_pointer();
    int get_total_packet_number();
    void close();
};


#endif //TCP_PROTOCOL_FILEREADER_H
