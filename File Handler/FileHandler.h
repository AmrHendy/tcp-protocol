//
// Created by Amr Hendy on 11/28/2018.
//

#ifndef TCP_PROTOCOL_FILEHANDLER_H
#define TCP_PROTOCOL_FILEHANDLER_H

using namespace std;

#include <string>

class FileHandler {
private:
    string file_path;
    int chunk_size;
    int current_chunk_index;

public:
    FileHandler(string file_path, int chunk_size);
    ~FileHandler();

    void set_chunk_size(int chunk_size);
    int get_file_size();
    int get_current_chunk_index();
    string get_current_chunk_data();
    string get_chunk_data(int chunk_index);
    void advance_chunk_pointer();
};


#endif //TCP_PROTOCOL_FILEHANDLER_H
