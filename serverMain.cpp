#include <iostream>
#include "Server/Server.h"
using namespace std;

int main() {
    Server server("server.txt");
    int stopAndWait = 0;
    int selective_repeat = 1;
    int GBN = 2;
    server.start_server(selective_repeat);
    return 0;
}