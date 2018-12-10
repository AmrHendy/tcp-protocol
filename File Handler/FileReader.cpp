//
// Created by Amr Hendy on 12/5/2018.
//

#include "FileReader.h"

FileReader::FileReader(string file_path, int chunk_size) {
    FileReader::file = fopen(file_path.c_str(), "rb");
    file_path = file_path.c_str();
    if (!file){
        perror("No Existing File at server");
    }
    FileReader::chunk_size = chunk_size;
    FileReader::current_chunk_index = 0;
}

FileReader::FileReader(const char* file_path, int chunk_size) {
    FileReader::file = fopen(file_path, "rb");
    file_path = file_path;
    if (!file){
        perror("No Existing File at server");
    }
    FileReader::chunk_size = chunk_size;
    FileReader::current_chunk_index = 0;
}

int FileReader::get_file_size() {
    fseek(file, 0, SEEK_END);
    int x = ftell(file);
    rewind(file);
    return x;
}

int FileReader::get_current_chunk_index() {
    return current_chunk_index;
}

Packet FileReader::get_current_chunk_data() {
    if(is_finished()){
        perror("No remaining bytes to be read");
    }
    current_chunk_index++;
    return get_chunk_data(current_chunk_index - 1);
}

void FileReader::advance_chunk_pointer() {
    current_chunk_index++;
}

Packet FileReader::get_chunk_data(int chunk_index) {
    if(chunk_index * chunk_size >= get_file_size()){
        perror("No remaining bytes to be read");
    }
    char * buffer = (char*) malloc(chunk_size);
    int bytes_readed;
    fseek(FileReader::file, chunk_index * chunk_size, SEEK_SET);
    bytes_readed = fread (buffer, sizeof(char), chunk_size, file);
    //TODO:: check this.
    if(bytes_readed != chunk_size && !is_finished()){
        //perror("Reading File Error");
    }
    Packet packet = PacketHandler::create_packet(buffer, chunk_index, bytes_readed);
    return packet;
}

bool FileReader::is_finished(){
    return ftell(file) == SEEK_END;
}

int FileReader::get_total_packet_number(){
    cout << "file size is " << get_file_size() << endl;
    cout << "transfering " << ceil(1.0 * get_file_size() / FileReader::chunk_size) << " packet" <<endl;
    return ceil(1.0 * get_file_size() / FileReader::chunk_size);
}

void FileReader::close(){
    fclose(file);
}