//
// Created by Amr Hendy on 12/5/2018.
//

#include "FileWriter.h"

FileWriter::FileWriter(string file_path, int chunk_size) {
    FileWriter::file = fopen(file_path.c_str(), "wa+");
    FileWriter::chunk_size = chunk_size;
    FileWriter::current_chunk_index = 0;
}

FileWriter::FileWriter() {
}


void FileWriter::write_chunk(string data){
    current_chunk_index++;
    write_chunk_data(current_chunk_index - 1, data);
}

void FileWriter::write_chunk_data(int chunk_index, string data) {
    //fseek(FileWriter::file, chunk_index * chunk_size, SEEK_SET);
    cout  << "client wrote "<< data.size()
            << " char" << " as chunk " << chunk_index * chunk_size << endl;
    fwrite(data.c_str(), sizeof(char), data.size(), file);
}

