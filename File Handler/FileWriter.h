//
// Created by Amr Hendy on 12/5/2018.
//

#ifndef TCP_PROTOCOL_FILEWRITER_H
#define TCP_PROTOCOL_FILEWRITER_H

using namespace std;

#include <string>
#include "../Packet/Packet.h"
#include "../Packet/PacketHandler.h"

class FileWriter {

private:
    FILE *file;
    int chunk_size;
    int current_chunk_index;

public:
    FileWriter(string file_path, int chunk_size=CHUNK_SIZE);
    ~FileWriter();

    void write_chunk(string data);
    void write_chunk_data(int chunk_index, string data);
};


#endif //TCP_PROTOCOL_FILEWRITER_H
